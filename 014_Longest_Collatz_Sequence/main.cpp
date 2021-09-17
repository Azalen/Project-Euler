#include <iostream>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = pow(10,6);

unsigned int collatzSequence(unsigned int n){
    unsigned int count = 1;
    while(n > 1){
        if(n % 2 == 0){
            n /= 2;
        }
        else{
            n = 3*n + 1;
        }
        count++;
    }
    return count;
}

int main(){

    int longestChain = 1;
    int num;
    for(int i=0; i<SIZE; i++){
        int currentChain = collatzSequence(i);
        if(currentChain > longestChain){
            longestChain = currentChain;
            num = i;
        }
            
    }

    cout << "Die längste Collatz-Sequenz bis " << SIZE << " ist " << num << " mit Laenge " << longestChain << endl;

    return 0;
}