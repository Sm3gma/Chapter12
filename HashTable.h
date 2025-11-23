#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
template <class T>
class Table
{
private:
	static const int MAX = 40;
	static const int NEVER_USED = -1;
	static const int PREVIOUSLY_USED = -2;
	int capacity;
	vector<T> array;
	int used;
	//convert/hash key into index
	int hash(int key) const
	{
		return key % capacity;
	}
	//find the next hash index
	int next_index(int index) const
	{
		return ((index + 1) % capacity);
	}
	//check if the key is -1 (NEVER_USED)
	bool is_vacant(int index) const
	{
		return array[index].key == NEVER_USED;
	}
public:
	//constructor
	Table(int cap = MAX)
	{
		capacity = cap;
		used = 0;
		array.resize(capacity);
		for (int i = 0; i < capacity; i++)
			array[i].key = NEVER_USED;
	}
	int size() const
	{
		return used;
	}
	bool insert(const T& entry)
	{
		int index = 0;
		if (!find_index(entry.key, index))
		{
			index = hash(entry.key);
			while (!is_vacant(index))
				index = next_index(index);
			++used;
		}
		array[index] = entry;
		return true;
	}
	bool remove(int key)
	{
		int index = 0;
		if (find_index(key, index))
		{
			array[index].key = PREVIOUSLY_USED;
			--used;
			return true;
		}
		return false;
	}
	bool find_index(const int key, int& index) const
	{
		int count = 0;
		index = hash(key);
		while ((count < capacity) && (!is_vacant(index)) && array[index].key !=
			key)
		{
			++count;
			index = next_index(index);
		}
		return (array[index].key == key);
	}
	void display(int index) const
	{
		cout << "\n\t\t\tStudent record found at index #" << index;
		cout << "\n\t\t\t\tStudentID : " << array[index].ID;
		cout << "\n\t\t\t\tName : " << array[index].name;
		cout << "\n\t\t\t\tMajor : " << array[index].major;
		cout << "\n\t\t\t\tGPA : " << array[index].GPA << '\n';
	}
	friend ostream& operator<<<>(ostream& outs, const Table<T>& obj);
};
template<class T>
ostream& operator<<(ostream& outs, const Table<T>& obj)
{
	if (obj.size() != 0)
	{
		outs << "\n\t\t\tRecord(s):";
		for (int i = 0; i < obj.capacity; i++)
			if (obj.array[i].key > 0)
				outs << "\n\t\t\t[" << setw(2) << i << "] - " <<
				obj.array[i].ID << ", " << obj.array[i].name << ", " << obj.array[i].major << ", "
				<< obj.array[i].GPA;
			else
				outs << "\n\t\t\t[" << setw(2) << i << "] - empty";
	}
	else
		outs << "\n\t\t\tERROR: No record found.";
	return outs;
}