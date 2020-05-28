#include "mySyntaxTree.hpp"
#include "mySymbolTable.hpp"
#include "myCheckFolder.hpp"
#include "myIRGenerator.hpp"

#include "lex.yy.c"
#include <fstream>
#include <iostream>

using namespace std;

extern FILE *yyin;
extern Node *root;
extern SymbolTable *global;

int main(int argc, char *argv[])
{
	char *outputFileName = NULL;
	int option;

    string file;

    cout << "Input pascal file name:" << endl;

    cin >> file;

	yyin = fopen(file.c_str(), "r");

	FILE *treeout = fopen((file + ".tree").c_str(), "w");
    ofstream symout(file + ".sym");
    ofstream irout(file + ".ir");

	yyparse();

	printTree(treeout, root, 1);
    
    buildSymbolTable(root, nullptr);

    global->printTable(symout, 0);

    typeCheckAndConstFold(root, global);

    generateIR(irout, root, global);
    
    return 0;

}
