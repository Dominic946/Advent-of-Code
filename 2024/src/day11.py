#!/usr/bin/python3
with open('../inputs/day11.txt', 'r') as file:
    input = file.readlines()
    input = [int(i.strip()) for i in input[0].split()]

memory = dict()
def split(rock, remaining_blinks):
    if remaining_blinks == 0:
        return 1
    if (rock, remaining_blinks) not in memory:
        num_length = len(str(rock))
        if rock == 0:
            total_rocks = split(1, remaining_blinks - 1)
        elif num_length % 2 == 0:
            total_rocks = split(int(str(rock)[:num_length // 2]), remaining_blinks - 1) + split(int(str(rock)[num_length // 2:]), remaining_blinks - 1)
        else:
            total_rocks = split(rock * 2024, remaining_blinks - 1)
        memory[(rock, remaining_blinks)] = total_rocks
    return memory[(rock, remaining_blinks)]


print(f"Part 1 answer: {sum([split(i, 25) for i in input])}")
print(f"Part 2 answer: {sum([split(i, 75) for i in input])}")
