#!/usr/bin/python3

import time
import subprocess

file = "gbc"

start = time.time()
subprocess.call([f"./{file}"])
end = time.time()
print(f"Finished in {end - start}.")
