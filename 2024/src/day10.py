#!/usr/bin/python3
with open('../inputs/day10.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

height = len(input)
width = len(input[0])

# Easy part 2 today, literally the only difference between part 1 and 2
# is storing my results in a set vs a list to include/remove duplicate paths
part1 = set()
part2 = []
# Basic recursive dfs, count the number of times we reach 9 by storing them in a set/list
def ascend(y, x, origin):
    if int(input[y][x]) == 9:
        part1.add((origin, (y, x)))
        part2.append((origin, (y, x)))
    for dy, dx in [(0,1), (0,-1), (1,0), (-1,0)]:
        if 0 <= (x + dx) < width and 0 <= (y + dy) < height:
            if int(input[y + dy][x + dx]) == int(input[y][x]) + 1:
                ascend(y + dy, x + dx, origin)

for y, row in enumerate(input):
    for x, elevation in enumerate(row):
        if int(elevation) == 0:
            ascend(y, x, (y, x))

print(f"Part 1 answer: {len(part1)}")
print(f"Part 2 answer: {len(part2)}")
