#!/usr/bin/python3
with open('../inputs/day3.txt', 'r') as file:
    input = file.readlines()
    input = 'do()' + ''.join([i.strip() for i in input])

def get_score(text):
	# Converts "abc~mul(2,3)~abc~mul(4,5)" into a list of lists of strings [['2', '3'], ['4', '5']]
	num_pairs = [t.split(')')[0].split(',') for t in text.split("mul(")]
	score = 0
	# For each list of two strings, if they are both integers then multiply them
	for n in num_pairs:
		try:
			assert len(n) == 2
			score += int(n[0]) * int(n[1])
		except:
			continue

	return score

def remove_donts(text):
	# Splits the text into a list of lists split by "don't()"s, and "do()"s
	# such that only the first item of each sublist is in "don't()" territory
	split_list = [t.split("do()") for t in text.split("don't()")]
	# return a flattened list with the first item of each sublist removed
	return ''.join([e for t in split_list for e in t[1:]])

print(f"Part 1 answer: {get_score(input)}")
print(f"Part 2 answer: {get_score(remove_donts(input))}")
