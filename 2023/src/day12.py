#!/usr/bin/python3
with open('../inputs/day12.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

def validate(board, key):
    a = []
    c = 0
    #print("VALIDATE")
    for b in board:
        if b == '#':
            c += 1
        else:
            if c > 0:
                a.append(c)
                c = 0
    if c > 0:
        a.append(c)
    #print('a', a)
    #print('key', key)
    if a == key:
        return 1
    else:
        return 0

def recur(board, key):
    #print(board, key)
    try:
        i = board.index('?')
        b = list(board)
        b[i] = '#'
        t = recur(''.join(b), key)
        b[i] = '.'
        return t + recur(''.join(b), key)
    except:
        return validate(board, key)


total = 0
for i in input:
    board, key = i.split()
    key = [int(k) for k in key.split(',')]
    total += recur(board, key)

print(total)
