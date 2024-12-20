#!/usr/bin/python3
with open('../inputs/day20.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

dirs = [(0,1), (0,-1), (1,0), (-1,0)]

# Parse the input, store all wall coordinates in a set, get the start and end coordinates
walls = set()
start = tuple()
end = tuple()
height = len(input)
width = len(input[0])
for y, row in enumerate(input):
    for x, char in enumerate(row):
        if char == "#":
            walls.add((y,x))
        if char == "S":
            start = (y,x)
        if char == "E":
            end = (y,x)

# A dict that maps a coordinate to the number of steps needed to get to the end
# Suppose the maze is like S . . E, where the start is (0,0) and the end is (0,3)
# Then this time_to_end dict will be like {(0,0): 3, (0,1): 2, (0,2): 1, (0,3): 0}
time_to_end = dict()

# Build the time_to_end dict, for each space count how many steps away it is from the end
location = end
steps = 0
while location != start:
    time_to_end[location] = steps
    for d in dirs:
        step = (location[0] + d[0], location[1] + d[1])
        if step not in walls and step not in time_to_end:
            location = step
            steps += 1
            break

time_to_end[location] = steps
path = list(time_to_end.keys())[::-1]

# Count the possible time saves.
# For each step along the path, look at each future step of the path.
# If we can get to that future step in less than [2 or 20] moves (measured with Manhattan distance)
# then add the difference in times_to_end, minus the steps needed to make the travel, to the saves list.
def count_saves(cheat_time=2):
    saves = []
    for idx, location in enumerate(path):
        for new_location in path[idx:]:
            distance = abs(new_location[0] - location[0]) + abs(new_location[1] - location[1])
            if distance < cheat_time + 1:
                saves.append(time_to_end[location] - time_to_end[new_location] - distance)
    return saves

print(f"Part 1 answer: {sum([1 for s in count_saves() if s >= 100])}")
print(f"Part 2 answer: {sum([1 for s in count_saves(20) if s >= 100])}")
