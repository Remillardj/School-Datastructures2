//
//  Time.cpp
//  Homework6
//
//  Created by Jaryd Remillard on 2/23/17.
//

#include <iostream>
#include <time.h>
#include <sstream>
#include <iomanip>
#include <string>

#include "Time.h"

using namespace std;

/*
 create the default Time() object by setting the values of
 hour, minute, second to the system time
*/
Time::Time()
{
    time_t now;
    struct tm tstruct;
    
    time(&now);
    tstruct = *localtime(&now);
    
    hour = tstruct.tm_hour;
    minute = tstruct.tm_min;
    second = tstruct.tm_sec;
}

/*
 use user inputted values for the respective time slot
 and by default, increment into the respective places.
 if the input is set to 0, then use the system time in place of that.
 for example: user inputs -1 for int h. It will replace hour
 with whatever time it is, for example, 7am, so 7.
 The purpose of this is to prevent users from inputting an invalid clock number
*/
Time::Time(int h, int m, int s)
{
    if ((h >= 0) && (m >= 0) && (s >= 0)) {
        incrementSeconds(s);
        incrementMinutes(m);
        incrementHours(h);
    }
    
    time_t now;
    struct tm tstruct;
    
    time(&now);
    tstruct = *localtime(&now);
    
    if (h < 0)
        hour = tstruct.tm_hour;
    if (m < 0)
        minute = tstruct.tm_min;
    if (s < 0)
        second = tstruct.tm_sec;
}

int Time::getHours() const
{
    return hour;
}

int Time::getMinutes() const
{
    return minute;
}

int Time::getSeconds() const
{
    return second;
}

// Set hour to user defined preference, and roll over if exceeding 24 hours.
void Time::setHours(int n)
{
    if (n >= 0) {
        hour = n;
        if (hour > 23) {
            hour = hour % 24;
        }
    } else {
        cout << "Can't set hour to less than 0. Setting to 0" << endl;
        hour = 0;
    }
}

// set minute to user defined preference and roll over excess minutes if over 60
void Time::setMinutes(int n)
{
    if (n >= 0) {
        minute = n;
        if (minute >= 60) {
            int temp = minute / 60;
            minute = minute % 60;
            incrementHours(temp);
        }
    } else {
        cout << "Can't set minute to less than 0. Setting to 0." << endl;
        minute = 0;
    }
}

// set any amount of seconds from user inputted preference, and roll over excess
// to minutes and hours if necessary
void Time::setSeconds(int n)
{
    if (n >= 0) {
        second = n;
        if (second >= 60) {
            int temp = second / 60;
            incrementMinutes(temp);
            second = second % 60;
        }
    } else {
        cout << "Can't set second to less than 0. Setting to 0." << endl;
        second = 0;
    }
}

// add user inputted amount of hours to current set
// and properly roll over hours if it exceeds 23, by resetting it back to 0
// and add remaining hours
void Time::incrementHours(int n)
{
    if (n >= 0) {
        hour += n;
        if (hour > 23) {
            hour = hour % 24;
        }
    } else {
        cout << "Can't increment hours by less than zero." << endl;
    }
}

// increment the minutes by user inputted amount and roll over to hours if
// minute is exceeding total of 60 minutes.
void Time::incrementMinutes(int n)
{
    if (n >= 0) {
        minute += n;
        if (minute >= 60) {
            int temp = minute / 60;
            minute = minute % 60;
            incrementHours(temp);
        }
    } else {
        cout << "Can't increment minutes by less than zero." << endl;
    }
}

// increment the second by user inputted amount and roll over to minutes if
// second is equal too or exceeding total of 60 seconds.
void Time::incrementSeconds(int n)
{
    if (n >= 0) {
        second += n;
        if (second >= 60) {
            int temp = second / 60;
            incrementMinutes(temp);
            second = second % 60;
        }
    } else {
        cout << "Can't increment seconds by less than zero." << endl;
    }
}

string Time::get24HourFormat() const
{
    ostringstream oss;
    oss << setfill('0');
    
    oss << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
    
    return (oss.str());
}

string Time::get12HourAmPmFormat()
{
    ostringstream oss;
    string timeFrame = "PM";
    int temp = hour;
    
    if (temp > 11) {
        temp = temp - 12;
    } else {
        timeFrame = "AM";
    }
    
    if (temp == 0) {
        timeFrame = "AM";
        temp = 12;
    }

    oss << setfill('0');
    oss << setw(2) << temp << ":" << setw(2) << minute << ":" << setw(2) << second << " " << timeFrame;
    
    return (oss.str());
    
}






