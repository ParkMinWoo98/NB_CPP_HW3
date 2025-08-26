#pragma once
#include "Item.h"

class Potion : public Item
{
public:
	Potion(string name, int price) : Item(name, price) {}
};

