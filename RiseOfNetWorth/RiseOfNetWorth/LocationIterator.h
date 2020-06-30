#pragma once
#include "Location.h"

class LocationIterator
{
private:
	Location* fLocation;
public:
	typedef LocationIterator Iterator;
	LocationIterator(Location* aLocation);
	~LocationIterator();

	string operator*() const;

	//Incremental operators
	LocationIterator& operator++();
	LocationIterator& operator++(int);

	//Decremental Operators
	LocationIterator& operator--();
	LocationIterator& operator--(int);

	//equivalence operators
	bool operator==(const Iterator& aOther) const;
	bool operator!=(const Iterator& aOther) const;

	LocationIterator begin();
	Location* current() const;// points and returns the current node
	LocationIterator end();
};

