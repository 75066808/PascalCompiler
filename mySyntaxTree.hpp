#ifndef SYNTAX_TREE_H
#define SYNTAX_TREE_H
#include <stdio.h>
#include <string>

#define MAX 4

using namespace std;

extern int yylineno;

typedef enum { 
	ROUTINE,
	CONSTANT,	
	TYPES, 
	VARI, 
	SUB,
	STMT, 
	EXPR
} Nodes;

typedef enum {
	INTEGE,
	REA,
	BOOLEA,
	CHARA,
	STR,
	ARRA,
	RECOR,
	ENUME,
	DECL,
	SELFDEFINE
} Types;

typedef enum {
	FUNC,
	PROC,
	PARAM_VAR,
	PARAM_VAL
} Rout;

typedef enum {
	ASSIGN_STMT,
	PROC_STMT, 
	IF_STMT, 
	REPEAT_STMT, 
	WHILE_STMT, 
	FOR_STMT, 
	CASE_STMT, 
	GOTO_STMT,
	CASE_EXP_STMT
} Stmt;

typedef enum { 
	FN_EXPR, 
    CON_EXPR, 
    OP_EXPR, 
    ID_EXPR
} Expr;

typedef enum { 
    BASIC_ID, 
    ARRAY_ID, 
    RECORD_ID 
} Iden;

typedef enum {
	PLUS_OP,	
	MINUS_OP,	
	OR_OP,	
	MUL_OP,	
	DIV_OP,	
	MOD_OP,	
	AND_OP,	
	GE_OP,	
	GT_OP,	
	LE_OP,	
	LT_OP,	
	EQ_OP,	
	UEQ_OP,	
	NOT_OP,	
	NEG_OP	
} Oper;

typedef struct {
	int   intNum;
	float realNum;
	char  strVal[256];
} Attr;

typedef struct Node{
	Nodes   nodes;
	char    name[256];

	union {
		Rout  routine;
		Types type;
		Stmt  stmt;
		Expr  expr;
	} pattern;

	union {
		Iden  iden;
		Oper  oper;
	} subexpr;

	Attr    attr;
	int     label;
    int     lineNo;
	int     system;

	Node   *dtype;
    Node   *sibling;
	Node   *children[MAX];

    string  resultName;
    Node   *resultType;
    bool    resultIndirect;
    bool    resultConstant;

} Node;
extern Node *root;

Node *newNode(Nodes kind);

Node *newRoutine(Node* head, Node* body);
Node *newSubHead(Rout type, char *name, Node *param, Node *re);
Node *newParam(Node *list, Node *type, Rout k);

Node *newConst(char* name, Node* value);
Node *newVar(Node* namelist, Node* decl);

Node *newType(Types type, Node *child1, Node *child2);
Node *newSelfDefineType(char *name);
Node *newTypeDef(char *TypeName, Node *type);

Node *newConstExp(Types type);
Node *newOpExp(Oper op);
Node *newIdenExp(Iden type, char *name, Node *child);
Node *newFuncExp(char *name, Node *args);

Node *newStmt(Stmt stmt);

void strSet(char *dst, char *src);
void lineTrans(Node *p, Node *q);
void lineAssign(Node *p, int q);
Node *makeLabel(Node *n, int label);
Node *addSibling(Node *p, Node *q);
void addChild(Node *parent, Node *child);


void printType(FILE *treeout, Node *p);
void printOperation(FILE *treeout, Node *p);
void printExpression(FILE *treeout, Node *p);
void printStatement(FILE *treeout, Node *p);
void printSubroutine(FILE *treeout, Node *p);
void printTree(FILE *treeout, Node *p, int level);
#endif
