#pragma once
#include <iostream>
#include <algorithm>
#include "Item.h"

using namespace std;

template <typename T>
class Inventory
{
private:
	T* pItems_ = nullptr;
	int capacity_;
	int size_;

public:
	Inventory<T>(int capacity = 10) : size_(0)
	{
		capacity = max(1, capacity);
		capacity_ = capacity;
		pItems_ = new T[capacity];
	}

	~Inventory()
	{
		delete[] pItems_;
		pItems_ = nullptr;
	}

	Inventory(const Inventory<T>& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; i++)
		{
			pItems_[i] = other.pItems_[i];
		}
		cout << "인벤토리 복사 완료" << endl;
	}

	void Assign(const Inventory<T>& other)
	{
		if (capacity_ != other.capacity_)
		{
			delete[] pItems_;
			pItems_ = new T[other.capacity_];
		}

		capacity_ = other.capacity_;
		size_ = other.size_;
		for (int i = 0; i < size_; i++)
		{
			pItems_[i] = other.pItems_[i];
		}
		cout << "인벤토리 복사 완료" << endl;
	}

	void Resize(int newCapacity)
	{
		T* newPtr = new T[newCapacity];
		for (int i = 0; i < capacity_; i++)
		{
			newPtr[i] = pItems_[i];
		}
		delete[] pItems_;
		capacity_ = newCapacity;
		pItems_ = newPtr;
		cout << "인벤토리 용량" << newCapacity << " 으로 변경 완료" << endl;
	}

	void AddItem(const T& item)
	{
		if (size_ >= capacity_)
		{
			Resize(capacity_ * 2);
		}
		pItems_[size_++] = item;
		cout << item.GetName() << " 추가" << endl;
	}

	void RemoveLastItem()
	{
		if (size_ <= 0)
		{
			cout << "인벤토리가 비어있습니다." << endl;
			return;
		}

		cout << pItems_[size_ - 1].GetName() << " 제거" << endl;
		size_--;
	}

	int GetSize() const
	{
		return size_;
	}

	int GetCapacity() const
	{
		return capacity_;
	}

	void PrintAllItems() const
	{
		cout << "보유한 아이템은 다음과 같습니다." << endl;
		for (int i = 0; i < size_; i++)
		{
			pItems_[i].PrintInfo();
		}
	}

	void SortItems()
	{
		sort(pItems_, pItems_ + size_, CompareItemsByPrice);
		cout << "정렬을 완료했습니다." << endl;
	}
};

