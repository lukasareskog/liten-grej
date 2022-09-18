#include <iostream>
#include "clock.h"

using namespace std;

int main()
{
	Clock clock1;     // making a new Clock object, called clock1

	// call whatever u want here
	int a, b, c;
	int medirian;
	cout << "Is it AM or PM? (am = 0, pm = 1)  : ";
	cin >> medirian;

	cout << "Enter hours, minutes and seconds in standard time (h:mm:ss): ";
	cin >> a >> b >> c;
	clock1.setClock(medirian, a, b, c);


	string timeStandard = clock1.displayStandard();
	cout << "Standard time: " << timeStandard << endl;

	string timeMilitary = clock1.displayMilitary();
	cout << "Military time: " << timeMilitary << endl;
}