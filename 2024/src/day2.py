#!/usr/bin/python3
with open('../inputs/day2.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

def attempt(lst):
    # The inc veriable tells if this report is increasing (inc = True) or decreasing (inc = False)
    if lst[1] > lst[0]:
        inc = True
    elif lst[1] < lst[0]:
        inc = False
    else:
        return False

    good = True
    for n in range(len(lst) - 1):
        # If any step is greater than 3, or is going in the opposite direction from expected, that's not good.
        if inc:
            if lst[n+1] - lst[n] > 3 or lst[n+1] <= lst[n]:
                good = False
        else:
            if lst[n] - lst[n+1] > 3 or lst[n] <= lst[n+1]:
                good = False
    return good

# Part 1, simply count the number of good rows
safe = 0
for i in input:
    nums = [int(n) for n in i.split()]
    safe += attempt(nums)

print(f"Part 1 answer: {safe}")

# Part 2, try removing one item from each report
total = 0
for i in input:
    nums = [int(n) for n in i.split()]
    found = False
    # Brute force, attempt removing each index of each report and see if it is safe
    for remove in range(len(nums)):
        if not found and attempt(nums[0:remove] + nums[remove+1:]):
            total += 1
            found = True

print(f"Part 2 answer: {total}")
