#!/usr/bin/python3
import os
mode = 0o777

for i in range(1, 26):
    code = ["#!/usr/bin/python3",
            f"with open('../inputs/day{i}.txt', 'r') as file:",
            "    input = file.readlines()",
            "    input = [i.strip() for i in input]",
            "",
            "for i in input:",
            "    print(i)",
			"",
			"total = 0",
			'print(f"Part 1 answer: {total}")',
			'print(f"Part 2 answer: {total}")',]
    filename = f"day{i}.py"
    with open(filename, 'w') as file:
        for line in code:
            file.write(line)
            file.write('\n')
    os.chmod(filename, mode)

    filename = f"../inputs/day{i}.txt"
    with open(filename, 'w') as file:
        file.write(f"day {i} empty file")
