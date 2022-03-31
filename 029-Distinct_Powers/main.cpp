#include <iostream>
#include <ctime>
#include <utility>
#include <set>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

void transformPair(pair<int, int> & toTransform){
    if(DEBUG)
        cout << "transformed " << toTransform.first << "^" << toTransform.second;
    for(int i=7; i>1; i--){
        double tempVal = pow(toTransform.first, 1.0/i);
        if(tempVal == (int)tempVal){
            toTransform.first = tempVal;
            toTransform.second = toTransform.second * i; 
        }
    }
    if(DEBUG)
        cout << " to " << toTransform.first << "^" << toTransform.second << endl;
}

int main(){
    
    clock_t start = clock();
    set<pair<int,int>> res;

    for(int basis = 2; basis <= 100; basis++){
        for(int exponent = 2; exponent <= 100; exponent++){
            pair<int,int> temp;
            temp.first = basis;
            temp.second = exponent;
            transformPair(temp);
            res.insert(temp);
        }
    }

    pair<int,int> temp;
    temp.first = 16;
    temp.second = 4;
    transformPair(temp);

    cout << "elements = " << res.size() << endl;

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    return 0;
}