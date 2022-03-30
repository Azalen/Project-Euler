#include <iostream>
#include <cmath>

using namespace std;

int evenFibonacci(int size){
    
    // Summe startend bei Null
    int sum = 0;

    // Ersten Zwei Fibonacci-Zahlen
    int i = 1;
    int j = 1;
    int temp;

    // aktuelle Fibonacci-Zahl ist kleiner als die angegebene Größe
    while(i <= size){
        // Eine Iteration nach oben Laufen
        temp = i;
        i = i+j;
        j = temp;
        if(i % 2 == 0)
            sum += i;
    }
    return sum;
}

int main(){
    int SIZE = 4*pow(10,6);
    cout << "Summe aller geraden Fibonacci-Zahlen bis " << SIZE << " = " << evenFibonacci(SIZE) << endl;
}