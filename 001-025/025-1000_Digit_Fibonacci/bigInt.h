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

        void multN(int n){
            int curOverhead = 0;

            for(int i=(s.size()-1); i>=0; i--){
                char c = s[i];
                int temp = (int)c - 48;
                temp = (temp * n) + curOverhead;
                curOverhead = temp / 10;
                temp = temp % 10;
                char b = temp + 48;
                s[i] = b; 
            }
        }

        void addBigInt(const BigInt & toAdd){

            int curOverhead = 0;

            for(int i=(s.size()-1); i>=0; i--){

                // OWN BIG INT
                char c = s[i];
                int cn = (int)c - 48;

                // PASSED BIG INT
                char t = toAdd.getDigit(i);
                int tn = (int)t - 48;

                cn = cn + tn + curOverhead;
                
                curOverhead = cn / 10;
                cn = cn % 10;
                char b = cn + 48;
                s[i] = b; 
            }
        }

        char getDigit(int index) const {
            return s[index];
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

        bool checkDigit(int digit){
            if(s[s.size()-digit] == '0'){
                return false;
            }
                
            return true;
        }

        void assign(const BigInt & toAssign){

            for(unsigned int i=0; i<s.size(); i++){
                s[i] = toAssign.getDigit(i);
            }
        }

};