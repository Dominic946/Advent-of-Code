#!/usr/bin/python3
with open('../inputs/day15.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

## Initialize variables and parse input ##
dirs = {"^": (-1, 0), "v": (1, 0), "<": (0, -1), ">": (0, 1)}
width = len(input[0])
y = 0
walls = set()
boxes = set()
robot = [0,0]

while input[y]:
    for x, char in enumerate(input[y]):
        match char:
            case '#':
                walls.add((y, x))
            case "O":
                boxes.add((y, x))
            case "@":
                robot = [y, x]
    y += 1

height = y
y += 1
instructions = ""

while y < len(input):
    instructions += input[y]
    y += 1

## For each instruction, try to move the robot.
# To do this, it searches until it hits a wall (which cancels the movement),
# or finds an empty space (which moves a box into that empty space and moves the robot forward)
for i in instructions:
    ny = robot[0] + dirs[i][0]
    nx = robot[1] + dirs[i][1]
    step = (ny, nx)
    while 0 <= nx < width and 0 <= ny < height and (ny, nx) not in walls:
        if (ny, nx) not in boxes:
            if step in boxes:
                boxes.add((ny, nx))
                boxes.remove(step)
            robot = [step[0], step[1]]
            break
        else:
            ny += dirs[i][0]
            nx += dirs[i][1]

## Print the final grid, just for fun visualization
for y in range(height):
    for x in range(width):
        if (y,x) in walls:
            print("#", end="")
        elif (y,x) in boxes:
            print("O", end="")
        elif x == robot[1] and y == robot[0]:
            print("@", end="")
        else:
            print(".", end="")
    print("")

## The total is the sum of the boxes GPS coordinates
total = sum([100 * b[0] + b[1] for b in boxes])
print(f"Part 1 answer: {total}")


## I start by building the new input grid; horizontally duplicate each character from the original input
input2 = []
for y in range(height):
    new_row = ""
    for char in input[y]:
        match char:
            case '#':
                new_row += "##"
            case "O":
                new_row += "[]"
            case "@":
                new_row += "@."
            case ".":
                new_row += ".."
    input2 += [new_row]

## Initialize the variables again, and do similar parsing from before but with the widened input2
width = len(input2[0])
y = 0
walls = set()
box_left = set()
box_right = set()
robot = [0,0]

for y in range(height):
    for x, char in enumerate(input2[y]):
        match char:
            case '#':
                walls.add((y, x))
            case "[":
                box_left.add((y, x))
            case "]":
                box_right.add((y,x))
            case "@":
                robot = [y, x]


## For each instruction, try to move the robot.
# Keep track of all spaces that an object (robot or box segment) is being pushed into
for i in instructions:
    ny = robot[0] + dirs[i][0]
    nx = robot[1] + dirs[i][1]
    pushing = {"@": [(ny, nx)], "[": [], "]": []}
    push_into = set()
    push_into.add((ny, nx))
    buffer = set()
    buffer.add((ny, nx))
    # If at any point any box segment or robot will be pushed into a wall, cancel the movement
    while sum([p in walls for p in push_into]) == 0:
        # If the buffer (which contains the frontmost spaces being pushed to) is all empty spots,
        # Then commit to the movement
        if sum([p in box_left.union(box_right) for p in buffer]) == 0:
            # Update the positions of the robot and all box segments
            robot = pushing["@"][0]
            for bl in pushing["["][::-1]:
                box_left.remove(bl)
                box_left.add((bl[0] + dirs[i][0], bl[1] + dirs[i][1]))
            for br in pushing["]"][::-1]:
                box_right.remove(br)
                box_right.add((br[0] + dirs[i][0], br[1] + dirs[i][1]))
            break
        # This else is the situation where there are boxes in the path that we are pushing into
        else:
            buffer = set()
            for p in push_into:
                next_step = (p[0] + dirs[i][0], p[1] + dirs[i][1])
                if p in box_left and next_step not in push_into:
                    # If we are pushing the left half of the box, the right half also gets pushed
                    # Though sometimes this gets double counted, so make sure we aren't adding duplicates to the pushing list
                    if (p[0], p[1]) not in pushing["["]:
                        pushing["["] += [(p[0], p[1])]
                    if (p[0], p[1]+1) not in pushing["]"]:
                        pushing["]"] += [(p[0], p[1]+1)]
                    # Add the steps in front of these new box to the set of frontmost spaces being pushed into
                    buffer.add(next_step)
                    buffer.add((next_step[0], next_step[1]+1))

                # duplicate logic as above, but for the right half of the box
                elif p in box_right and next_step not in push_into:

                    if (p[0], p[1]-1) not in pushing["["]:
                        pushing["["] += [(p[0], p[1]-1)]
                    if (p[0], p[1]) not in pushing["]"]:
                        pushing["]"] += [(p[0], p[1])]

                    buffer.add(next_step)
                    buffer.add((next_step[0], next_step[1]-1))
            [push_into.add(b) for b in buffer]


## Print the final grid, just for fun visualization
for y in range(height):
    for x in range(width):
        if (y,x) in walls:
            print("#", end="")
        elif (y,x) in box_left:
            print("[", end="")
        elif (y,x) in box_right:
            print("]", end="")
        elif x == robot[1] and y == robot[0]:
            print("@", end="")
        else:
            print(".", end="")
    print("")

## The total is the sum of the boxes GPS coordinates
# where the x coordinate is measured from the left side of the box
total = sum([100 * b[0] + b[1] for b in box_left])
print(f"Part 2 answer: {total}")
