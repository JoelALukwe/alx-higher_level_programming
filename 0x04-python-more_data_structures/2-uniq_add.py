#!/usr/bin/python3

def uniq_add(my_list=[]):
    return sum(set(my_list))

# Test the function
my_list = [1, 2, 3, 1, 4, 2, 5]
result = uniq_add(my_list)
print("Result: {:d}".format(result))

