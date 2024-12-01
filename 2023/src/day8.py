#!/usr/bin/python3
with open('../inputs/day8.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

pattern = input[0]
dict = {}

for i in input[2:]:
    key, v = i.split(' = ')
    v = v.replace('(', '').replace(')', '').split(', ')
    dict[key] = v
'''
steps = 0
location = "AAA"
while location != "ZZZ":
    if pattern[steps % len(pattern)] == 'R':
        location = dict[location][1]
    else:
        location = dict[location][0]
    steps += 1

print(f"Part 1: {steps}")
'''
locations = []
for k in dict:
    if k[2] == "A":
        locations.append(k)

totals = []
for i in locations:
    steps = 0
    l = i
    while l[2] != 'Z':
        dir = 0
        if pattern[steps % len(pattern)] == 'R':
            dir = 1
        l = dict[l][dir]
        steps += 1
    totals.append(steps)

from math import gcd
lcm = 1
for i in totals:
    lcm = lcm*i//gcd(lcm, i)

print(f"Part 2: {lcm}")
