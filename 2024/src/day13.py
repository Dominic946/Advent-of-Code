#!/usr/bin/python3
with open('../inputs/day13.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

p2 = 10000000000000

def calculate(a, b, prize):
    x = (prize[0]/b[0] - prize[1]/b[1]) / (a[0]/b[0] - a[1]/b[1])
    y = prize[0]/b[0] - x * a[0]/b[0]
    if abs(x-round(x)) < 0.01 and abs(y-round(y)) < 0.01:
        return round(3*x + y)

    return 0

total = 0
total2 = 0
for i in range(0,len(input), 4):
    A = (int(input[i].split('+')[1].split(',')[0]), int(input[i].split('+')[2]))
    B = (int(input[i+1].split('+')[1].split(',')[0]), int(input[i+1].split('+')[2]))
    prize = (int(input[i+2].split('=')[1].split(',')[0]), int(input[i+2].split('=')[2]))
    total += calculate(A, B, prize)
    total2 += calculate(A, B, (prize[0] + p2, prize[1] + p2))

print(f"Part 1 answer: {total}")
print(f"Part 2 answer: {total2}")

"""
Notes
x * a[0] + y * b[0] == prize[0]
x * a[1] + y * b[1] == prize[1]
Two equations and two variables x and y, the rest are constants

Rearrange both equations to get y by itself
y == prize[0]/b[0] - x * a[0]/b[0]
y == prize[1]/b[1] - x * a[1]/b[1]

Set the equations equal to each other and simplify
prize[0]/b[0] - x * a[0]/b[0] == prize[1]/b[1] - x * a[1]/b[1]

prize[0]/b[0] - prize[1]/b[1] == x * a[0]/b[0] - x * a[1]/b[1]

prize[0]/b[0] - prize[1]/b[1] == x * (a[0]/b[0] - a[1]/b[1])

x = (prize[0]/b[0] - prize[1]/b[1]) / (a[0]/b[0] - a[1]/b[1])
y = prize[0]/b[0] - x * a[0]/b[0]
"""