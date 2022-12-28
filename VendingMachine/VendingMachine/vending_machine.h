#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_
#include <iostream>
using namespace std;

// id_ is a unique identifier for the VendingBank much like a serial number
class VendingBank // strictly numerical
{
public:
	VendingBank();
	VendingBank(int id);

	//getters-setters
	int id() const;
	double penny() const; 
	double nickel() const;
	double dime() const; 
	double quarter() const; 
	void set_amounts(double penny, double nickel, double dime, double quarter);

	// FILL IN FURTHER PUBLIC FUNCTIONS HERE
	double coinCounter(double penny_, double nickel_, double dime_, double quarter_); 
	void change(); // gives back change


	// Overloaded operators
	VendingBank operator+(const VendingBank& vending_bank) const;
	VendingBank& operator-=(const VendingBank& vending_bank);
	VendingBank operator-(const VendingBank& vending_bank) const; 
	VendingBank& operator+=(const VendingBank& vending_bank);

	
private:
	int id_;

	// FILL IN DATA MEMBERS
	double penny_;
	double nickel_;
	double dime_;
	double quarter_;

}
#endif
