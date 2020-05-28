%{
	#include <stdio.h>
    #include "myCompiler.tab.c"
	#include "mySyntaxTree.hpp"
%}
%option yylineno
%%
"("	    return LP;
")"	    return RP;
"["	    return LB;
"]"	    return RB;
"."	    return DOT;
","	    return COMMA;
":"	    return COLON;
"*"	    return MUL;
"/"	    return DIV;
"+"	    return PLUS;
"-"	    return MINUS;
">="    return GE;
">"	    return GT;
"<="	return LE;
"<"	    return LT;
"="	    return EQUAL;
":="	return ASSIGN;
"<>"	return UNEQUAL;
";"	    return SEMI;

"program" return PROGRAM;
"const" return CONST;
"type" return TYPE;
"array" return ARRAY;
"record" return RECORD;
"var" return VAR;
"function" return FUNCTION;
"procedure" return PROCEDURE;
"or" return OR;
"and" return AND;
"mod" return MOD;
"not" return NOT;
"read" return READ;
"if" {
    yylval.intNum = yylineno;
	return IF;
}
"then" {
    yylval.intNum = yylineno;
	return THEN;
}
"else" return ELSE;
"repeat" {
    yylval.intNum = yylineno;
	return REPEAT;
}
"until" return UNTIL;
"while" {
    yylval.intNum = yylineno;
	return WHILE;
}
"do" {
    yylval.intNum = yylineno;
	return DO;
}
"for" {
    yylval.intNum = yylineno;
	return FOR;
}
"to" return TO;
"downto" return DOWNTO;
"begin" {
    yylval.intNum = yylineno;
	return BEGINNING;
}
"end" {
    yylval.intNum = yylineno;
	return END;
}
"case" {
    yylval.intNum = yylineno;
	return CASE;
}
"of" return OF;
"goto" {
    yylval.intNum = yylineno;
	return GOTO;
}


"false"	{
    yylval.intNum = 0;
	return BOOLEAN;
}
"true"	{
    yylval.intNum = 1;
	return BOOLEAN;
}
"maxint"	{
    yylval.intNum = 32767;
	return INTEGER;
}

"boolean" 	return TYPE_BOOLEAN;
"char" 		return TYPE_CHAR;
"integer" 	return TYPE_INTEGER;
"real" 		return TYPE_REAL;
"string" 	return TYPE_STRING;

"abs"|"chr"|"odd"|"ord"|"pred"|"sqr"|"sqrt"|"succ"	{
	strcpy(yylval.strValue, yytext);
	return SYS_FUNCT;
}

"write"|"writeln"|"readln"	{
	strcpy(yylval.strValue, yytext);
	return SYS_PROC;
}

[a-zA-Z][a-zA-Z0-9_]*	{
	strcpy(yylval.strValue, yytext);
	return NAME;
}
[0-9]+	{
	yylval.intNum = atoi(yytext);
	return INTEGER;
}
[0-9]+\.[0-9]+	{
	yylval.floatNum = atof(yytext);
	return REAL;
}
\'.\'	{
	yylval.intNum = yytext[1];
	return CHAR;
}
\'[^'\n]*\'	{
	strcpy(yylval.strValue, yytext);
	return STRING;
}
.	{}
\n	{}
%%
int yywrap(void){
	return 1;
}
