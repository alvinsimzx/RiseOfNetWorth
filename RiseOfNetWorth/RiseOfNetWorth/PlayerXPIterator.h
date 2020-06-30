#pragma once
#include "PlayerXP.h"
class PlayerXPIterator
{
private:
	PlayerXP* fPlayerXP;
public:
	typedef PlayerXPIterator Iterator;
	PlayerXPIterator();
	PlayerXPIterator(PlayerXP* aPlayerXP);
	~PlayerXPIterator();

	string operator*() const;

	//incremental operator overload
	PlayerXPIterator& operator++();
	PlayerXPIterator& operator++(int);

	//equivalence operator overload
	bool operator==(const Iterator& aOther) const;
	bool operator!=(const Iterator& aOther) const;

	PlayerXPIterator end();
};

