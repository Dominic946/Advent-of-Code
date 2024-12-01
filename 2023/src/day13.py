#!/usr/bin/python3
with open('../inputs/day13.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

def find_v(board):
    for c in range(1,len(board[0])):
        good = True
        for x in range(c):
            try:
                if [i[c-x-1] for i in board] != [i[c+x] for i in board]:
                    good = False
                    break
            except:
                break
        if good:
            return c
    return 0

def find_h(board):
    for c in range(1,len(board)):
        good = True
        for x in range(c):
            try:
                if board[c-x-1] != board[c+x]:
                    good = False
                    break
            except:
                break
        if good:
            return c
    return 0



boards = []
b = []
for i in input:
    if len(i) > 1:
        b.append(i)
    else:
        boards.append(b)
        b = []
boards.append(b)


total = 0
for x in boards:
    total += find_v(x)
    total += find_h(x) * 100

print(total)
