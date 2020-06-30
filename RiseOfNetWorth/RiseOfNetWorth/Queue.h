#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <class T>
class Queue
{
private:
	vector<T> fElements;
public:
	bool isEmpty()
	{
		return fElements.empty();
	};
	int size() const
	{
		return fElements.size();
	};

	void enqueue(const T& aItem)
	{
		fElements.push_back(aItem);
	}
	const T& dequeue()
	{
		if (!isEmpty())
		{
			const T& Result = fElements[0];
			fElements.erase(fElements.begin());
			return Result;
		}
		else
		{
			throw underflow_error("Queue is empty.");
		}
	}

	const T& peek()
	{
		return fElements[0];
	}
	
};

