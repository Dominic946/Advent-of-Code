#!/usr/bin/python3
'''
with open('../inputs/day1.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

def find_last(smain, subs):
    ret = None
    idx = 0
    while True:
        f = smain[idx:].find(subs)
        idx += f
        if f == -1:
            return ret if ret else idx
        ret = idx
        idx += 1

total = 0
nums =  ['zero','one','two','three','four','five','six','seven','eight','nine']
nums2 = ['0','1','2','3','4','5','6','7','8','9']

for i in input:
    first = 1000000
    last = 0
    f=''
    l=''
    for lst in [nums, nums2]:
        for n in range(len(lst)):
            idx1 = i.find(lst[n])
            idx2 = find_last(i, lst[n])
            if idx1 > -1 and idx1 < first:
                first = idx1
                f = n
            if idx2 > -1 and idx2 > last:
                last = idx2
                l = n

    print(i)
    print(int(str(f) + str(l)))
    total += int(str(f) + str(l))


print(total)
'''
# lol hardest day 1? I took this from Jonathan Paulson
import sys
D = open('../inputs/day1.txt', 'r').read().strip()
p1 = 0
p2 = 0
for line in D.split('\n'):
  p1_digits = []
  p2_digits = []
  for i,c in enumerate(line):
    if c.isdigit():
      p1_digits.append(c)
      p2_digits.append(c)
    for d,val in enumerate(['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']):
      if line[i:].startswith(val):
        p2_digits.append(str(d+1))
  p1 += int(p1_digits[0]+p1_digits[-1])
  p2 += int(p2_digits[0]+p2_digits[-1])
print(p1)
print(p2)
