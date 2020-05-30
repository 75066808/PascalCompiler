
all:
	bison myCompiler.y
	flex myCompiler.l
	g++ -g mySyntaxTree.cpp mySymbolTable.cpp myIRGenerator.cpp myCheckFolder.cpp main.cpp -o main -std=c++11

clean:
	rm -f main lex.yy.c myCompiler.tab.c
