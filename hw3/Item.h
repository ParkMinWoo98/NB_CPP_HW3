#pragma once
#include <iostream>

using namespace std;

class Item
{
protected:
	string name_;
	int price_;

public:
	Item() : name_(""), price_(0) {}
	Item(string name, int price) : name_(name), price_(price) {}

	void PrintInfo() const;
	string GetName() const;
	int GetPrice() const;
};

bool CompareItemsByPrice(const Item& a, const Item& b);
