//
//  stackMachine.cpp
//  Homework4
//
//  Created by admin on 5/2/17.
//  Copyright © 2017 Remillard Tech. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "stackMachine.h"

using namespace std;

typedef int Type;

//void getFile(string directory)
//{
//    string temp;
//    vector<string> numbers;
//    ifstream in;
//    stringstream line;
//    int check;
//    int counter = 0;
//    
//    in.open(directory);
//    
//    // check if unable to open
//    if (!in) {
//        cout << "[ERROR]: Cannot open file!" << endl;
//        exit(1);
//    }
//
//    while(!in.eof()) {
//        getline(in, temp);
//        if (temp == ".data") {
//            getline(in, temp);
//            line.str(temp);
//            while (line >> check) {
//                
//            }
//        }
//    }
//    
//    in.close();
//}

void printMemory(staticMachine<Type>& macbookpro) {
    for (int i = 0; i < 100; i++) {
        cout << macbookpro.retrieveElement(i) << " ";
        if (i % 10 == 9) {
            cout << endl;
        }
    }
}

int main()
{
    staticMachine<Type> macbookpro;
    
    cout << "=========TEST ONE==========\n";
    string dir1 = "/Users/admin/Documents/Homework4/Homework4/lab3_test1.txt";
    macbookpro.getFile(dir1);
    printMemory(macbookpro);
    macbookpro.reset();
    
    cout << "\n=========TEST TWO==========\n";
    string dir2 = "/Users/admin/Documents/Homework4/Homework4/lab3_test2.txt";
    macbookpro.getFile(dir2);
    printMemory(macbookpro);
    macbookpro.reset();
    
    
    return 0;
}
