#!/usr/bin/python3
import subprocess
import random

# Generate a list of 100 numbers
numbers = list(range(0, 100))

# Shuffle the numbers to get a random permutation
random.shuffle(numbers)

# Convert the numbers to a string
numbers_str = ' '.join(map(str, numbers))

# Execute the command with the random numbers
# print(numbers_str)
arg_command = f'ARG="{numbers_str}";'
command = f'{arg_command} ./push_swap $ARG | ./checker $ARG'
subprocess.run(command, shell=True)