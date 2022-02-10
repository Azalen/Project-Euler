#include <iostream>
#include <iomanip>

using namespace std;

/**
 *      1900 was no leap year -> 365 days
 *          01.01.1900 was a monday
 *      365 % 7 = 1 
 *      =>  01.0.1.1901 was a tuesday
 * */

const int daysPerMonth[12] = {
    31,28,31,30,31,30,31,31,30,31,30,31
};

int countSundays(int startIndex, bool isLeapYear){
    int count = 0;
    for(int i=0; i<12; i++){
        if(startIndex % 7 == 0){
            count++;
        }
        startIndex += daysPerMonth[i];
        if(isLeapYear && i==1)
            startIndex++;
    }
    return count;
}

int main(){
    
    int startYear = 1901;
    int startYearIndex = 2;         // First day of the century
    int totalCountSundays = 0;
    bool leapYear = false;
    

    for(int i = 0; i<100; i++){
        int year = startYear + i;
        leapYear = false;
        if(year % 4 == 0){
            leapYear = true;
        }
        if(year % 100 == 0){
            leapYear = false;
        }
        if(year % 400 == 0){
            leapYear = true;
        }
        int temp = countSundays(startYearIndex, leapYear);
        totalCountSundays += temp;
        startYearIndex += 365;
        if(leapYear)
            startYearIndex++;
        startYearIndex = startYearIndex % 7;

        cout << year << " | leapYear = " << boolalpha << setw(5) << leapYear << " | countSundays = " << temp << endl; 
    }

    cout << endl << "Total Count Sundays = " << totalCountSundays << endl;

    return 0;
}