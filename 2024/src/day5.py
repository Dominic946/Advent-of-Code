#!/usr/bin/python3
with open('../inputs/day5.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

# I don't know why I created a class for this, there's surely an easier way,
# But this clas does what I needed it to do.
class nums_after():
    # dict from int -> list[int]
    # where {4:[5,3]} means 4 must come before 5 and 3
    def __init__(self):
        self.data = dict()

    def add(self, key, value):
        if key in self.data:
            self.data[key] += [value]
        else:
            self.data[key] = [value]
    
    def get(self, key):
        if key in self.data:
            return self.data[key]
        else:
            return []

# Parse input
nums_after = nums_after()
updates = []
for i in input:
    if '|' in i:
        l, r = [int(num) for num in i.split('|')]
        nums_after.add(l, r)

    elif ',' in i:
        updates.append([int(num) for num in i.split(',')])

# Solve part 1 by asserting that numbers are in the correct order
part1 = 0
bad_updates = []
for update in updates:
    try:
        for x in range(len(update)):
            starting_num = update[x]
            for future_num in update[x+1:]:
                assert future_num in nums_after.get(starting_num)
                assert starting_num not in nums_after.get(future_num)
        part1 += update[len(update)//2]
    except:
        bad_updates += [update]

print(f"Part 1 answer: {part1}")

# Solve part 2 by writing a pretty basic insertion sort to sort all the bad updates
# Using the given rules to compare numbers
part2 = 0
for update in bad_updates:
    sorted = []
    for num in update:
        idx = 0
        while idx < len(sorted) and num not in nums_after.get(sorted[idx]):
            idx += 1
        sorted.insert(idx, num)
    part2 += sorted[len(update)//2]

print(f"Part 2 answer: {part2}")
