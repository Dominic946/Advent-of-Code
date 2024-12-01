#!/usr/bin/python3
with open('../inputs/day1.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

left_list = []
right_list = []
for i in input:
    left_list.append(int(i.split()[0]))
    right_list.append(int(i.split()[1]))

left_list.sort()
right_list.sort()

total = 0
for idx in range(len(input)):
    total += abs(left_list[idx] - right_list[idx])

print(f"Part 1 answer: {total}")

similarity = 0
for i in left_list:
    similarity += i * right_list.count(i)

print(f"Part 1 answer: {similarity}")
