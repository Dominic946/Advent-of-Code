#!/usr/bin/python3
with open('../inputs/day4.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

dirs = [[1,0], [1,1], [0,1], [-1,1], [-1,0], [-1,-1], [0,-1], [1,-1]]

height = len(input)
width = len(input[0])

# Oops, this code ended up kinda messy, but at least it works :)

total = 0
for col in range(height):
    for row in range(width):
        if input[col][row] == 'X':
            for d in dirs:
                good = True
                for n, letter in enumerate(['M', 'A', 'S']):
                    if good:
                        y = col + d[0]*(n+1)
                        x = row + d[1]*(n+1)
                        if 0 <= y < height and 0 <= x < width:
                            if input[y][x] != letter:
                                good = False
                        else:
                            good = False
                if good:
                    total += 1

print(f"Part 1 answer: {total}")


dirs2 = [[1,1], [-1,1], [-1,-1], [1,-1]]
part2 = 0
for col in range(height):
    for row in range(width):
        if input[col][row] == 'A':
            good = 0
            for d in dirs2:
                for i, n in enumerate([1, -1]):
                    y = col + d[0]*n
                    x = row + d[1]*n
                    if 0 <= y < height and 0 <= x < width:
                        if input[y][x] == "MS"[i]:
                            good += 1
                if good % 2 == 1:
                    good = 0
            if good == 4:
                part2 += 1

print(f"Part 2 answer: {part2}")
