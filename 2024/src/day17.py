#!/usr/bin/python3
with open('../inputs/day17.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

A = int(input[0].split(": ")[1])
B = int(input[1].split(": ")[1])
C = int(input[2].split(": ")[1])

code = [int(x) for x in input[4].split(": ")[1].split(',')]

def get_combo(operand):
    if 0 <= operand <= 3:
        return operand
    if operand == 4:
        return A
    if operand == 5:
        return B
    if operand == 6:
        return C
    else:
        assert(False)
    
ip = 0
out = []
while ip < len(code):
    operand = code[ip+1]
    match code[ip]:
        case 0:
            A = A // (2 ** get_combo(operand))
        case 1:
            B = B ^ operand
        case 2:
            B = get_combo(operand) % 8
        case 3:
            if A == 0:
                pass
            else:
                ip = operand - 2
        case 4:
            B = B ^ C
        case 5:
            out += [str(get_combo(operand) % 8)]
        case 6:
            B = A // (2 ** get_combo(operand))
        case 7:
            C = A // (2 ** get_combo(operand))

    ip += 2

print(f"Part 1 answer: {','.join(out)}")
