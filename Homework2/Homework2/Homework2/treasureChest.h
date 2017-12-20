#ifndef treasureChest_H
#define treasureChest_H

#include "boxType.h"
#include <string>
#include <vector>

enum coins {gold = 25, silver = 10, copper = 1, nada = 0};

class treasureChest : public boxType
{
public:
    treasureChest();
    treasureChest(double l, double w, double h, color setColor);
    
    int getNumCoins();
    void addCoin(coins add);
    void removeCoin(coins remove);
    
    int getSum();
    
    void setBoxColor(color setColor);
    
    void printCoinPurse();
    
private:
    coins coinPurse[100];
    int coinAmt;
};

#endif
