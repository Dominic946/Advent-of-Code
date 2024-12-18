#!/usr/bin/python3
import sys
with open('../inputs/day16.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]


sys.setrecursionlimit(10000)
print("Recursion limit:", sys.getrecursionlimit())

# Close enough to infinity
inf = 1000000
dirs = {"^": (-1, 0), "v": (1, 0), "<": (0, -1), ">": (0, 1)}
# The directions can can be turned. If you are facing up ^ then a 90 degree turn makes you face either left or right [<, >]
turns = {"^": ["<", ">"], "v": ["<", ">"], "<": ["v", "^"], ">": ["v", "^"]}

# Parse the input, store the coordinates of the walls into a set, get the start and end points
walls = set()
start = tuple()
end = tuple()
for y, row in enumerate(input):
    for x, char in enumerate(row):
        if char == '#':
            walls.add((y,x))
        elif char == 'S':
            start = (y,x)
        elif char == 'E':
            end = (y,x)

# Seen is a dict that maps a direction to a dict of coordinates and scores. For example
# {'>': {(2,3): 456, (2,4): 457}} means that we have already visited the coordinate (2,3)
# while facing right, and at that time we had score 456. So there is no need to revisit that
# same coordinate + direction combination unless we have a score better than 456
seen = {"^": {}, "v": {}, "<": {}, ">": {}}

# Recursive search function
def search(location, dir, score):
    if location == end:
        return score

    # If we have already been to this location+direction previously, with a better score,
    # then this is not an optimal solution; return
    if location in seen[dir] and seen[dir][location] < score:
        return inf

    seen[dir][location] = score
    forward = (location[0] + dirs[dir][0], location[1] + dirs[dir][1])
    # Store a list of all the possible scores we can get from here
    recursive_scores = [inf]
    # For each turn direction or step forward, if it is a valid step and we haven't been to
    # that location+direction combo before, or we will reach it with a better score than before,
    # then recursively go there and add that optimal score to our "recursive_scores" list
    if forward not in walls:
        if forward not in seen[dir] or score + 1 < seen[dir][forward]:
            recursive_scores.append(search(forward, dir, score + 1))
    for d in turns[dir]:
        if location not in seen[d] or score + 1000 < seen[d][location]:
            recursive_scores.append(search(location, d, score + 1000))

    # Return the best score
    return min(recursive_scores)

total = search(start, ">", 0)
print(f"Part 1 answer: {total}")
