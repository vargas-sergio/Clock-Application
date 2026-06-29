// CS210 Module 5.3 Project 3
// 
// Author: Sergio J. Vargas
// Date: 06/7/2026
//
// Make and investment app to display investments over a selected period of time.
#include <iostream>
#include <iomanip>
#include "InvestmentAccount.h"

using namespace std;


//Main Class function prototypes
//Displays the account details, as well as account balances and interest earned for each year.
//@param account - InvestmentAccount object
//@param numberOfYears - number of years integer
//@return - void display output
void displayOutput(InvestmentAccount account, int numberOfYears) {
    string borderTop(80, '=');
    string borderBottom(80, '-');

    cout << borderTop << endl;
    cout << "Year";
    cout << right << setw(38) << "Year End Balance";
    cout << right << setw(38) << "Year End Earned Interest" << endl;
    cout << borderBottom << endl;

    // display out the balances
    for (int year = 1; year <= numberOfYears; year++) {
        cout << left << setw(4) << year;
        cout << right << setw(36) << account.getEndingBalanceFormatted(year);
        cout << right << setw(36) << account.getInterestEarnedFormatted(year) << endl;
    }
    cout << endl;
};

int main()
{
    double userInitialAmount;
    double userAnnualInterestRate;
    double userMonthlyDeposit;
    int userYears;
    string border(20, '*');

    cout << border << border << border << endl;
    cout << border << right << setw(10) << "Data ";
    cout << left << setw(10) << "Input" << border << endl;

    //Get the input...validate that the values are non-negative.
    do {
        cout << "Initial Investment Amount: ";
        cin >> userInitialAmount;
    } while (userInitialAmount < 0);

    do {
        cout << "Monthly Deposit: ";
        cin >> userMonthlyDeposit;
    } while (userMonthlyDeposit < 0);

    do {
        cout << "Annual Interest: ";
        cin >> userAnnualInterestRate;
    } while (userAnnualInterestRate < 0 || userAnnualInterestRate > 100);

    do {
        cout << "Number of years: ";
        cin >> userYears;
    } while (userYears < 0);

    // Display initial inputs

    cout << border << border << border << endl;
    cout << border << right << setw(10) << "Data ";
    cout << left << setw(10) << "Input" << border << endl;
    cout << "Initial Investment Amount:  $" << userInitialAmount << endl;
    cout << "Monthly Deposit:  $" << userMonthlyDeposit << endl;
    cout << "Annual Interest:  %" << userAnnualInterestRate << endl;
    cout << "Number of years:  " << userYears << endl;

    //Create two InvestmentAccount variables...one with monthly deposit and one without monthly deposit
    InvestmentAccount investmentSansDeposit(userInitialAmount, userAnnualInterestRate);
    InvestmentAccount investmentWithDeposit(userInitialAmount, userAnnualInterestRate, userMonthlyDeposit);
    //Display the output for each investment account
    cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
    displayOutput(investmentSansDeposit, userYears);
    cout << "      Balance and Interest With Additional Monthly Deposits" << endl;
    displayOutput(investmentWithDeposit, userYears);
}