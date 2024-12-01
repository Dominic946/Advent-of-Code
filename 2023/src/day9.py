#!/usr/bin/python3
with open('../inputs/day9.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

total1 = 0
total2 = 0

for i in input:
    l = [int(j) for j in i.split()]
    ll = [l]
    cur = l
    while True in [c != 0 for c in cur]:
        cur = []
        for i in range(len(l)-1):
            cur.append(l[i+1]-l[i])
        ll.append(cur)
        l = cur
    total1 += sum([x[-1] for x in ll])

    subtotal = 0
    for x in ll[::-1]:
        subtotal = x[0] - subtotal
    total2 += subtotal

print(f"Part 1: {total1}")
print(f"Part 2: {total2}")
