#!/usr/bin/python3
with open('../inputs/day4.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

total = 0
'''
------
Part 1
------
for c in input:
    win, nums = c.replace('  ', ' ').split(' | ')
    win = win.split(': ')[1].split(' ')
    nums = nums.split(' ')
    matches = 0
    for n in nums:
        if n in win:
            print(n)
            matches += 1
    if matches > 0:
        total += 2**(matches - 1)
'''
copies = [1]*len(input)

for c in range(len(input)):
    win, nums = input[c].replace('  ', ' ').split(' | ')
    win = win.split(': ')[1].split(' ')
    nums = nums.split(' ')
    matches = 0
    for n in nums:
        if n in win:
            matches += 1
    if matches > 0:
        for i in range(matches):
            copies[c+i+1] += copies[c]

print(sum(copies))
