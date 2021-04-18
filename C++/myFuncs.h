#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


class Funcs
{
public:
	int numLen(long long num)
		{
			return to_string(num).length(); // returns the digit count of num
		}
		
	int getLastDigit(int num)
	{
		string strNum = to_string(num); // Converts num to string
		char lastNum = strNum[strNum.length()-1]; // Gets the last digit of strNum
		// Returns the ascii value of lastNum subtracted by 48, since ascii numbers start at 48. 
		// So if num = 112, the last num = 2, 2's ascii value is 50, 50 - 48 = 2, returns 2 as int.
		return lastNum - 48;
	}
		
	int isPrime(long long num)
	{
		int divCount = 0;
		int trys = 100;
		int commonDivs[] = {0, 2, 4, 6, 8}; // If the last digit of num = any of these, num is not prime
		if(numLen(num) > 1)
		{
			int lastDigit = getLastDigit(num);
			for(int commonDiv : commonDivs)
			{
				if(lastDigit == commonDiv)
				{
					return 0; // Num is not prime.
					break;
				}
			}
		}
		
		for(int i = 1; i < trys; i++)
		{
			if(divCount > 2)
			{
				return 0; // num is not prime
				break;
			} 
			else
			{
				int rem = num % i;
				if(rem == 0)
				{
					divCount++;
				}
			}
		}
			
		return 1; // Num is prime
	}
};



