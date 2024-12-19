#!/usr/bin/python3
with open('../inputs/day19.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

patterns = set(input[0].split(', '))
memory = dict()

# Recursive function to determine how many ways the given design can be made.
# It looks for for all patterns which match the start of the design, and
# removes them, then count the arrengements in the remainder.

# For example if the available patterns are [abc, a, b] and the design is "abcde"
# then the candidates of possible remainders are [de, bcde] because the
# patterns 'abc' and 'a' matched, and were removed from the start of the design.

# So this count function is then recursively called on 'de' and 'bcde'. It goes until
# either there are no possible candidates (which means the pattern can't be made)
# or the design is empty, meaning we made the full design with patterns (success)

# I do some memoization of every successful count, to speed up the runtime significantly.
def count_arrangements(design):
    if not design:
        return 1
    if design in memory:
        return memory[design]

    candidates = [design[len(p):] for p in patterns if p == design[:len(p)]]

    total = 0
    for c in candidates:
        total += count_arrangements(c)
    memory[design] = total
    return total
    
total1 = 0
total2 = 0
for i in input[2:]:
    # count_arrangements(i) returns a count of how many possibilities there are.
    # The only difference between part 1 and part 2 is that 1 only wants to know
    # how many times that result is > 0, while part 2 sums the counts themselves.
    result = count_arrangements(i)
    total1 += bool(result)
    total2 += result

print(f"Part 1 answer: {total1}")
print(f"Part 2 answer: {total2}")
