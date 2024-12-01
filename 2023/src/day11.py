#!/usr/bin/python3
with open('../inputs/day11.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

# Part 1
EXPAND = 1
# Part 2
EXPAND = 1000000-1

space = []
for i in input:
    space.append([x for x in i])

gs = []
for i in range(len(space)):
    for j in range(len(space[i])):
        if space[i][j] == '#':
            gs.append([i,j])

dy = 0
for i in range(len(space)):
    if '#' not in space[i]:
        for g in gs:
            if g[0] > i + dy:
                g[0] += EXPAND
        dy += EXPAND

dx = 0
for i in range(len(space[0])):
    if '#' not in [y[i] for y in space]:
        for g in gs:
            if g[1] > i + dx:
                g[1] += EXPAND
        dx += EXPAND
'''
print(gs)
for y in range(15):
    str = ''
    for x in range(15):
        if [y,x] in gs:
            str += '#'
        else:
            str += '.'
    print(str)
'''
total = 0
for i in range(len(gs)):
    for j in range(i+1, len(gs)):
        #print(f"from {i} to {j}: {abs(gs[i][0]-gs[j][0]) + abs(gs[i][1]-gs[j][1])}")
        total += abs(gs[i][0]-gs[j][0])
        total += abs(gs[i][1]-gs[j][1])


print(total)
