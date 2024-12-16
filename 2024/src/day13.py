#!/usr/bin/python3
with open('../inputs/day13.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

p2 = 10000000000000

def calculate(a, b, prize):
    for num_b in range(1000000000000):
        if num_b * b[0] > prize[0]:
            return 0
        if (prize[0] - (b[0] * num_b)) % a[0] == 0:
            num_a = (prize[0] - b[0] * num_b) // a[0]
            if prize[1] == num_b * b[1] + num_a * a[1]:
                return 3 * num_a + num_b
    return 0

total = 0
total2 = 0
for i in range(0,len(input), 4):
    print(i)
    A = (int(input[i].split('+')[1].split(',')[0]), int(input[i].split('+')[2]))
    B = (int(input[i+1].split('+')[1].split(',')[0]), int(input[i+1].split('+')[2]))
    prize = (int(input[i+2].split('=')[1].split(',')[0]), int(input[i+2].split('=')[2]))
    #total += calculate(A, B, prize)
    total2 += calculate(A, B, (prize[0] + p2, prize[1] + p2))

print(f"Part 1 answer: {total}")
print(f"Part 2 answer: {total2}")
