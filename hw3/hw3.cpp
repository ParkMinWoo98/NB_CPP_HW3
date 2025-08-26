#include <iostream>
#include "Inventory.h"
#include "Weapon.h"
#include "Potion.h"

int main()
{
	Inventory<Item> inventory;
	
	Weapon weapon1("weapon_1", 200);
	inventory.AddItem(weapon1);

	Weapon weapon2("weapon_2", 400);
	inventory.AddItem(weapon2);

	Potion potion1("potion_1", 300);
	inventory.AddItem(potion1);

	Potion potion2("potion_2", 100);
	inventory.AddItem(potion2);

	cout << "가진 아이템의 갯수는 " << inventory.GetSize() << "개 입니다." << endl;
	inventory.PrintAllItems();
	cout << endl;

	inventory.SortItems();
	inventory.PrintAllItems();
	cout << endl;

	inventory.RemoveLastItem();
	cout << "가진 아이템의 갯수는 " << inventory.GetSize() << "개 입니다." << endl;
	inventory.PrintAllItems();
	cout << endl;

	cout << inventory.GetCapacity() << endl;
	inventory.Resize(inventory.GetCapacity() * 2);
	cout << inventory.GetCapacity() << endl;
}
