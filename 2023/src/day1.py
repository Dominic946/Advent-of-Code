#!/usr/bin/python3
with open('../inputs/day1.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

words = {"one": 1, "two": 2, "three": 3, "four": 4, "five": 5, "six": 6, "seven": 7, "eight": 8, "nine": 9}

total = 0
for i in input:
    nums = []
    for char in i:
        try:
            int(char)
            nums.append(char)
        except:
            pass
    total += int(nums[0] + nums[-1])


print(f"Part 1 answer: {total}")

total = 0
for i in input:
    chars = ""
    nums = []
    for char in i:
        try:
            int(char)
            nums.append(int(char))
            break
        except:
            chars += char
            found = False
            for n in words.keys():
                if n in chars:
                    found = True
                    nums.append(words[n])
                    break
            if found:
                break
    chars = ""
    for char in i[::-1]:
        try:
            int(char)
            nums.append(int(char))
            break
        except:
            chars = char + chars
            found = False
            for n in words.keys():
                if n in chars:
                    found = True
                    nums.append(words[n])
                    break
            if found:
                break

    total += int(str(nums[0]) + str(nums[-1]))


print(f"Part 2 answer: {total}")
