#pragma once

#include <fstream>
#include <string>
#include <queue>
#include "mySyntaxTree.hpp"
#include "mySymbolTable.hpp"

using namespace std;

class IRGenerator {

public:
    static string generateTempLabel(void); 

    static string generateTempName(void);

    static string generateTempPtrName(void);

    static void generatePrint(ofstream &out, string s0, string s1 = "", string s2 = "", string s3 = "");
    
    static void generateAssignPrint(ofstream &out, string s0, string s1 = "", string s2 = "", string s3 = "");

    static string generateResultName(ofstream &out, Node *node, bool needIndirect = true); 

    static string generateResultValue(Node *node); 

    static void recycleTempName(string name);

    static bool checkConstEqual(Node *const1, Node *const2);

private:
    static int tempLabelCount;
    static int tempNameCount;
    static int tempPtrNameCount;

    static priority_queue<int, vector<int>, greater<int> > tempNameHeap;
    static priority_queue<int, vector<int>, greater<int> > tempPtrNameHeap;
    
};

void generateIR(ofstream &out, Node *root, SymbolTable *global, string assignName = "");
