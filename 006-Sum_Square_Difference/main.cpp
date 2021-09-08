#include <iostream>
#include <cmath>

using namespace std;

const bool DEBUG = false;

long sumOfSquares(int size){
    long sum = 0;
    for(int i=1; i<= size; i++){
        sum += (i*i);
    }
    return sum;
}

long squareOfSum(int size){
    long sum = 0;
    for(int i=1; i<= size; i++){
        sum += i;
    }
    return (sum*sum);
}

long difference(int size){
    return abs(sumOfSquares(size)-squareOfSum(size));
}

int main(){

    int SIZE = 100;

    cout << "Die Differenz zwischen SumOfSquare und SquareOfSum der ersten " << SIZE << " Integer-Nummern ist " << difference(SIZE) << endl;
    return 1;
}