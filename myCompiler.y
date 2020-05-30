%{
	#include <stdio.h>
	#include <string.h>
	#include "mySyntaxTree.hpp"
	int yylex(void);
	void yyerror(char *);
	extern int yylineno;
	Node *root;
%}
%union{
	int intNum;
	float floatNum;
	char strValue[256];
	Node *node;
}
%type <node> expression expr term factor const_value args_list expression_list
%type <node> repeat_stmt stmt_list stmt non_label_stmt assign_stmt proc_stmt if_stmt
%type <node> case_expr_list while_stmt for_stmt goto_stmt compound_stmt case_stmt
%type <node> label_part case_expr else_clause routine routine_head routine_body
%type <node> type_decl_list const_part type_part var_part routine_part const_expr_list
%type <node> array_type_decl type_definition type_decl simple_type_decl sys_type name_list
%type <node> sub_routine record_type_decl field_decl_list field_decl var_decl_list var_decl
%type <node> function_decl function_head procedure_decl procedure_head program_head
%type <node> val_para_list para_decl_list para_type_list var_para_list parameters
%type <intNum> direction 
%token GE GT LE LT EQUAL UNEQUAL PLUS MINUS OR MUL DIV MOD AND NOT ASSIGN
%token ID LP RP DOT COMMA LB RB SEMI COLON SYS_TYPE
%token <intNum> INTEGER CHAR BOOLEAN
%token <floatNum> REAL
%token <strValue> STRING NAME SYS_FUNCT SYS_PROC
%token TYPE_INTEGER TYPE_REAL TYPE_CHAR TYPE_BOOLEAN TYPE_STRING READ 
%token <intNum> IF THEN ELSE REPEAT UNTIL WHILE DO FOR TO DOWNTO
%token <intNum> CASE OF GOTO BEGINNING END
%token PROGRAM CONST TYPE ARRAY RECORD VAR FUNCTION PROCEDURE
%%

program:
	program_head routine DOT	{ 
		root = newSubHead(PROC, $1->name, NULL, NULL); 
		addChild(root, $2); 
        lineTrans(root, $1);
	}
	;
program_head:
	PROGRAM NAME SEMI	{ $$ = newIdenExp(BASIC_ID, $2, NULL); }
	;
routine:
	routine_head routine_body	{ 
        $$ = newRoutine($1, $2); 
        if($1 != NULL){
            lineTrans($$, $1);
        }
        else if($2 != NULL){
            lineTrans($$, $2);
        }
    }
	;
routine_head:
	label_part const_part type_part	var_part routine_part	{ 
        Node *tmp;
        tmp = addSibling($4, $5);
        tmp = addSibling($3, tmp);
        tmp =  addSibling($2, tmp);
        $$ = addSibling($1, tmp); 
    }
	;
sub_routine:
	routine_head routine_body	{ 
        $$ = newRoutine($1, $2); 
        if($1 != NULL){
            lineTrans($$, $1);
        }
        else if($2 != NULL){
            lineTrans($$, $2);
        }
    }
	;
label_part:		{ $$ = NULL; }
	;
const_part:
	CONST const_expr_list	{ $$ = $2; }
	|	{ $$ = NULL; }
	;
const_expr_list:
	const_expr_list NAME EQUAL const_value SEMI	{ 
        Node *tmp = newConst($2, $4);
        $$ = addSibling($1, tmp); 
    }
	| NAME EQUAL const_value SEMI	{ $$ = newConst($1, $3); }
	;
type_part:
	TYPE type_decl_list	{ $$ = $2; }	
	|	{ $$ = NULL; }
	;
type_decl_list:
	type_decl_list type_definition	{ $$ = addSibling($1, $2); }
	| type_definition	{ $$ = $1; }
	;
type_definition:
	NAME EQUAL type_decl SEMI	{ 
		$$ = newTypeDef($1, $3); 
	}
	;
type_decl:
	simple_type_decl	{ $$ = $1; }
	| array_type_decl	{ $$ = $1; }
	| record_type_decl	{ $$ = $1; }
	;
simple_type_decl:
	sys_type	{ $$ = $1; }
	| NAME		{ $$ = newSelfDefineType($1); }		
	| LP name_list RP	{ $$ = newType(ENUME, $2, NULL); }
	| const_value DOT DOT const_value	{ $$ = newType(ENUME, $1, $4); }
	| MINUS const_value DOT DOT const_value		{ 
		Node *p;
		p = newOpExp(NEG_OP); 
        addChild(p, $2);
		$$ = newType(ENUME, p, $5); 
	}
	| MINUS const_value DOT DOT MINUS const_value	{ 
		Node *p, *q;
		p = newOpExp(NEG_OP); 
        addChild(p, $2);
		q = newOpExp(NEG_OP); 
        addChild(q, $6);
		$$ = newType(ENUME, p, q); 
	}
	| NAME DOT DOT NAME	{ 
        Node *p, *q;
        p = newIdenExp(BASIC_ID, $1, NULL);
        q = newIdenExp(BASIC_ID, $4, NULL);
        $$ = newType(ENUME, p, q); 
    }
	;
sys_type:
	TYPE_INTEGER	{ $$ = newType(INTEGE, NULL, NULL); }
	| TYPE_REAL	{ $$ = newType(REA, NULL, NULL); }
	| TYPE_BOOLEAN	{ $$ = newType(BOOLEA, NULL, NULL); }
	| TYPE_CHAR	{ $$ = newType(CHARA, NULL, NULL); }
	| TYPE_STRING	{ $$ = newType(STR, NULL, NULL); }
	;
array_type_decl:
	ARRAY LB simple_type_decl RB OF type_decl	{ $$ = newType(ARRA, $3, $6); }
	;
record_type_decl:
	RECORD field_decl_list END		{ 
        $$ = newType(RECOR, $2, NULL); 
    }
	;
field_decl_list:
	field_decl_list field_decl		{ $$ = addSibling($1, $2); }
	| field_decl		{ $$ = $1; }
	;
field_decl:
	name_list COLON type_decl SEMI	{ $$ = newVar($1, $3); }
	;
name_list:
	name_list COMMA NAME	{ 
        Node *p = newIdenExp(BASIC_ID, $3, NULL);
        $$ = addSibling($1, p); 
    }
	| NAME		{ $$ = newIdenExp(BASIC_ID, $1, NULL); }
	;
var_part:
	VAR var_decl_list	{ $$ = $2; }
	|	{ $$ = NULL; }
	;
var_decl_list:
	var_decl_list var_decl	{ $$ = addSibling($1, $2); }	
	| var_decl		{ $$ = $1; }
	;
var_decl:
	name_list COLON type_decl SEMI		{ $$ = newVar($1, $3); }
	;
routine_part: 
	routine_part function_decl	{ $$ = addSibling($1, $2); }
	| routine_part procedure_decl	{ $$ = addSibling($1, $2); }
	| function_decl		{ $$ = $1; }
	| procedure_decl	{ $$ = $1; }
	| 	{ $$ = NULL; }
	;
function_decl:
	function_head SEMI sub_routine SEMI	{ 
        addChild($1, $3);
        $$ = $1;
    }
	;
function_head:
	FUNCTION NAME parameters COLON simple_type_decl		{ $$ = newSubHead(FUNC, $2, $3, $5); }
	;
procedure_decl:
	procedure_head SEMI sub_routine SEMI	{ 
        addChild($1, $3);
        $$ = $1;
    }
	;
procedure_head:
	PROCEDURE NAME parameters	{ $$ = newSubHead(PROC, $2, $3, NULL); }
	;
parameters:
	LP para_decl_list RP	{ $$ = $2; }
	|	{ $$ = NULL; }
	;
para_decl_list:
	para_decl_list SEMI para_type_list	{ $$ = addSibling($1, $3); }
	| para_type_list	{ $$ = $1; }
	;
para_type_list:
	var_para_list COLON simple_type_decl	{ $$ = newParam($1, $3, PARAM_VAR); }
	| val_para_list COLON simple_type_decl	{ $$ = newParam($1, $3, PARAM_VAL); }
	;
var_para_list:
	VAR name_list	{ $$ = $2; }
	;
val_para_list:
	name_list	{ $$ = $1; }
	;
routine_body:
	compound_stmt	{ $$ = $1; }
	;
stmt_list:
	stmt_list stmt SEMI		{ $$ = addSibling($1, $2); }
	|		{ $$ = NULL; }
	;
stmt:
	INTEGER COLON non_label_stmt	{ $$ = makeLabel($3, $1); }
	| non_label_stmt	{ $$ = $1; }
	;
non_label_stmt:
	assign_stmt		{ $$ = $1; }
	| proc_stmt		{ $$ = $1; }
	| if_stmt		{ $$ = $1; }
	| repeat_stmt		{ $$ = $1; }
	| while_stmt		{ $$ = $1; }
	| for_stmt		{ $$ = $1; }
	| case_stmt		{ $$ = $1; }
	| goto_stmt		{ $$ = $1; }
	| compound_stmt		{ $$ = $1; }
	;
compound_stmt:
	BEGINNING stmt_list END		{ $$ = $2; }
	;
assign_stmt:
	NAME ASSIGN expression 		{ 
		$$ = newStmt(ASSIGN_STMT); 
		addChild($$, newIdenExp(BASIC_ID, $1, NULL));
		addChild($$, $3);
	}
	| NAME LB expression RB ASSIGN expression	{
		$$ = newStmt(ASSIGN_STMT);
		addChild($$, newIdenExp(ARRAY_ID, $1, $3));
		addChild($$, $6);
	}
	| NAME DOT NAME ASSIGN expression 	{
		$$ = newStmt(ASSIGN_STMT);
        Node *p = newIdenExp(BASIC_ID, $3, NULL);
        addChild($$, newIdenExp(RECORD_ID, $1, p));
		addChild($$, $5);
	}
	;
proc_stmt:
	NAME 	{ 
		$$ = newStmt(PROC_STMT);
		strcpy($$->name, $1);
	}
	| NAME LP args_list RP	{
		$$ = newStmt(PROC_STMT);
		strcpy($$->name, $1);
        addChild($$, $3);
	}
	| SYS_PROC	{
		$$ = newStmt(PROC_STMT);
		strcpy($$->name, $1);
		$$->system = 1;
	}
	| SYS_PROC LP expression_list RP	{
		$$ = newStmt(PROC_STMT);
		strcpy($$->name, $1);
		$$->system = 1;
        addChild($$, $3);
	}		
	| READ LP factor RP {
		$$ = newStmt(PROC_STMT);
		strcpy($$->name, "read");
		$$->system = 1;
        addChild($$, $3);
	}
	;
if_stmt:
	IF expression THEN stmt else_clause		{ 
		$$ = newStmt(IF_STMT);
		addChild($$, $2);
		addChild($$, $4);
		addChild($$, $5);
        lineAssign($$, $1);
	}
	;
else_clause:
	ELSE stmt	{ $$ = $2; }
	|		{ $$ = NULL; }
	;
repeat_stmt:
	REPEAT stmt_list UNTIL expression	{ 
		$$ = newStmt(REPEAT_STMT);
		addChild($$, $2);
		addChild($$, $4);
        lineAssign($$, $1);
	}
	;
while_stmt:
	WHILE expression DO stmt	{
		$$ = newStmt(WHILE_STMT);
		addChild($$, $2);
		addChild($$, $4);
        lineAssign($$, $1);
	}
	;
for_stmt:
	FOR NAME ASSIGN expression direction expression DO stmt		{
		$$ = newStmt(FOR_STMT);
		strcpy($$->name, $2);
		addChild($$, $4);
		addChild($$, $6);
		addChild($$, $8);
		$$->attr.intNum = $5;
        lineAssign($$, $1);
	}
	;
direction:
	TO		{ $$ = 1; }
	| DOWNTO	{ $$ = 0; }
	;
case_stmt:
	CASE expression OF case_expr_list END	{
		$$ = newStmt(CASE_STMT);
		addChild($$, $2);
		addChild($$, $4);
        lineAssign($$, $1);
	}
	;
case_expr_list:
	case_expr_list case_expr	{ $$ = addSibling($1, $2); }
	| case_expr		{ $$ = $1; }
	;
case_expr:
	const_value COLON stmt SEMI	{ 
		$$ = newStmt(CASE_EXP_STMT);
		addChild($$, $1);
		addChild($$, $3);
	}
	| NAME COLON stmt SEMI		{
		$$ = newStmt(CASE_EXP_STMT);
		Node *p = newIdenExp(BASIC_ID, $1, NULL);
        addChild($$, p);
		addChild($$, $3);
	}
	;
goto_stmt:
	GOTO INTEGER		{
		$$ = newStmt(GOTO_STMT);
		$$->attr.intNum = $2;
	}
	;
expression_list:
	expression_list COMMA expression 	{ $$ = addSibling($1, $3); }
	| expression	{ $$ = $1; }
	;
expression:
	expression GE expr		{
		$$ = newOpExp(GE_OP);
		addChild($$, $1);
		addChild($$, $3);
	}	
	| expression GT expr 		{
		$$ = newOpExp(GT_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| expression LE expr 		{
		$$ = newOpExp(LE_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| expression LT expr 		{
		$$ = newOpExp(LT_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| expression EQUAL expr		{
		$$ = newOpExp(EQ_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| expression UNEQUAL expr	{
		$$ = newOpExp(UEQ_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| expr		{ $$ = $1; }
	;
expr:
	expr PLUS term		{
		$$ = newOpExp(PLUS_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| expr MINUS term	{
		$$ = newOpExp(MINUS_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| expr OR term		{
		$$ = newOpExp(OR_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| term		{ $$ = $1; }
	;
term:
	term MUL factor		{ 
		$$ = newOpExp(MUL_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| term DIV factor	{ 
		$$ = newOpExp(DIV_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| term MOD factor	{ 
		$$ = newOpExp(MOD_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| term AND factor	{ 
		$$ = newOpExp(AND_OP);
		addChild($$, $1);
		addChild($$, $3);
	}
	| factor	{ $$ = $1; }
	;
factor:
	NAME		{ $$ = newIdenExp(BASIC_ID, $1, NULL); }
	| NAME LP args_list RP		{ $$ = newFuncExp($1, $3); }
	| SYS_FUNCT	{ $$ = NULL; }
	| SYS_FUNCT LP args_list RP	{
		$$ = newFuncExp($1, $3);
		$$->system = 1;
	}
	| const_value	{ $$ = $1; }
	| NOT factor	{
		$$ = newOpExp(NOT_OP);
		addChild($$, $2);
	}
	| MINUS factor	{
		$$ = newOpExp(NEG_OP);
		addChild($$, $2);
	}
	| LP expression RP { $$ = $2; }
	| NAME LB expression RB		{ $$ = newIdenExp(ARRAY_ID, $1, $3); }
	| NAME DOT NAME	{ 
        Node *p = newIdenExp(BASIC_ID, $3, NULL);
        $$ = newIdenExp(RECORD_ID, $1, p); 
    }
	;
args_list:
	args_list COMMA expression	{ $$ = addSibling($1, $3); }
	| expression 	{ $$ = $1; }
	;
const_value:
	INTEGER		{ 
		$$ = newConstExp(INTEGE);
		$$->attr.intNum = $1;
	}
	| REAL		{
		$$ = newConstExp(REA);
		$$->attr.realNum = $1;
	}
	| CHAR		{
		$$ = newConstExp(CHARA);
		$$->attr.intNum = $1;
	}
	| STRING	{
		$$ = newConstExp(STR);
		strSet($$->attr.strVal, $1);
	}
	| BOOLEAN	{
		$$ = newConstExp(BOOLEA);
		$$->attr.intNum = $1;
	}
	;
%%

void yyerror(char *s){
	fprintf(stderr, "%s\n", s);
	printf("%d\n", yylineno);
}
