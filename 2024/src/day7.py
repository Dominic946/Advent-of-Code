#!/usr/bin/python3
with open('../inputs/day7.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]


# Perfomrms the list of operations on the numbers.
# Returns boolean, True if the result equals the answer
def evaluate_equation(nums, ops, ans):
    total = nums[0]
    # Perform all the operations
    for n in range(1, len(nums)):
        match ops[n-1]:
            case '+':
                total += nums[n]
            case '*':
                total *= nums[n]
            case 'c':
                total = int(str(total) + str(nums[n]))
    # All operations are complete, return whether or not we got the right answer
    return total == ans


# This code sets up the next permutation of operations if didn't get the right answer
# Initial ops is '++++', which becomes '*+++',
# then '+*++', then '**++' then '++*+', '*+*+', and so on.
# Takes in one set of operations and returns the next permutation in that series
def next_permutation(ops, include_c = False):
    for char in range(len(ops)):
        if ops[char] == '+':
            ops[char] = '*'
            break
        elif include_c and ops[char] == '*':
            ops[char] = 'c'
            break
        else:
            ops[char] = '+'
    return ops


# Run the main code to parse input and brute force trying all permutations of operations on each line
def run_code(include_c = False):
    result = 0
    for i in input:
        ans, nums = i.split(':')
        ans = int(ans)
        nums = [int(n) for n in nums.split()]
        
        # Brute force testing all permutations of + and *, like *+++ and +*+* etc.
        num_ops = len(nums) - 1
        ops = ['+'] * num_ops
        for i in range((2 + include_c) ** num_ops):
            # Attempt the equations, break if we found a success
            if evaluate_equation(nums, ops, ans):
                result += ans
                break

            # Get the next permutation of operations if didn't get the right answer
            ops = next_permutation(ops, include_c)
    return result

print(f"Part 1 answer: {run_code()}")
print(f"Part 2 answer: {run_code(include_c = True)}")
