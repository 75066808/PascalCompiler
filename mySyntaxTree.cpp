#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mySyntaxTree.hpp"

Node *newNode(Nodes kind){
	Node *p = (Node *)malloc(sizeof(Node));
	p->nodes = kind;
	p->dtype = p->children[0] = p->children[1] = p->children[2] = p->children[3] = p->sibling = NULL;
	p->label = p->system = 0;
	p->lineNo = yylineno;
	return p;
}

Node *newRoutine(Node* head, Node* body){
	Node *p = newNode(ROUTINE);
	addChild(p, head);
	addChild(p, body);
	return p;
}

Node *newSubHead(Rout type, char *name, Node *param, Node *re){
	Node *p = newNode(SUB);
	p->dtype = re;
	p->pattern.routine = type;
	strcpy(p->name, name);
	addChild(p, param);
	return p;
}

Node *newParam(Node *list, Node *type, Rout k){
	Node *p = newNode(SUB);
	p->dtype = type;
	p->pattern.routine = k;
	addChild(p, list);
	return p;
}

Node *newConst(char* name, Node* value){
	Node *p = newNode(CONSTANT);
	strcpy(p->name,name); 
	addChild(p, value);
	return p;
}

Node *newVar(Node* namelist, Node* decl){
	Node *p = newNode(VARI);
	p->dtype = decl;
	addChild(p, namelist);
	return p;
}

Node *newType(Types type, Node *child1, Node *child2){
	Node *p = newNode(TYPES);
	p->pattern.type = type;
	addChild(p, child1);
	addChild(p, child2);
	return p;
}

Node *newSelfDefineType(char *name){
	Node *p = newNode(TYPES);
	p->pattern.type = SELFDEFINE;
	strcpy(p->name, name);
	return p;
}
Node *newTypeDef(char *TypeName, Node *type){
	Node *p = newNode(TYPES);
	p->pattern.type = DECL;
	p->dtype = type;
	strcpy(p->name, TypeName);
	return p;
}

Node *newConstExp(Types type){
	Node *p = newNode(EXPR);
	p->dtype = newType(type, NULL, NULL);
	p->pattern.expr = CON_EXPR;
	return p;
}

Node *newOpExp(Oper op){
	Node *p = newNode(EXPR);
	p->pattern.expr = OP_EXPR;
	p->subexpr.oper = op;
	return p;
}

Node *newIdenExp(Iden type, char *name, Node *child){
	Node *p = newNode(EXPR);
	p->pattern.expr = ID_EXPR;
	p->subexpr.iden = type;
	strcpy(p->name, name);
	addChild(p, child);
	return p;
}

Node *newFuncExp(char *name, Node *args){
	Node *p = newNode(EXPR);
	p->pattern.expr = FN_EXPR;
	strcpy(p->name, name);
	addChild(p, args);
	return p;
}

Node *newStmt(Stmt stmt){
	Node *p = newNode(STMT);
	p->pattern.stmt = stmt;
	return p;
}

Node *addSibling(Node *p, Node *q){
	Node * ret;
	if (!p) return q;
	ret = p;
	while (p->sibling!=NULL) p = p->sibling;
	p->sibling = q;
	return ret;
}

void addChild(Node *parent, Node *child){
	int i = 0;
	while(i < MAX){
		if(parent->children[i] == NULL){
			parent->children[i] = child;
			return;
		}
		i++;
	}
}

void lineTrans(Node *p, Node *q){
	if(p != NULL && q != NULL){
		p->lineNo = q->lineNo;
	}
}

void lineAssign(Node *p, int q){
	if(p != NULL){
		p->lineNo = q;
	}
}

void strSet(char *dst, char *src){
	int i;
	for (i = 1; i < strlen(src) - 1; i++){
		dst[i - 1] = src[i];
	}
	dst[strlen(src) - 1] = 0;
}

Node *makeLabel(Node *n, int label){
	n->label = label;
	return n;
}

void printType(FILE *treeout, Node *p){
	switch (p->pattern.type){
		case DECL:{
			fprintf(treeout, "Type define %s ", p->name); 
			break;
		}
		case INTEGE:{
			fprintf(treeout, "Integer"); 
			break;
		}
		case REA:{
			fprintf(treeout, "Real"); 
			break;
		}
		case BOOLEA:{
			fprintf(treeout, "Boolean ");
			break;
		}
		case CHARA:{
			fprintf(treeout, "Char ");
			break;
		}
		case STR:{
			fprintf(treeout, "String ");
			break;
		}
		case ENUME: {
			fprintf(treeout, "Enum "); 
			if (!p->children[1]) fprintf(treeout, "name "); 
			else fprintf(treeout, "range ");  
			break;
		}
		case ARRA:{
			fprintf(treeout, "Array ");
			break;
		}
		case RECOR:{
			fprintf(treeout, "Record ");
			break;
		}
		case SELFDEFINE:{
			fprintf(treeout, "%s ", p->name); 
			break;
		}
	}
}

void printOperation(FILE *treeout, Node *p){
	fprintf(treeout, "Operation ");
	switch (p->subexpr.oper){
		case PLUS_OP:{
			fprintf(treeout, "plus"); 
			break;
		}
		case MINUS_OP:{
			fprintf(treeout, "minus"); 
			break;
		}
		case NEG_OP:{
			fprintf(treeout, "neg"); 
			break;
		}
		case MUL_OP:{
			fprintf(treeout, "mul"); 
			break;
		}
		case DIV_OP:{
			fprintf(treeout, "div"); 
			break;
		}
		case MOD_OP:{
			fprintf(treeout, "mod"); 
			break;
		}
		case AND_OP:{
			fprintf(treeout, "and"); 
			break;
		}
		case OR_OP:{
			fprintf(treeout, "or"); 
			break;
		}
		case LE_OP:{
			fprintf(treeout, "le"); 
			break;
		}
		case LT_OP:{
			fprintf(treeout, "lt"); 
			break;
		}
		case GE_OP:{
			fprintf(treeout, "ge"); 
			break;
		}
		case GT_OP:{
			fprintf(treeout, "gt"); 
			break;
		}
		case EQ_OP:{
			fprintf(treeout, "eq"); 
			break;
		}
		case UEQ_OP:{
			fprintf(treeout, "ueq"); 
			break;
		}
		case NOT_OP:{
			fprintf(treeout, "not"); 
			break;
		}
	}
}

void printExpression(FILE *treeout, Node *p){
	switch (p->pattern.expr){
		case OP_EXPR: { 
			printOperation(treeout, p);
			if(p->dtype)
				printType(treeout, p->dtype);
			break;
		}
		case ID_EXPR: { 
			switch (p->subexpr.iden){
				case BASIC_ID:{
					fprintf(treeout, "%s", p->name); 
					break;
				}
				case ARRAY_ID:{
					fprintf(treeout, "Array %s", p->name);
					break;
				}
				case RECORD_ID:{
					fprintf(treeout, "Record %s", p->name);
					break;
				}
			}
			if(p->dtype)
				printType(treeout, p->dtype);
			break;
		}
		case FN_EXPR: { 
			fprintf(treeout, "Function %s  args ", p->name);
			if(p->dtype)
				printType(treeout, p->dtype);
			break;
		}
		case CON_EXPR: { 
			fprintf(treeout, "Constant ");
			if(p->dtype)
				printType(treeout, p->dtype);
			printf("this is for test %d\n", p->attr.intNum);
			break;
		}
	}
}
void printStatement(FILE *treeout, Node *p){
	if (p->label) 
		fprintf(treeout, "Label %d ", p->label);

	switch (p->pattern.stmt){
		case IF_STMT:{ 
			fprintf(treeout, "If ");
			break;
		}
		case FOR_STMT:{ 
			fprintf(treeout, "For %s", p->name); 
			if (p->attr.intNum) 
				fprintf(treeout, " to "); 
			else
				fprintf(treeout, " downto ");
			break;
		}
		case REPEAT_STMT:{
			fprintf(treeout, "Repeat ");
			break;
		}
		case WHILE_STMT:{ 
			fprintf(treeout, "While ");
			break;
		}
		case GOTO_STMT:{
			fprintf(treeout, "Goto %d", p->attr.intNum);
			break;
		}
		case PROC_STMT:{
			fprintf(treeout, "Procedure %s", p->name);
			break;
		} 
		case ASSIGN_STMT:{
			fprintf(treeout, "Assignment ");
			break;
		}
		case CASE_STMT:{
			fprintf(treeout, "Case ");
			break;
		}
		case CASE_EXP_STMT:{ 
			fprintf(treeout, "Case ");
			break;
		}
	}
}

void printSubroutine(FILE *treeout, Node *p){
	switch (p->pattern.routine){
		case FUNC: { 
			fprintf(treeout, "Function %s ", p->name); 
			break;
		} 
		case PROC: { 
			fprintf(treeout, "Procedure %s ", p->name);
			break;
		}
		case PARAM_VAR: { 
			fprintf(treeout, "Var parameter");
			break;
		} 
		case PARAM_VAL: { 
			fprintf(treeout, "Val parameter");
			break;
		}
	}
}

void printTree(FILE *treeout, Node *p, int level){
	int i;	
	if (p == NULL) return;
	else if(level == 1){
		fprintf(treeout, "Line\n");
	}
	else{
		fprintf(treeout, "\n\t");
		for (i = 0; i < 2 * level; i++) 
			fprintf(treeout, "  ");
		fprintf(treeout, "|\n");
	}

	fprintf(treeout, "%d\t", p->lineNo);

	for (i = 0; i < 2 * level; i++) 
		fprintf(treeout, ". ");
	fprintf(treeout, "+- ");

	switch (p->nodes){
		case ROUTINE: { 
			fprintf(treeout, "Routine ");
			break;
		}
		case CONSTANT: { 
			fprintf(treeout, "Constant %s ", p->name);
			break;
		}
		case TYPES: { 
			printType(treeout, p); 
			printTree(treeout, p->dtype, level+1);
			break;
		} 
		case VARI: { 
			fprintf(treeout, "Variable ");
			printTree(treeout, p->dtype, level+1);
			break;
		} 
		case EXPR: { 
			printExpression(treeout, p);
			break;
		} 
		case STMT: { 
			printStatement(treeout, p);
			break;
		} 
		case SUB: { 
			printSubroutine(treeout, p);
			printTree(treeout, p->dtype, level+1);
			break;
		} 
	}
	printTree(treeout, p->children[0], level + 1);
	printTree(treeout, p->children[1], level + 1);
	printTree(treeout, p->children[2], level + 1); 
	printTree(treeout, p->children[3], level + 1);
	printTree(treeout, p->sibling, level);
}