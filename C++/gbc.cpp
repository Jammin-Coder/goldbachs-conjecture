#include <iostream>
#include <stdlib.h>
#include "myFuncs.h"

using namespace std;


class Goldbach
{
private:
	Funcs custom; // My custom functions
	unsigned long long m_primes[100] = {0};
	int m_primesSize = 0;
	int m_low;
	int m_high;
	int m_lastPrime = 1;
	int m_nextRange = 100;

	// Keeps m_primes array size under 101
	void manage_primes()
	{
        if(m_primesSize >= 100)
		{
            for(int i = 50; i <= 75; i++)
            {
                m_primes[i] = 0;

            }
            m_primesSize = 75;
        }
    }
     
     void findPrimes()
     {
        cout << "Finding primes...\n";
        /*
        This method finds primes incrementally, only as they are needed.
        Otherwise when going to large numbers, the program will hang for about 
        17 years at startup. Plus the m_primes array can be kept under 101 in length
        */
        for(unsigned long long i = m_lastPrime; i < m_nextRange; i+= 2)
        {
            if (custom.isPrime(i) == 1 && i != 0)
            {
                manage_primes();
                m_primes[m_primesSize] = i;
                m_primesSize++;
                m_lastPrime = i;  // Sets the last prime to i, so next time this loop runs, it remembers where it left off.
            }
        }
        m_nextRange += 100;  // Increments the max number to go to next time.
    }
    
    void calc()
    {
        cout << "Testing Goldbach's conjecture...\n";
        int works = 0;
        for(unsigned long long i = m_low; i < m_high; i += 2)
        {
            int do_break = 0;  // If this is true, then move on to the next even number
            if(i >= m_lastPrime)
            {
                findPrimes(); // Refer to
            }
            for(int j = 0; j < m_primesSize; j++)
            {
                if(do_break == 1){break;}
                unsigned long long num1 = m_primes[j];

                if(num1 == 0){break;}

                for(int k = 0; k < m_primesSize; k++)
                {
                	unsigned long long num2 = m_primes[k];
                    if (num1 + num2 == i)
                    {
                        cout << num1 << " + " << num2 << " = " << i << endl;
                        do_break = 1;  // Found 2 prime numbers that add up to i, move to the next one.
                        works = 1;
                        break;
                    }
                }
            }
        }

        // Should only run if the conjecture fails.
        if(works == 0)
        {
            cout << "The conjecture has failed...\n";
            exit(0);
        }
    }

public:
	// Initializer.
	Goldbach(int low, unsigned long long high)
	{
		m_low = low;
		m_high = high;
	}
	
	void run(){calc();}
};



int main()
{
	/*int maxNum;
	cout << "Enter maximum num >> ";
	cin >> maxNum;
	if(maxNum > 100000000000000)
	{
		cout << "The program may not be able to deal with such a large number.\n";
		exit(1);
	}
	*/
	
	Goldbach conjecture(0, 10000000);
	
	conjecture.run();
		
	return 0;
}




