#!/usr/bin/python3
with open('../inputs/day3.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]


def check_valid(engine, x, y):
    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            try:
                if engine[y+dy][x+dx] not in ['.','1','2','3','4','5','6','7','8','9','0']:
                    return True
            except:
                continue
    return False


engine = []
for i in input:
    engine.append([a for a in i])

total = 0
for y in range(len(engine)):
    valid = False
    num = ""
    for x in range(len(engine[0])):
        if engine[y][x] in ['1','2','3','4','5','6','7','8','9','0']:
            if not valid and check_valid(engine, x, y):
                valid = True
            num += engine[y][x]
        else:
            if valid:
                print(num)
                total += int(num)
            valid = False
            num = ""
    if valid:
        print(num)
        total += int(num)
    valid = False
    num = ""

print(total)
