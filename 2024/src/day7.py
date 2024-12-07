#!/usr/bin/python3
with open('../inputs/day7.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

# --------------------------------------------------------------
# lol this code is pretty messy and slow,
# but it worked for me first try so I can't complain
# I gotta go to sleep now but, maybe I'll clean this up tomorrow
# to make it more efficient and readable
# --------------------------------------------------------------

part1 = 0
for i in input:
    ans, nums = i.split(':')
    ans = int(ans)
    nums = [int(n) for n in nums.split()]
    
    # Brute force testing all permutations of + and *, like +*++ and +*** etc.
    num_ops = len(nums) - 1
    ops = ['+'] * num_ops
    for i in range(2**num_ops):
        total = nums[0]
        # For all the operations in this permutation, if it is + then add, else multiply
        for n in range(1, len(nums)):
            if ops[n-1] == '+':
                total += nums[n]
            else:
                total *= nums[n]
                
        # All operations are complete, break if we got the right answer
        if total == ans:
            part1 += ans
            break

        # This code sets up the next permutation of operations if didn't get the right answer
        # Initial ops is '++++', which becomes '*+++',
        # then '+*++', then '**++' then '++*+', '*+*+', and so on.
        for char in range(num_ops):
            if ops[char] == '+':
                ops[char] = '*'
                break
            else:
                ops[char] = '+'

print(f"Part 1 answer: {part1}")

part2 = 0
# Same exact code copied from part 1 solution, but I just added a new operation 'c'
for i in input:
    ans, nums = i.split(':')
    ans = int(ans)
    nums = [int(n) for n in nums.split()]
    
    num_ops = len(nums) - 1
    ops = ['+'] * num_ops
    for i in range(3**num_ops):
        total = nums[0]
        for n in range(1, len(nums)):
            if ops[n-1] == '+':
                total += nums[n]
            elif ops[n-1] == '*':
                total *= nums[n]
            # if the operation is 'c', do string concatenation and convert back to int
            elif ops[n-1] == 'c':
                total = int(str(total) + str(nums[n]))
                
        if total == ans:
            part2 += ans
            break

        # Very similar code to part 1 get the next permutation of operations, it just also
        # adds in the new 'c' operation into the mix.
        for char in range(num_ops):
            if ops[char] == '+':
                ops[char] = '*'
                break
            elif ops[char] == '*':
                ops[char] = 'c'
                break
            else:
                ops[char] = '+'

print(f"Part 2 answer: {part2}")
