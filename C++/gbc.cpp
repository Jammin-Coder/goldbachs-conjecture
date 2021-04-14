#include <iostream>
#include <stdlib.h>
#include "linkedLists.h"
#include "myFuncs.h"

using namespace std;


class Goldbach
{
private:
	Funcs custom; // My custom functions
	List m_primes; // List of prime numbers, empty at first.
	int m_low;
	int m_high;
	int m_lastPrime = 1;
	int m_nextRange = 100;
	
	void manage_primes()
	{
        if(m_primes.size() >= 500)
		{
            for(int i = 200; i < 300; i++)
            {
                m_primes.remell(i);
            }
        }
    }
     
     void find_primes()
     {
        cout << "Finding primes...\n";
        /*
        This method finds primes incrementally, only as they are needed.
        Otherwise when going to large numbers, the program will hang for about 
        17 years at startup.
        */
        for(long long i = m_lastPrime; i < m_nextRange; i+= 2)
        {
            if (custom.isPrime(i) == 1)
            {
                m_primes.append(i);
                manage_primes();
                m_lastPrime = i;  // Sets the last prime to i, so next time this loop runs, it remembers where it left off.
            }
        }
        m_nextRange += 100;  // Increments the max number to go to next time.
    }
    
    void calc()
    {
        cout << "Testing Goldbach's conjecture...\n";
        int works = 0;
        for(long long i = m_low; i < m_high; i += 2)
        {
            int do_break = 0;  // If this is true, then move on to the next even number
            if(i >= m_lastPrime)
            {
                // This allows the known calculated prime numbers to increment as needed,
                // so we aren't looking for tons of numbers at the start of the program.
                find_primes();
            }
			int primesLength = m_primes.size();
            for(int j = 0; j < primesLength; j++)
            {
                if(do_break == 1){break;}
                long long num1 = m_primes.index(j);
                
                for(int k = 0; k < primesLength; k++)
                {
                	long long num2 = m_primes.index(k);
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
	Goldbach(int low, long long high)
	{
		m_low = low;
		m_high = high;
	}
	
	void run(){calc();}
};



int main()
{
	Goldbach conjecture(0, 100000000000);
	
	conjecture.run();
		
	return 0;
}




