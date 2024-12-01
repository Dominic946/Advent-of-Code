#!/usr/bin/python3
with open('../inputs/day6.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

t, d = input
while '  ' in t:
    t = t.replace('  ', ' ')
while '  ' in d:
    d = d.replace('  ', ' ')
t = t.split(': ')[1]
d = d.split(': ')[1]
t = t.split(' ')
d = d.split(' ')
t = [int(i) for i in t]
d = [int(i) for i in d]

print(t)
print(d)

total = 1
for r in range(len(t)):
    ways = 0
    for held in range(1,t[r]):
        dis = (t[r]-held)*held
        if dis > d[r]:
            ways += 1
    total *= ways

print(f"Part 1: {total}")

t = int(''.join([str(i) for i in t]))
d = int(''.join([str(i) for i in d]))

print(t)
print(d)

# Brute force round 2.
# Takes about 30 seconds to run, but it works
# There is definintely a faster way to do this
ways = 0
for held in range(1,t):
    dis = (t-held)*held
    if dis > d:
        ways += 1

print(f"Part 2: {ways}")





#
