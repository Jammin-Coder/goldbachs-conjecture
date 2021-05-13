#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


class Funcs
{
public:
    template<typename T>
	int numLen(T num)
	{
		return to_string(num).length(); // returns the digit count of num
	}
	
	template<typename T>
	int isPrime(T num)
	{
		int divCount = 0;
		int trys = 50;
		if (num % 2 == 0){return 0;}
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



