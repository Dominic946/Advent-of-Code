#!/usr/bin/python3
with open('../inputs/day9.txt', 'r') as file:
    input = [int(i) for i in file.readlines()[0]]


disk = []
data = True
idx = 0
for i in input:
    if data:
        disk += [idx] * int(i)
        idx += 1
    else:
        disk += ['.'] * int(i)
    data = not data

while True:
    idx = len(disk) - 1
    while disk[idx] == '.':
        idx -= 1
    dot_idx = disk.index('.')
    if idx < dot_idx:
        break
    disk[dot_idx] = disk[idx]
    disk[idx] = '.'

total = 0
for i in range(disk.index('.')):
    total += i * disk[i]

print(f"Part 1 answer: {total}")



# file[0] is the file's starting index, file[1] is the file's length
numbered_input = [[sum(input[:i]), input[i]] for i in range(len(input))]
files = numbered_input[::2][::-1]
gaps = numbered_input[1::2]
data = []
max_id = len(files) - 1
for id, file_ in enumerate(files):
    for gap in gaps:
        if gap[0] < file_[0] and gap[1] >= file_[1]:
            gap[1] -= file_[1]
            file_[0] = gap[0]
            gap[0] += file_[1]

    data += [[max_id - id, file_[0], file_[1]]]

# data[0] is the file id, data[1] is the file's starting index, data[2] is the file's length
part2 = 0
for d in data:
    for idx in range(d[1], d[1]+d[2]):
        part2 += idx * d[0]

print(f"Part 2 answer: {part2}")
