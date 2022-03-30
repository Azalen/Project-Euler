#include <iostream>
#include <ctime>

using namespace std;

int listMultiplesOfThreeAndFive(int uppBound){
    int sum=0;
    for(int i=0; i<uppBound; i=i+3)
        sum += i;
    for(int i=0; i<uppBound; i=i+5)
        sum+= i;
    for(int i=0; i<uppBound; i=i+15)
        sum-= i;
    
    return sum;
}

int main(){

    int SIZE = 1000;

    int start = clock();
    cout << "Summe aller Vielfachen von 3 und 5 bis " << SIZE << " = " << listMultiplesOfThreeAndFive(SIZE) << endl;
    int end = clock();
    int timeUsed = end-start;
    cout << "Time Used = " << timeUsed << " CPU ticks (" << (double(timeUsed)/CLOCKS_PER_SEC*1000) << "ms)" << endl;

}