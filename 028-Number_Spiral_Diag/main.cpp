#include <iostream>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int main(){
    
    int n = 1001;

    int rings = n/2;
    int curRing = 0;
    int inRingCounter = 0;

    unsigned long long diagSum = 1;

    for(int i = 3; curRing < rings; i = i + (2*(curRing+1))){
        inRingCounter++;
        diagSum = diagSum + i;
        if(DEBUG)
            cout << i << " ";

        if(inRingCounter == 4){
            if(DEBUG)
                cout << endl;
            curRing++;
            inRingCounter = 0;
        }
    }

    

    cout << diagSum << endl;

    return 0;
}