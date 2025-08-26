#include "Item.h"

void Item::PrintInfo() const
{
	cout << "[�̸�: " << name_ << ", ����: " << price_ << "G]" << endl;
}

string Item::GetName() const
{
	return name_;
}

int Item::GetPrice() const
{
	return price_;
}

bool CompareItemsByPrice(const Item& a, const Item& b)
{
	return a.GetPrice() < b.GetPrice();
}