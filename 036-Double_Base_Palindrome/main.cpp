#include <iostream>
#include <ctime>
#include <string>
#include <bits/stdc++.h>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 1000000;

string makeBinary(int num){
    string bin = "";
    do{

        if(num % 2 == 0)
            bin = bin + "0";
        else
            bin = bin + "1";

        num /= 2;

    }while(num != 0);
    reverse(bin.begin(), bin.end());
    return bin;
}

int main(){
    
    long long amountUniqueComputations = 0;
    clock_t start = clock();
    
    int sum = 0;
    for(int i = 1; i<SIZE; i = i+2){
        
        string t = to_string(i);
        string r = t;
        reverse(r.begin(), r.end());
        if(r != t)
            continue;

        string bin = makeBinary(i);
        string rev = bin;
        reverse(rev.begin(), rev.end());
        if(rev != bin)
            continue;

        sum += i;
        
    }
    cout << "sum of palindroms of base 2 and 10 = " << sum << endl;
    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}