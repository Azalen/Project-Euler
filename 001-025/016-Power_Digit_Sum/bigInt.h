#include <iostream>
#include <string>

using namespace std;

class BigInt{

    private:
        string s;

    public:
        BigInt(int n) : s(n, '0') {
            s[s.size()-1]='1';
        }

        void mult2(){

            int curOverhead = 0;

            for(int i=(s.size()-1); i>=0; i--){
                char c = s[i];
                int temp = (int)c - 48;
                temp = (temp * 2) + curOverhead;
                curOverhead = temp / 10;
                temp = temp % 10;
                char b = temp + 48;
                s[i] = b; 
            }
        }

        void print(){
            cout << s << endl;
        }

        int addDigits(){
            int sum = 0;
            for(unsigned int i=0; i<s.size(); i++){
                char c = s[i];
                int temp = (int)c - 48;
                sum += temp;
            }
            return sum;
        }

};