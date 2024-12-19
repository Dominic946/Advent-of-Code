#!/usr/bin/python3
with open('../inputs/day2.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

total = 0
for i in input:
    ID, games = i.replace(' ', '').split(':')
    ID = int(ID.split('Game')[1])
    fail = False
    maxr = 12
    maxg = 13
    maxb = 14
    for round in games.split(';'):
        for color in round.split(','):
            r = color.split('red')
            g = color.split('green')
            b = color.split('blue')
            if len(r) > 1 and int(r[0]) > maxr:
                fail = True
            if len(g) > 1 and int(g[0]) > maxg:
                fail = True
            if len(b) > 1 and int(b[0]) > maxb:
                fail = True

    total += ID if not fail else 0

print(f"Part 1 answer: {total}")

total = 0
for i in input:
    ID, games = i.replace(' ', '').split(':')
    fail = False
    maxr = 0
    maxg = 0
    maxb = 0
    for round in games.split(';'):
        for color in round.split(','):
            r = color.split('red')
            g = color.split('green')
            b = color.split('blue')
            if len(r) > 1 and int(r[0]) > maxr:
                maxr = int(r[0])
            if len(g) > 1 and int(g[0]) > maxg:
                maxg = int(g[0])
            if len(b) > 1 and int(b[0]) > maxb:
                maxb = int(b[0])

    total += maxr * maxg * maxb

print(f"Part 2 answer: {total}")
