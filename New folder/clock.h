#include <iostream>
#include <string>

using namespace std;

class Clock {
private:
    int hour;
    int minute;
    int second;
    bool medirian;
public:
    Clock();                                // standard Constructor
    ~Clock();                               // standard Destructor
    void setClock(int, int, int, int);      // sets the clock to 12 hour time (US-time)
    string displayStandard();
    string displayMilitary();
};

Clock::Clock()      // Constructor definition
{
    hour = 0;
    minute = 0;
    second = 0;
}

Clock::~Clock()     // Destructor definition
{
}

void Clock::setClock(int medirianCheck, int h, int m, int s)
{
    if (medirianCheck == 0 || 1)
    {
        if (h >= 1 && h <= 12 && m >= 0 && m <= 59 && s >= 0 && s <= 59)
        {
            hour = h;
            minute = m;
            second = s;
            if (medirianCheck == 1)
            {
                medirian = true;
            }
        }
        else
        {
            cout << "Invalid format of time";
        }
    }
	else
	{
		cout << "Invalid format of time";
	}

}

string Clock::displayStandard()
{
    string time;
    string h;
    string m;
    string s;

    h = to_string(hour);

    if (minute < 10)
    {
        m = "0" + to_string(minute);
    }
    else
    {
        m = to_string(minute);
    }

    if (second < 10)
    {
        s = "0" + to_string(second);
    }
    else
    {
        s = to_string(second);
    }

    if (medirian == true)
    {
        time = h + ":" + m + ":" + s + " PM";
    }
    else
    {
        time = h + ":" + m + ":" + s + " AM";
    }
	return time;
}

string Clock::displayMilitary()  // time = https://www.ontheclock.com/convert-military-24-hour-time.aspx
{
    string time;

    string h;
    string m;
    string s;

    if (hour < 10)
    {
        h = "0" + to_string(hour);
    }
    else
    {
        h = to_string(hour);
    }

    if (minute < 10)
    {
        m = "0" + to_string(minute);
    }
    else
    {
        m = to_string(minute);
    }

    if (second < 10)
    {
        s = "0" + to_string(second);
    }
    else
    {
        s = to_string(second);
    }
		
    time = h + ":" + m + ":" + s;

    if (medirian == true) // if it is PM
    {
        int h = stoi(time.substr(0, 2));
        h = h + 12;
        time = to_string(h) + time.substr(2, 6);
    }

    return time;

}

