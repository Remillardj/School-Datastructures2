//
//  main.cpp
//  MiniLab
//
//  Created by admin on 4/18/17.
//  Copyright © 2017 Remillard Tech. All rights reserved.
//

#include <iostream>
#include "staticArray.h"


int main() {
    
    staticArray<int> myArr;
    
    // insert data
    myArr.setStaticArray(0, 0);
    myArr.setStaticArray(1, 1);
    myArr.setStaticArray(2, 2);
    myArr.setStaticArray(3, 3);
    myArr.setStaticArray(4, 4);
    myArr.setStaticArray(5, 5);
    myArr.setStaticArray(6, 6);
    myArr.setStaticArray(7, 7);
    myArr.setStaticArray(8, 8);
    myArr.setStaticArray(9, 9);
    
    staticArrayIterator<int> iterator = myArr.beginStaticArray();
    staticArrayIterator<int> convert(myArr.endStaticArray());
    
    while (iterator != convert) {
        std::cout << *iterator << std::endl;
        ++iterator;
        if (iterator == convert) {
            std::cout << *iterator << std::endl;
        }
    }
    
    return 0;
}
