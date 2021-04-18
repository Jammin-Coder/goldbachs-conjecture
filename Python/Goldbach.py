#!/usr/bin/python3

"""
Goldbach's Conjecture testing, v1.0.
Made 4/9/2021 by JamminCoder.
"""


def write(path, content):
    with open(path, "w") as f:
        f.write(content)


def append(path, content):
    with open(path, "a") as f:
        f.write(content)


class Conjecture:
    def __init__(self, low, high):
        self.out = "conjecture.txt"
        write(self.out, "")
        self.low = low
        self.high = high
        self.primes = []
        self.last_prime = 1  # Keeps track of the last prime number found,
        self.next_range = 100  # Keeps track of the range of numbers to look for primes.

    def is_prime(self, num):
        num = str(num)
        # If a number ends with any of these, we can definitively say it's not prime
        common = "2, 4, 5, 6, 8, 0"
        if len(num) > 1:
            if num[-1] in common:
                return False

        num = int(num)
        max_div = 100  # The maximum number to try to divide num by. 100 is sufficient for calculating it.
        div_count = 0  # Number of divisors
        for i in range(1, num + 1):
            if div_count > 2 or i >= max_div:
                # If this is true, then we can make a decision, so stop the loop.
                break
            else:
                rem = num % i  # Remainder of num divided ny i
                if rem == 0:
                    # If rem = 0, then i divides evenly into num, so add 1 to total divisors.
                    div_count += 1

        # Returns true if divisors count is <= 2 (num is prime), otherwise return false.
        if div_count <= 2:
            return True
        else:
            return False

    # This method manages the amount of prime numbers stored in the self.primes list
    # never exceeds 500
    def manage_primes(self):
        if len(self.primes) >= 100:
            for i in range(50, 75):
                self.primes.pop(i)

    def find_primes(self):
        print("Finding primes...")
        """
        This method finds primes incrementally, only as they are needed.
        Otherwise when going to large numbers, the program will hang for about 
        17 years at startup.
        """
        for i in range(self.last_prime, self.next_range):
            if self.is_prime(i):
                self.primes.append(i)
                self.manage_primes()
                self.last_prime = i  # Sets the last prime to i, so next time this loop runs, it remembers where it left off.
        self.next_range += 100  # Increments the max number to go to next time.

    def calc(self):
        print("Testing Goldbach's conjecture...")
        works = False
        for i in range(self.low, self.high, 2):
            do_break = False  # If this is true, then move on to the next even number
            if i >= self.last_prime:
                # This allows the known calculated prime numbers to increment as needed,
                # so we aren't looking for tons of numbers at the start of the program.
                self.find_primes()

            for num in self.primes:
                if do_break:
                    break
                for num2 in self.primes:
                    if num + num2 == i:
                        print(f"{num} + {num2} = {i}")
                        do_break = True  # Found 2 prime numbers that add up to i, move to the next one.
                        works = True
                        break

        # Should only run if the conjecture fails.
        if not works:
            print("The conjecture has failed...")
            exit()

    def run(self):
        self.find_primes()
        self.calc()
