#!/usr/bin/python3
from math import prod

with open('../inputs/day14.txt', 'r') as file:
    input_ = file.readlines()
    input_ = [i.strip() for i in input_]

# THIS CODE ONLY PRINTS THE ANSWER FOR PART 1
# from there you can manually visualize the outputs
# for part 2 and press enter until you see the tree :)

height = 7
width = 11
if len(input_) > 100:
    height = 103
    width = 101

def move(seconds):        
    middle = []
    quads = {'tl':[], 'tr':[], 'bl':[], 'br':[]}
    for i in input_:
        
        p = [int(x) for x in i.split(' ')[0].split('=')[1].split(',')]
        v = [int(x) for x in i.split(' ')[1].split('=')[1].split(',')]
        pos = ((p[0] + seconds*v[0]) % width, (p[1] + seconds*v[1]) % height)
        if pos[0] == width // 2 or pos[1] == height //2:
            middle += [pos]
            continue
        if pos[0] < width // 2:
            if pos[1] < height // 2:
                quads['tl'] += [pos]
            else:
                quads['bl'] += [pos]

        elif pos[0] > width // 2:
            if pos[1] < height // 2:
                quads['tr'] += [pos]
            else:
                quads['br'] += [pos]
    return quads, middle


quads, _ = move(100)
print(f"Part 1 answer: {prod([len(x) for x in quads.values()])}")

# For part 2 I just made a terminal visualization, where I print out a picture of where all robots are
# to the terminal and look at it, then press enter to generate the next frame

# My strategy was to look at each frame 1 by 1 until I find the tree and I was starting at the static
# for a while but gave up after 1000 "seconds". But while I was watching I noticed a pattern.

# Every once in a while a frame would be much more concentrated near the center, and have some
# straight horizontal lines, then all would be messy again next frame.
# I kept track of when these patterns happened and (at least for my input) it occured
# every 101 frames, there would be a high concentration and many straight lines.

# So from there I modified my code to print every 101 seconds, and from there I kept looking until
# The christmas tree picture appeared. 
i = 5174
while True:
    quads, middle = move(i)
    all_spaces = quads['tl'] + quads['bl'] + quads['tr'] + quads['br'] + middle

    for x in range(width):
        for y in range(height):
            if (y,x) in all_spaces:
                print('X', end='')
            else:
                print('.', end='')
        print('')
    input(i)
    i += 101
