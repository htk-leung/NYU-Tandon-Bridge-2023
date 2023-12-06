/*
FUNCTION 1: int printMonthCalender(int numOfDays, int startingDay)
1. print a formatted MONTHLY calendar of that month
2. return a number 1-7 that represents the day in the week of the LAST DAY in that month
3. include a header line with the day's names
4. columns spaced by a tab
5. given : numOfDays - number fo days in the month
            startingDay

FUNCTION 2: 
1. determine if a year is a leap year
2. return true of it is

FUNCTION 3: void printYearCalender(int year, int startingDay)
1. use func 1 & 2 to print a formatted YEARLY calendar of that year

*/

#include <iostream>
#include <string>
using namespace std;

int printMonthCalender(int, int);
bool isLeapYear(int);
void printYearCalender(int, int);

int main()
{
    int year, startingDay;
    
    cout << "Please enter the year and starting day of the calendar, each separated by space.\n"
        << "For instance, for year 2016 starting on Thursday, type 2016 4 :\n";
    cin >> year >> startingDay;
    
    printYearCalender(year, startingDay);
    return 0;
}


bool isLeapYear(int yr) {
    bool notDiv4 = yr % 4;
    bool notDiv100 = yr % 100;
    bool notDiv400 = yr % 400;

    if ((!notDiv4 && notDiv100) || !notDiv400)
        return true;

    return false;
}

void printYearCalender(int year, int startingDay) {
    int numOfDays;
    string month;

    for (int mon = 1; mon <= 12; mon++) {                   // loop through each month
        switch(mon) {                                       // month name, #days
            case 1: numOfDays = 31;
                month = "January"; 
                break;
            case 2: 
                if (isLeapYear(year)) numOfDays = 29; // CONST
                else numOfDays = 28;
                month = "February";
                break;
            case 3: numOfDays = 31; // CONST
                month = "March";
                break;
            case 4: numOfDays = 30;
                month = "April";
                break;
            case 5: numOfDays = 31;
                month = "May";
                break;
            case 6: numOfDays = 30;
                month = "June";
                break;
            case 7: numOfDays = 31;
                month = "July";
                break;
            case 8: numOfDays = 31;
                month = "August";
                break;
            case 9: numOfDays = 30;
                month = "September";
                break;
            case 10: numOfDays = 31;
                month = "October";
                break;
            case 11: numOfDays = 30;
                month = "November";
                break;
            case 12: numOfDays = 31;
                month = "December";
                break;
        }
        cout << '\n' << month << ' ' << year << endl;
        startingDay = printMonthCalender(numOfDays, startingDay) + 1; 
        if (startingDay == 8)                               // update next month's info
            startingDay -= 7;
    }
}

int printMonthCalender(int numOfDays, int startingDay) {
                                                            // call isLeapYear for Feb
    int day = 1;
    int dayOfWeek = 1;
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun\n";
    if (day == 1) {                                         // first few empty dates
        for (int space = 1; space < startingDay; space++)   // dayofweek = 7
            cout << '\t';
        cout << day << '\t';
        dayOfWeek += startingDay;                           // dayofweek = 1 + 7 = 8                      
        day++;
    }
    while (1 < day && day <= numOfDays) {
        if (dayOfWeek > 7) {                                // 8 - 7 = 1
            cout << endl;                                   // skip a line start fresh
            dayOfWeek -= 7;
        }
        cout << day << '\t';                                // starting on 4
        if (day == numOfDays) {
            cout << endl;
            return dayOfWeek;
        }
        dayOfWeek++;                                        // next day
        day++;
    }
    return 1;
}