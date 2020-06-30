 #pragma once
#include <iostream>
using namespace std;
class Properties
{
private:
	int fPrice;
	int fMortgagePrice;
	bool fOwned;
protected:
	string fPlaceName;
public:
	Properties(int aPrice,string aPlaceName);
	~Properties();

	virtual string PropertyMessage()=0;

	int GetPrice();
	int GetSellPrice();
	void BuyProperty();
	bool GetOwnershipStatus();
	string OwnershipStatusString();
	
	void SetOwnershipStatus(bool aStatus);
};

