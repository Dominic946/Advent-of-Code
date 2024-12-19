#!/usr/bin/python3
with open('../inputs/day3.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

nums = ['1','2','3','4','5','6','7','8','9','0']

def check_valid(engine, x, y):
    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            try:
                if engine[y+dy][x+dx] not in ['.'] + nums:
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
        if engine[y][x] in nums:
            if not valid and check_valid(engine, x, y):
                valid = True
            num += engine[y][x]
        else:
            if valid:
                total += int(num)
            valid = False
            num = ""
    if valid:
        total += int(num)
    valid = False
    num = ""

print(f"Part 1 answer: {total}")


def get_full_num_from(y, x):
    coords = []
    dx = -1
    while x+dx >= 0 and input[y][x + dx] in nums:
        dx -= 1
    dx += 1
    num = input[y][x + dx]
    coords.append((y, x + dx))
    dx += 1
    while x+dx < len(input[y]) and input[y][x + dx] in nums:
        num += input[y][x + dx]
        coords.append((y, x + dx))
        dx += 1
    return num, coords
                        

total = 0
for y, row in enumerate(input):
    for x, char in enumerate(row):
        if char == "*":
            numbers = []
            coords = []
            for dy in [-1, 0, 1]:
                for dx in [-1, 0, 1]:
                    if (y+dy, x+dx) not in coords and input[y + dy][x + dx] in nums:
                        n, c = get_full_num_from(y + dy, x + dx)
                        numbers.append(n)
                        coords += c
            if len(numbers) == 2:
                total += int(numbers[0]) * int(numbers[1])

                        
print(f"Part 2 answer: {total}")
