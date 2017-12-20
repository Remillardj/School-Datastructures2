//
//  treasureChest.cpp
//  Homework2
//
//  Created by admin on 4/23/17.
//  Copyright © 2017 Remillard Tech. All rights reserved.
//

#include <iostream>
#include "treasureChest.h"


treasureChest::treasureChest() {
    boxType::setBoxColor(black); //default to black
    for (int i = 0; i < 100; i++) {
        coinPurse[i] = nada; //initialize it all to default nada
    }
    coinAmt = 0;
}

treasureChest::treasureChest(double l, double w, double h, color setColor) :
boxType(l, w, h, setColor)
{
    boxType::setBoxColor(setColor); //check if color is set to black or brown
    for (int i = 0; i < 100; i++) {
        coinPurse[i] = nada; //initialize it all to default nada
    }
    coinAmt = 0;
}

void treasureChest::setBoxColor(color setColor) {
    if (setColor == black || setColor == brown) {
        boxType::setBoxColor(setColor);
    } else {
        std::cout << "[ERROR]: box color attempted to set to color other than black or brown in constructor." << std::endl;
    }
}

int treasureChest::getNumCoins() {
    return coinAmt;
}

void treasureChest::printCoinPurse() {
    for (int i = 0; i < 100; i++) {
        std::cout << coinPurse[i] << std::endl;
    }
}

void treasureChest::addCoin(coins add) {
    // check if coinPurse is hitting max
    if (getNumCoins() > 99) {
        std::cout << "[ERROR]: Too many coins!" << std::endl;
        
    } else {
        int idx = 0;
        for (int i = 0; i < 100; i++) {
            if (coinPurse[i] == nada) {
                idx = i;
                break;
            }
        }
        coinPurse[idx] = add;
        coinAmt++;
    }
}

void treasureChest::removeCoin(coins remove) {
    int idx = 0;
    for (int i = 0; i < 100; i++) {
        if (coinPurse[i] == remove) {
            idx = i;
            break;
        }
    }
    coinPurse[idx] = nada;
    coinAmt--;
}

int treasureChest::getSum() {
    int sum = 0; //initialize sum
    for (int i = 0; i < 100; i++) {
        sum += coinPurse[i];
    }
    return sum;
}











