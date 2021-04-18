#!/usr/bin/python3

import Goldbach
import time

max_num = int(input("Enter max num >> "))

conjecture = Goldbach.Conjecture(0, max_num)
start = time.time()
conjecture.run()
end = time.time()
print(f"Finished in {round(end - start, 3)} seconds.")
