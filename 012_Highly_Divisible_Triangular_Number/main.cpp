#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

const bool DEBUG = false;

int amountDivisors(long num)
{
    // Default Divisors 1 and num arent checked
    int divisors = 2;

    /**
     *      ACHTUNG: Divisors come in pairs -> you only have to check up to the root value of num 
     *                  -> always add +2 if you find a divisor <= root
     *                  -> if root = divisor only count it once
     *          
     *          => RUNTIME O(sqrt(n))
     * 
     * */

    long root = sqrt(num);
    for (int i = 2; i < root; i++)
    {
        if (num % i == 0)
            divisors += 2;
    }
    if (num % root == 0)
        divisors++;
    return divisors;
}

int main()
{
    int n = 500;
    // second triangle number
    long i = 3;
    long triangleDif = 3;

    while (i < LONG_MAX)
    {

        int div = -1;
        div = amountDivisors(i);

        if (DEBUG)
            cout << i << " -> " << div << endl;

        if (div > n)
            break;
        i += triangleDif++;
    }

    cout << "Die erste Triangular-Zahl mit mehr als " << n << " Teilern = " << i << endl;

    return 0;
}