#!/usr/bin/python3
with open('../inputs/day10.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

grid = []
pipe = []
y = 0

for i in input:
    l = [x for x in i]
    pipe.append([0]*len(l))
    grid.append(l)
    if 'S' in l:
        sy = y
        sx = l.index('S')
    y += 1

p = (sx, sy)

def get(p):
    try:
        return grid[p[1]][p[0]]
    except:
        return '.'

def step(dir):
    global p
    if dir == 'u':
        p = (p[0], p[1]-1)
    if dir == 'd':
        p = (p[0], p[1]+1)
    if dir == 'l':
        p = (p[0]-1, p[1])
    if dir == 'r':
        p = (p[0]+1, p[1])


if get((sx-1, sy)) in '-FL':
    dir = 'l'
elif get((sx+1, sy)) in '-J7':
    dir = 'r'
elif get((sx, sy-1)) in '|F7':
    dir = 'u'
elif get((sx, sy+1)) in '|LJ':
    dir = 'd'

print(dir)
pipe[p[1]][p[0]] = 1
step(dir)
dis = 1

while get(p) != 'S':
    pipe[p[1]][p[0]] = 1
    t = get(p)
    if t == 'L':
        if dir == 'l':
            dir = 'u'
        else:
            dir = 'r'
    if t == 'J':
        if dir == 'r':
            dir = 'u'
        else:
            dir = 'l'
    if t == '7':
        if dir == 'u':
            dir = 'l'
        else:
            dir = 'd'
    if t == 'F':
        if dir == 'u':
            dir = 'r'
        else:
            dir = 'd'

    step(dir)
    dis += 1

p2 = 0
for i in range(len(grid)):
    for j in range(len(grid[i])):
        if pipe[i][j] == 0:
            dx = j
            count = 0
            last = ''
            while dx > 0:
                dx -= 1

                if pipe[i][dx] == 3:
                    break
                if pipe[i][dx] == 2:
                    count += 1
                    break

                if grid[i][dx] == '|':
                    count += 1
                    continue
                if grid[i][dx] == '-':
                    continue
                if grid[i][dx] == 'J':
                    last = 'J'
                    continue
                if grid[i][dx] == '7':
                    last = '7'
                    continue
                if grid[i][dx] == 'F':
                    if last == 'J':
                        count += 1
                    last = ''
                    continue
                if grid[i][dx] == 'L' or grid[i][dx] == 'S':
                    if last == '7':
                        count += 1
                    last = ''
                    continue

            # 2 is inside, 3 is outside
            if count%2 == 0:
                pipe[i][j] = 3
            else:
                pipe[i][j] = 2
                p2 += 1


for i in range(len(grid)):
    str = ''
    for j in range(len(grid[i])):
        if pipe[i][j] == 1:
            str += grid[i][j]
        elif pipe[i][j] == 2:
            str += '#'
        else:
            str += '.'
    print(str)

print(f"part 1: {dis/2}")
print(f"part 2: {p2}")
