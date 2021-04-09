#!/usr/bin/python3

import Goldbach


max_num = int(input("Enter the maximum number to go calculate to >> "))

conjecture = Goldbach.Conjecture(0, max_num)
conjecture.run()
