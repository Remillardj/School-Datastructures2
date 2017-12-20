//
//  main.cpp
//  Homework6
//
//  Created by Jaryd Remillard on 2/23/17.
//

#include <iostream>
#include "Time.h"

void testoutputformats(Time &t);

int main()
{
    Time alarmTime(22, 50, 30);
    
    string alarmString;
    
    alarmString = alarmTime.get24HourFormat();
    cout << alarmString << endl; //22:50:30 24hr
    
    alarmString = alarmTime.get12HourAmPmFormat();
    cout << alarmString << endl; // 10:50:30 PM 12hr
    
    alarmTime.incrementSeconds(45);
    testoutputformats(alarmTime); // 10:51:15 PM
    
    alarmTime.incrementSeconds(200);
    testoutputformats(alarmTime); // 10:54:35 PM
    
    alarmTime.incrementMinutes(63);
    testoutputformats(alarmTime); // 11:57:35 PM
    
    alarmTime.incrementHours(24);
    testoutputformats(alarmTime); // 11:57:35 PM
    
    alarmTime.incrementHours(49);
    testoutputformats(alarmTime);
    
    alarmTime = Time(6, 30, 0);
    testoutputformats(alarmTime);
    
    alarmTime = Time(18, 30, 0);
    testoutputformats(alarmTime);
    
    alarmTime.setHours(2);
    testoutputformats(alarmTime);
    
    alarmTime.setMinutes(5);
    testoutputformats(alarmTime);
    
    alarmTime.setSeconds(65);
    testoutputformats(alarmTime);
    
    alarmTime.setSeconds(7261);
    testoutputformats(alarmTime);
    
    alarmTime.incrementMinutes(-1);
    testoutputformats(alarmTime);
    
    Time myAppt(15, 0, 0);
    testoutputformats(myAppt);
    cout << myAppt.getHours() << endl;
    
    Time rightNow;
    testoutputformats(rightNow);
    
    Time testTime(-15, 0, 0);
    testoutputformats(testTime);
    
    return 0;
}

/*
 automate process of printing out both 24 hour formats and 12 hour AM/PM format
*/
void testoutputformats(Time &t)
{
    string tmpString;
    
    tmpString = t.get24HourFormat();
    cout << tmpString << endl;
    
    tmpString = t.get12HourAmPmFormat();
    cout << tmpString << endl;
}
