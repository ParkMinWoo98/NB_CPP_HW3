#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(string name, int price) : Item(name, price) {}
};

