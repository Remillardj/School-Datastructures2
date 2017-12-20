//
//  stackMachine.hpp
//  Homework4
//
//  Created by admin on 5/2/17.
//  Copyright © 2017 Remillard Tech. All rights reserved.
//

#ifndef stackMachine_h
#define stackMachine_h

#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "stackMachine.h"

using namespace std;

template <class Type>
class staticMachine
{
public:
    staticMachine();
    
    void reset();
    
    void push(const int);
    
    void pop(const int);
    
    void add();
    void subtract();
    void multiply();
    void divide();
    
    void getFile(string directory);
    
    Type retrieveElement(int);
    
private:
    Type memory[100];
    std::stack<Type> myStack;
};

template <class Type>
staticMachine<Type>::staticMachine()
{
    reset();
}

template <class Type>
void staticMachine<Type>::reset() {
    for (int i = 0; i < 100; i++) {
        memory[i] = 0;
    }
    
    while(!myStack.empty()) {
        myStack.pop();
    }
}

template <class Type>
Type staticMachine<Type>::retrieveElement(int pos) {
    if (pos >= 0 && pos < 100) {
        return memory[pos];
    } else {
        std::cout << "[ERROR]: Index pos out of range" << std::endl;
        return 1;
    }
}

template <class Type>
void staticMachine<Type>::push(int pos)
{
    if (pos >= 0 && pos < 100) {
        myStack.push(retrieveElement(pos));
    }
}

template <class Type>
void staticMachine<Type>::pop(int pos)
{
    if (!myStack.empty()){
        if (pos >= 0 && pos < 100) {
            memory[pos] = myStack.top();
            myStack.pop(); //expects no param
            //myStack.pop(retrieveElement(pos));
        }
    }
}

template <class Type>
void staticMachine<Type>::add()
{
    if (myStack.size() > 1) {
        Type y = myStack.top();
        myStack.pop();
        Type x = myStack.top();
        myStack.pop();
        
        myStack.push(x + y);
    }
}

template <class Type>
void staticMachine<Type>::subtract()
{
    if (myStack.size() > 1) {
        Type y = myStack.top();
        myStack.pop();
        Type x = myStack.top();
        myStack.pop();
        
        myStack.push(x - y);
    }
}

template <class Type>
void staticMachine<Type>::multiply()
{
    if (myStack.size() > 1) {
        Type y = myStack.top();
        myStack.pop();
        Type x = myStack.top();
        myStack.pop();
        
        myStack.push(x * y);
    }
}

template <class Type>
void staticMachine<Type>::divide()
{
    if (myStack.size() > 1) {
        Type y = myStack.top();
        myStack.pop();
        Type x = myStack.top();
        myStack.pop();
        
        myStack.push(x / y);
    }
}

template <class Type>
void staticMachine<Type>::getFile(string directory)
{
    string temp;
    ifstream in;
    stringstream line;
    Type inum;
    int counter = 0;
    
    in.open(directory);
    
    // inum if unable to open
    if (!in) {
        cout << "[ERROR]: Cannot open file!" << endl;
        exit(1);
    }
    
    while(!in.eof()) {
        getline(in, temp);
        
        // insert data
        if (temp == ".data") {
            getline(in, temp);
            line.str(temp);
            while (line >> inum) {
                memory[counter] = inum;
                ++counter;
            }
        } else if (!temp.compare(0, 3, "add")) {
                     add();
                } else if (temp == "subtract") {
                    subtract();
                } else if (temp == "multiply") {
                    multiply();
                } else if (temp == "divide") {
                    divide();
                } else if (!temp.compare(0, 3, "pop")) { //get pop
                    line.clear();
                    line.str(temp.substr(4));
                    line >> inum;
                    pop(inum);
                } else if (!temp.compare(0, 4, "push")) { //get push
                    line.clear();
                    line.str(temp.substr(5));
                    line >> inum;
                    push(inum);
                }
        }
    
    in.close();
}

#endif /* stackMachine_hpp */








