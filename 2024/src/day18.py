#!/usr/bin/python3
import sys
with open('../inputs/day18.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

sys.setrecursionlimit(10000)

# Close enough to infinity
inf = 1000000
dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

# Parse the input, store the coordinates of the walls into a set
grid_size = 70
num_bytes = 1024
walls = set()
start = (0,0)
end = (grid_size, grid_size)
for i in input[:num_bytes]:
    walls.add(tuple([int(c) for c in i.split(',')]))

# A 'seen' dict that maps a coordinate to a score. For example {(2,3): 12} means we have
# already visited coordinate (2,3) and at that time we had score 12. So there is no need
# to revisit it unless we would get to it with a better score.
seen = {start: 0}

# Recursive search function
# Returns a tuple containing (number of steps taken, [list of coordinates visited along the optimal path])
def search(location, steps, path):
    if location == end:
        return (steps, path)

    # Store a list of all the possible scores we can get from here
    recursive_scores = [(inf, path)]

    for dy, dx in dirs:
        ny = location[0] + dy
        nx = location[1] + dx
        if (ny, nx) not in walls and 0 <= nx <= grid_size and 0 <= ny <= grid_size:
            if (ny, nx) not in seen or steps + 1 < seen[(ny, nx)]:
                seen[(ny,nx)] = steps + 1
                recursive_scores.append(search((ny, nx), steps + 1, path + [(ny, nx)]))

    # Return the best score
    for score, path in recursive_scores:
        if score == min([s[0] for s in recursive_scores]):
            return (score, path)

total, best_path = search(start, 0, [start])
print(f"Part 1 answer: {total}")

# I kept a list of the coordinates visited along the optimal path,
# only recalculate when a new wall is placed on our path
while total < inf:
    num_bytes += 1
    new_wall = tuple([int(c) for c in input[num_bytes].split(',')])
    walls.add(new_wall)

    if new_wall in best_path:
        seen = {start: 0}
        total, best_path = search(start, 0, [start])


print(f"Part 2 answer: {input[num_bytes]}")
