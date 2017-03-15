#include <iostream>
#include <conio.h>
#include <string>
#include <vector>;

using namespace std;

struct emp
{
	int id;
	string fn;
	string ln;
	double rate;
	double hours;
};

bool DoAgain()
{
	char prompt = '\0';

	while (prompt != 'y' && prompt != 'n' && prompt != 'Y' && prompt != 'N')
	{
		cout << endl << endl << "Would you like to enter another employee? (y/n)";
		cin >> prompt;
		cout << endl;
	}

	return (prompt == 'y' || prompt == 'Y');
}

int main()
{
	vector<emp> empvec;
	emp e;

	// Prompt for entry of employee data
	do
	{
		cout << "Student ID: ";
		cin >> e.id;
		cout << "First name: ";
		cin >> e.fn;
		cout << endl << "Last name:";
		cin >> e.ln;
		cout << endl << "Pay rate: ";
		cin >> e.rate;
		cout << endl << "Hours worked: ";
		cin >> e.hours;

		empvec.push_back(e);
	} while (DoAgain());
	
	// Print report to console of entered data along with the calculated gross pay
	double total = 0;

	for (int i = 0; i < empvec.size(); i++)
	{
		double gross;

		gross = empvec[i].hours * empvec[i].rate;
		cout << empvec[i].id << " " << empvec[i].fn << " " << empvec[i].ln << " - $" << gross << endl;

		total += gross;
	}

	// Print the total gross pay
	cout << "Total gross pay is $" << total;

	_getch();
	return 0;
}