#!/usr/bin/python3
with open('../inputs/day8.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

# Parse the input to build a dict of {letters -> list of points}, where
# {'a': [(1,2), (3,4)]} means that there are letter 'a' beacons at coordinates (1,2) and (3,4).
# Yes I know the problem calls them "antennas" but I like the word "beacon" more.
beacons = {}
height = len(input)
width = len(input[0])
for y in range(height):
    for x in range(width):
        char = input[y][x]
        if char not in ".#":
            if char not in beacons:
                beacons[char] = []
            beacons[char] += [(y,x)]

# Main function to find all antinodes created by all pairs of beacons
def run_code(beacons, part=1):
    antinodes = set()
    # Loop through each "frequency" beacon type
    for letter in beacons:
        # Among the beacons at this frequency, loop through all pairs of them.
        for idx, first_beacon in enumerate(beacons[letter]):
            for second_beacon in beacons[letter][idx+1:]:
                # Only Part 2 allows antinodes at the beacons
                if part == 2:
                    antinodes.add(first_beacon)
                    antinodes.add(second_beacon)
                # Get the distance between the two beacons. There are potentially
                # antinodes at each step of this distance from a beacon,
                # Either stepping backwards from the first beacon or forwards from the second.
                dy = second_beacon[0] - first_beacon[0]
                dx = second_beacon[1] - first_beacon[1]
                potential_antinode_1 = (first_beacon[0] - dy, first_beacon[1] - dx)
                potential_antinode_2 = (second_beacon[0] + dy, second_beacon[1] + dx)
                # Check potential antinodes in direction 1
                # Break when out of bounds, or part 1 which only considers 1 antinode in each direction
                while True:
                    if 0 <= potential_antinode_1[0] < height and 0 <= potential_antinode_1[1] < width:
                        antinodes.add(potential_antinode_1)
                    else:
                        break
                    if part == 1:
                        break
                    else:
                        potential_antinode_1 = (potential_antinode_1[0] - dy, potential_antinode_1[1] - dx)

                # Check potential antinodes in direction 2
                # Break when out of bounds, or part 1 which only considers 1 antinode in each direction
                while True:
                    if 0 <= potential_antinode_2[0] < height and 0 <= potential_antinode_2[1] < width:
                        antinodes.add(potential_antinode_2)
                    else:
                        break
                    if part == 1:
                        break
                    else:
                        potential_antinode_2 = (potential_antinode_2[0] + dy, potential_antinode_2[1] + dx)

    # I used a set of points to track antinodes. Set automatically removes duplicated so I
    # can just return the len() of the set to get the answer.
    return len(antinodes)

print(f"Part 1 answer: {run_code(beacons, part=1)}")
print(f"Part 2 answer: {run_code(beacons, part=2)}")
