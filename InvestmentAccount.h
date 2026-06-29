#ifndef PROJECT2_SOURCE_FILES_INVESTMENTACCOUNT_H_
#define PROJECT2_SOURCE_FILES_INVESTMENTACCOUNT_H_

#include <string>
#include <cmath>

class InvestmentAccount
{

public:
	InvestmentAccount(double t_initialAmount, double t_annualInterestRate); //monthlyDeposit is 0!
	InvestmentAccount(double t_initialAmount, double t_annualInterestRate, double t_monthlyDeposit);

	double getEndingBalance(int t_numberOfYears);  //Calculate the ending balance after number of years
	// Use www.calculators.org/savings/monthly.php to test values
	double getInterestEarned(int t_numberOfYears); //Calculate the interest earned for number of years

	std::string getEndingBalanceFormatted(int t_numberOfYears);	//Use format and round to get the ending balance as a decimal to 2 places
	std::string getInterestEarnedFormatted(int t_numberOfYears);  //Use format and round to get the ending balance as a decimal to 2 places

	double getInitialAmount();
	double getMonthlyDeposit();
	double getAnnualInterestRate();

	double round(double t_value, int t_places);
	std::string format(double t_value);


private:
	double m_initialAmount;
	double m_monthlyDeposit;
	double m_annualInterestRate;

};

#endif // PROJECT2_SOURCEFILES_INVESTMENTACCOUNT_H_