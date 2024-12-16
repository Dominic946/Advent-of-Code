#!/usr/bin/python3
with open('../inputs/day12.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

height = len(input)
width = len(input[0])
# The 4 directions: up, down, left, right
dirs = [(0,-1), (0,1), (-1,0), (1,0)]

# A const dict like {dir: [left direction, up-left direction]}
# Like suppose I am facing east, or in other words I am facing in the (0,1) dir.
# Then if I turn to my left, I will be facing in the (-1, 0) direction. If I combine those to go forward and left, that is the (-1, 1) direction.
# So this dict {dir: [left direction, up-left direction]} contains (0,1) : [(-1, 0), (-1, 1)] to represent that example.
left_turn = {(1, 0): [(0,1), (1,1)], (-1, 0): [(0, -1), (-1, -1)], (0, 1): [(-1, 0), (-1, 1)], (0, -1): [(1, 0), (1, -1)]}

seen = set()

# A dict like {letter: [list of points]} aka {'A': [(0,0), (1,0)]} to show that their is a 'A' type field on tiles (0,0) and (1,0)
# Though the fact that there can be multiple disjoin fields which are both type 'A' make it a bit more complecated.
# So I also put an origin in the dict key, where the origin is just one point (which is the top most, left most point) that is in this field
# So this dict is actually formatted {('A', (0,0)): [(0,0), (1,0)]}.
fields = dict()

# dfs alrogithm, like flood fill to find all tiles of the same plant type that are connected to build the fields dict
def find_field(y, x, plant_type, origin):
    seen.add((y,x))
    if (origin) not in fields:
        fields[(origin)] = []
    fields[(origin)].append((y,x))
    for dy, dx in dirs:
        ny = y + dy
        nx = x + dx
        if ((ny, nx) not in seen) and (0 <= nx < width) and (0 <= ny < height) and (input[ny][nx] == plant_type):
            find_field(y+dy, x+dx, plant_type, origin)

for y, row in enumerate(input):
    for x, plant_type in enumerate(row):
        if (y, x) not in seen:
            find_field(y, x, plant_type, (y, x))


total = 0
for field in fields.values():
    area = len(field)
    perimiter = 0
    for plant in field:
        perimiter += 4 - sum([(plant[0]+dy, plant[1]+dx) in field for dy, dx in dirs])
    total += area * perimiter
    
print(f"Part 1 answer: {total}")


total = 0
for field in fields.values():
    area = len(field)
    perimiter = 0
    for y, x in field:
        for dy, dx in dirs:
            if (y+dy, x+dx) not in field:
                if not (((y + left_turn[(dy, dx)][0][0], x + left_turn[(dy, dx)][0][1]) in field) and ((y + left_turn[(dy, dx)][1][0], x + left_turn[(dy, dx)][1][1]) not in field)):
                    perimiter += 1

    total += area * perimiter

print(f"Part 2 answer: {total}")
