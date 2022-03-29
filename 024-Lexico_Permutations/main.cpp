#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

const bool  DEBUG   = false;

int fakulaet(int n){
    if(n == 1){
        return 1;
    }
    if(n == 0){
        return 1;
    }
    return fakulaet(n-1) * n;
}

int main(){
    
    // ANZAHL ALLER PERMUTATIONEN FÜR N STELLEN = n!
    int n = 10;

    // GESUCHTE PERMUTATION
    // 0123456789 IST NULLTE-PERMUTATION
    int pos = 1000000-1;
    
    // AUSWÄHLBARE ZIFFERN FÜR AKTUELLE STELLE
    vector<int> leftToPick = {0,1,2,3,4,5,6,7,8,9};

    // STELLEN VON VORNE BERECHNEN i=0 IST ERSTE STELLE
    for(int i = 0; i<n; i++){

        // ZAHL DIE VORNE STEHT BEI (n-i) RESTLICHEN STELLEN
        int val = pos / fakulaet(n-i-1);


        // RESTLICHE ZU ERBRINGENDE ANZAHL PERMUTATIONEN NACH EINGETRAGENER STELLE i
        pos = pos - (val*fakulaet(n-i-1));

        // AUSWAHL DER ZIFFER FÜR GEFUNDENE STELLE 
        int trueVal = leftToPick[val];
        cout << trueVal;

        // IST EINE ZIFFER AUSGEWÄHLT, SO DARF SIE NICHT NOCHMALS VORKOMMEN
        //  WICHTIG: TRENNUNG EINZUSETZENDE ZIFFER <-> NOCH ZU ERBRINGENDE PERMUTATIONEN
        leftToPick.erase(leftToPick.begin()+val);
    }
    cout << endl;

    return 0;
}