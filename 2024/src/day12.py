#!/usr/bin/python3
with open('../inputs/day12.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

height = len(input)
width = len(input[0])
dirs = [(0,1), (0,-1), (1,0), (-1,0)]
left_turn = {(1, 0): [(0,1), (1,1)], (-1, 0): [(0, -1), (-1, -1)], (0, 1): [(-1, 0), (-1, 1)], (0, -1): [(1, 0), (1, -1)]}

seen = []
fields = dict()

def find_field(y, x, plant_type, origin):
    seen.append((y,x))
    if (plant_type, origin) not in fields:
        fields[(plant_type, origin)] = []
    fields[(plant_type, origin)].append((y,x))
    for dy, dx in dirs:
        ny = y + dy
        nx = x + dx
        if ((ny, nx) not in seen) and (0 <= nx < width) and (0 <= ny < height) and (input[ny][nx] == plant_type):
            find_field(y+dy, x+dx, plant_type, origin)

print('parse')
for y, row in enumerate(input):
    for x, plant_type in enumerate(row):
        if (y, x) not in seen:
            find_field(y, x, plant_type, (y, x))

print('calculate cost 1')
total = 0
for plant_type, field in fields.items():
    area = len(field)
    perimiter = 0
    for plant in field:
        perimiter += 4 - sum([(plant[0]+dy, plant[1]+dx) in field for dy, dx in dirs])
    total += area * perimiter
    
print(f"Part 1 answer: {total}")

print('calculate cost 2')
total = 0
for plant_type, field in fields.items():
    area = len(field)
    perimiter = 0
    for y, x in field:
        for dy, dx in dirs:
            if (y+dy, x+dx) not in field:
                if not (((y + left_turn[(dy, dx)][0][0], x + left_turn[(dy, dx)][0][1]) in field) and ((y + left_turn[(dy, dx)][1][0], x + left_turn[(dy, dx)][1][1]) not in field)):
                    perimiter += 1

    total += area * perimiter

print(f"Part 2 answer: {total}")
