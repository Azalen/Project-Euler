#include <iostream>
#include <ctime>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int main(){
    
    clock_t start = clock();

    int totalCoinSum = 200;
    int coins[8] = {1,2,5,10,20,50,100,200};
    int anz = 0;

    for(int a=0; a<=totalCoinSum/coins[0]; a++){
        for(int b=0; b<=totalCoinSum/coins[1]; b++){
            for(int c=0; c<=totalCoinSum/coins[2]; c++){
                for(int d=0; d<=totalCoinSum/coins[3]; d++){
                    for(int e=0; e<=totalCoinSum/coins[4]; e++){
                        for(int f=0; f<=totalCoinSum/coins[5]; f++){
                            for(int g=0; g<=totalCoinSum/coins[6]; g++){
                                for(int h=0; h<=totalCoinSum/coins[7]; h++){
                                    
                                    if(a*coins[0] + b*coins[1] + c*coins[2] + d*coins[3] + e*coins[4] + f*coins[5] + g*coins[6] + h*coins[7] == 200){
                                        // korrekte Combo
                                        anz++;
                                    }

                                }
                            }
                        }
                    }
                }
            }   
        }
    }
    cout << "possibilities: " << anz << endl;

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    return 0;
}