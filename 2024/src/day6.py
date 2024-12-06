#!/usr/bin/python3
with open('../inputs/day6.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

# Function to rotate clockwise
def rotate(step):
    match step:
        case [-1,0]:
            return [0,1]
        case [0,1]:
            return [1,0]
        case [1,0]:
            return [0,-1]
        case [0,-1]:
            return [-1,0]

# Get the starting position
start = []
for i in range(len(input)):
    if '^' in input[i]:
        start = [i, input[i].index('^')]
        break

step = [-1,0]
pos = [start[0], start[1]]
path = []
total = 1

# Simulate the guard walking, and break once the guard's position throws an out of bounds exception
while True:
    try:
        pos[0] += step[0]
        pos[1] += step[1]
        assert pos[0] >= 0 and pos[1] >= 0
        if input[pos[0]][pos[1]] == '#':
            pos[0] -= step[0]
            pos[1] -= step[1]
            step = rotate(step)
        if not (pos[0], pos[1]) in path:
            path += [(pos[0], pos[1])]
            total += 1
    except:
        break

print(f"Part 1 answer: {total}")

part2 = 0
# Originally I had brute force checked adding a wall in all spots in the whole grid
# But I realized there are a bunch of places the guard never reaches
# So I only need to check adding a wall on spots that are in the guards path
for i, j in path:
    reps = 1
    step = [-1,0]
    good = True
    pos = [start[0], start[1]]
    # There's probably a clever way to detect an infinite loop. But it is easier to assume that
    # if the guard took 10000 steps, they are probably in a loop.
    while reps < 10000:
        try:
            pos[0] += step[0]
            pos[1] += step[1]
            assert pos[0] >= 0 and pos[1] >= 0
            if input[pos[0]][pos[1]] == '#' or pos == [i,j]:
                pos[0] -= step[0]
                pos[1] -= step[1]
                step = rotate(step)
            reps += 1
        except:
            good = False
            break

    if good:
        part2 += 1

print(f"Part 2 answer: {part2}")
