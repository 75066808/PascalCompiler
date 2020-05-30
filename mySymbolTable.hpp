#pragma once
#include "mySyntaxTree.hpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

class SymbolTable {
public:
    SymbolTable(string tableName, SymbolTable *parent);
    ~SymbolTable();
    
    Node* findSymbol(string symbolName);
    SymbolTable* findSymbolTable(string tableName);

    bool insertSymbol(string symbolName, Node *symbolVal);

    string getTableName(void);
    string getConnectTableName(void);

    SymbolTable* getParent(void);
    SymbolTable* getChildren(string name);

    Node* getActualType(Node *type);
    SymbolTable* getRecordTable(Node *type); 

    size_t getTypeSize(Node *type);
    size_t getRecordOffset(Node *type, string name);


    void printTable(ofstream& out, int level); 
private:
    string tableName;
    SymbolTable *parent;
    unordered_map<string, SymbolTable*> children;
    unordered_map<string, Node*> symbolMap;
};

void buildSymbolTable(Node *node, SymbolTable *table = nullptr);
