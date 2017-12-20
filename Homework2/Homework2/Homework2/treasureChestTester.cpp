//Test client for CSC 2431 HW2, SP17
#include <iostream>
#include <iomanip>
#include "rectangleType.h"
#include "boxType.h"
#include "treasureChest.h"

using namespace std;

void printBoxColor(boxType *box);

int main()
{
	cout << "========== Testing boxType ==========" << endl;

	//test to make sure boxType works with patterns now
	boxType *wcc = new boxType(1, 1, 1, white);

	cout << "Box dimensions: ";
	wcc->print();
	cout << endl;
	
	cout << "What color is it?" << endl;
	printBoxColor(wcc);

	cout << endl << "========== Be ye testing of yon treasureChest ==========" << endl;

	treasureChest *swag = new treasureChest(10, 10, 10, brown);
	
	//... and containing some coins
	swag->addCoin(gold);
	swag->addCoin(silver);
	swag->addCoin(gold);
	swag->addCoin(copper);
	swag->addCoin(silver);
	swag->addCoin(gold);
	swag->addCoin(copper);

	//pirate tells us what color the chest is
	printBoxColor(swag);
	cout << endl;

	//pirate removes some coins
	swag->removeCoin(gold);
	swag->removeCoin(silver);
	swag->removeCoin(copper);

	//pirate tells us what's in the chest
	cout << "Arr matey, the chest contains " << swag->getNumCoins();
	cout << " coins which, in total, is worth " << endl;
	cout << swag->getSum() << " dubloons ";
	cout << "(on my honor, I found it this way!)" << endl;
	cout << endl;

	//pirate tells us color of chest after painting it
	cout << "Painting the chest black, matey..." << endl;
	swag->setBoxColor(black);
	printBoxColor(swag);
	cout << endl;

	//pirate refuses to let us paint the chest green
	cout << endl << "No silly green pirate chests!" << endl;
	swag->setBoxColor(green);
	printBoxColor(swag);
	cout << endl;

	//pirate tries to stuff chest with 101 more gold coins (it can only fit 100)
	for (int i = 0; i < 101; i++)
		swag->addCoin(gold);
	
	cout << endl << "Now there be " << swag->getNumCoins() << " coins in the chest." << endl;

	cout << "Arr matey, the chest contains this much loot ";
	cout << "(hands off!): ";
	cout << swag->getSum() << " dubloons" << endl;
	cout << endl;

	return 0;
}

//This function prints the pattern of a boxType object
//Parameters: pointer to a boxType object
//Returns: nothing
void printBoxColor(boxType *box)
{
	color c = box->getBoxColor();
	switch (c)
	{
	case green:
		cout << "The box is green!" << endl;
		break;
	case brown:
		cout << "The box is brown." << endl;
		break;
	case black:
		cout << "The box is black." << endl;
		break;
	case white:
		cout << "The box is white." << endl;
		break;
	default:
		cout << "Here be dragons!" << endl;
	}
}
