#include "InvestmentAccount.h"
#include <cmath>

//Class Constructor 1
//@param t_initialAmount - principal balance
//@param t_annualInterestRate - annual percentage rate
//Note: no monthly deposit indicated
InvestmentAccount::InvestmentAccount(double t_initialAmount, double t_annualInterestRate) {
	m_initialAmount = t_initialAmount;
	m_annualInterestRate = t_annualInterestRate;
	m_monthlyDeposit = 0.0; // default value
}
//Class Constructor 2
//@param t_initialAmount - principal balance
//@param t_annualInterestRate - annual percentage rate
//@param t_monthlyDeposit - yearly deposit amount
InvestmentAccount::InvestmentAccount(double t_initialAmount, double t_annualInterestRate, double t_monthlyDeposit) {
	m_initialAmount = t_initialAmount;
	m_annualInterestRate = t_annualInterestRate;
	m_monthlyDeposit = t_monthlyDeposit;
}

//@return m_initialAmount - initial amount
double InvestmentAccount::getInitialAmount() {
	return m_initialAmount;
}
//@return m_monthlyDeposit - monthly deposit amount
double InvestmentAccount::getMonthlyDeposit() {
	return m_monthlyDeposit;
}
//@return m_annualInterestRate - annual interest rate
double InvestmentAccount::getAnnualInterestRate() {
	return m_annualInterestRate;
}
//@params: t_numberOfYears - number of years int
//@return - ending balance
double InvestmentAccount::getEndingBalance(int t_numberOfYears) {
	double monthlyRate;
	int totalMonths;
	double currentBalance;

	//monthly interest rate from APR
	monthlyRate = (getAnnualInterestRate() / 100.0) / 12.0;
	//set initial balance
	currentBalance = getInitialAmount();
	// get total months from years
	totalMonths = t_numberOfYears * 12;

	//iterate through each month and calculate new current balance
	for (int i = 0; i < totalMonths; i++) {
		currentBalance += m_monthlyDeposit;
		currentBalance += currentBalance * monthlyRate;
	}

	return currentBalance;
}
//@params: t_numberOfYears - number of years int
//@returns - the interest earned
double InvestmentAccount::getInterestEarned(int t_numberOfYears) {
	double totalDeposits;
	double interestEarned;

	// get total deposits
	totalDeposits = getMonthlyDeposit() * 12;
	// get deposit 
	interestEarned = getEndingBalance(t_numberOfYears) - getEndingBalance(t_numberOfYears - 1) - totalDeposits;

	return interestEarned;
}

//@params: t_numberOfYears - number of years int
//@returns -  the formatted ending balance
std::string InvestmentAccount::getEndingBalanceFormatted(int t_numberOfYears) {
	std::string formattedEndingBalance;

	// format ending balance
	formattedEndingBalance = format(round(getEndingBalance(t_numberOfYears), 2));

	return formattedEndingBalance;
}

//@params: t_numberOfYears - number of years int
//@return: string formatted interest earned
std::string InvestmentAccount::getInterestEarnedFormatted(int t_numberOfYears) {
	std::string formattedInterestEarned;

	//format interest earned
	formattedInterestEarned = format(round(getInterestEarned(t_numberOfYears), 2));

	return formattedInterestEarned;
}

//The following method rounds a value to the specified number of places.
//NOTE: It works for most values...but is not guaranteed to work for all values!
//@param t_value - the value to round
//@param t_places - the number of places to round
//@returns - the rounded number
double InvestmentAccount::round(double t_value, int t_places) {
	const int multiplier = pow(10, t_places);

	double roundedValue = (int)(t_value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;
}

//Formats a double value for output purposes.
//This method will not append with any 0s...so the value should be rounded prior to use.
//@param t_value - the value to format
//@returns - the formatted value.
std::string InvestmentAccount::format(double t_value) {
	std::string valueAsString = std::to_string(t_value);
	std::string formatted;

	bool decimalFound = false;
	int decimalCount = 0;

	int i;
	for (i = 0; i < valueAsString.size(); i++) {
		char currentChar = valueAsString[i];

		if (decimalCount == 2) {
			break;
		}

		if (currentChar == '.') {
			decimalFound = true;
		}
		else if (decimalFound && decimalCount != 2) {
			decimalCount++;
		}

		formatted.append(std::string(1, currentChar));
	}

	return formatted;
}