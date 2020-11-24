#include <iostream>
#include <vector>

#include "SLList.h"

bool intInVector(int val, std::vector<int> vec)
{
	for (auto i = 0; i < vec.size(); i++)
		if (val == vec[i])
			return true;
	return false;
}

int getSLListLength(const SLList* list)
{
	auto count = 0;
	while (list->hasNext())
	{		
		list = list->next();
		count++;
	}
	return count;
}

SLList* kFromTheEnd(const SLList* list, int k)
{
	auto count = getSLListLength(list);
	for (auto i = 1; i < count - k; i++)
		list = list->next();
	return const_cast<SLList*>(list);
}

void removeSLListDuplicates(SLList* list)
{
	auto values = std::vector<int>();
	auto prev = list;
	do 
	{
		auto data = list->getData();
		if (intInVector(data, values))
		{
			prev->removeNext();
		}
		else 
		{
			values.push_back(data);
			prev = list;
		}
		list = prev->next();
	} while (list != nullptr);
}

void printSLList(const SLList* list)
{
	while (list->hasNext())
	{
		std::cout << list->getData();		
		list = list->next();
		if (list->hasNext())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

void main()
{
	auto first = SLList::beginList(rand() % 5);
	auto list = first;
	for (auto i = 0; i < 10; i++)
		list = list->addElement(rand() % 5);
	printSLList(first);
	removeSLListDuplicates(first);
	printSLList(first);
	auto count = getSLListLength(first);
	for (auto i = 0; i < count; i++)
		std::cout << i << " from the end is " << kFromTheEnd(first, i)->getData() << std::endl;
	delete first;
}