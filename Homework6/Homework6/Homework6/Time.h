//
//  Time.h
//  Homework6
//
//  Created by Jaryd Remillard on 2/23/17.
//

#include <string>
using namespace std;

/*
 Time is a class object that can create a clock that essentially can be modified
 from user inputs, or initiated by the systems clock timer.
*/
class Time {
public:
    Time(); //create object
    // create construct for user input
    // if any of user input is a negative, then by default
    // it will use the system time instead
    Time(const int h, const int m, const int s);
    
    // initiate getter and setter for the hours modifier
    // setHours() requires an integer input, and getHours()
    // returns an integer
    int getHours() const;
    void setHours(int n);
    
    // initiate getter and setter for minutes modifier
    // setMinutes() requires an integer input, and getMinutes()
    // returns an integer
    int getMinutes() const;
    void setMinutes(int n);
    
    // initiate getter and setter for seconds modifier
    // getSeconds() requires an integer input, and getSeconds()
    // returns an integer
    int getSeconds() const;
    void setSeconds(int n);
    
    /*
     increment the respective values by a number that the user inputs
     and roll over remaining amount into the next section.
     for example; inputting 75 into incrementHours(75), will add to the clock
     1 minute and 15 seconds.
    */
    void incrementSeconds(int n);
    void incrementMinutes(int n);
    void incrementHours(int n);
    
    // default value is 24 hour format
    // convert integers into a 24 hour clock
    string get24HourFormat() const;
    // convert the 24 hour fomrat to a 12 hour format
    // and uses logic to output correct AM or PM format
    string get12HourAmPmFormat();
    
private:
    int hour;
    int minute;
    int second;
};
