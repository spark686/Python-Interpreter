#ifndef STATEMENT_H
#define STATEMENT_H
#include <iostream>
#include <string>
#include <vector>
#include "AST.h"
#include "Lexer.h"
#include "InfixParser.h"
using namespace std;

class Statement{
    public:
    Statement();
    size_t level;
    vector <Token*> condition;
    vector <Statement*> body;
    virtual ~Statement();
    virtual void print();
    virtual void deleteStatement();
    virtual void calculate(InfixParser* infixParser);
    // virtual vector <Token*> getValue();
};

class While: public Statement{
    public:
    size_t level;
    vector <Token*> condition;
    vector <Statement*> body;
    void deleteStatement();
    void print();
    void calculate(InfixParser* infixParser);
    // vector <Token*> getValue();
};

class If: public Statement{
    public:
    size_t level;
    vector <Token*> condition;
    vector <Statement*> body;
    void deleteStatement();
    void print();
    void calculate(InfixParser* infixParser);
    // vector <Token*> getValue();
};


class Else: public Statement{
    public:
    size_t level;
    vector <Token*> condition;
    vector <Statement*> body;
    void deleteStatement();
    void print();
    void calculate(InfixParser* infixParser);
    // vector <Token*> getValue();
};

class Print: public Statement{
    public:
    size_t level;
    vector <Statement*> body;
    void print();
    void deleteStatement();
    void calculate(InfixParser* infixParser);
    // vector <Token*> getValue();
};

class Expression: public Statement{
    public:
    size_t level;
    vector <Token*> body;
    void print();
    void deleteStatement();
    void calculate(InfixParser* infixParser);
    // vector <Token*> getValue();
};

#endif