#!/usr/bin/python3
with open('../inputs/day7.txt', 'r') as file:
    input = file.readlines()
    input = [i.strip() for i in input]

#values1 = ['A','K','Q','J','T','9','8','7','6','5','4','3','2']
values = ['A','K','Q','T','9','8','7','6','5','4','3','2', 'J']
ranks = ['five', 'four', 'full', 'three', 'two', 'pair', 'high']

def find_type(cards):
    dict = {}
    for c in cards:
        if c in dict:
            dict[c] += 1
        else:
            dict[c] = 1
    j = 0
    if "J" in dict:
        j = dict.pop("J")
    counts = sorted(list(dict.values()))
    try:
        counts[-1] += j
    except:
        counts = [5]
    if counts == [5]:
        return 'five'
    if counts == [1,4]:
        return 'four'
    if counts == [2,3]:
        return 'full'
    if counts == [1,1,3]:
        return 'three'
    if counts == [1,2,2]:
        return 'two'
    if counts == [1,1,1,2]:
        return 'pair'
    if counts == [1,1,1,1,1]:
        return 'high'

class hand():
    def __init__(self, cards, bid):
        self.cards = cards
        self.bid = bid
        self.type = find_type(cards)

    def __gt__(self, other):
        if ranks.index(self.type) < ranks.index(other.type):
            return True
        if ranks.index(self.type) > ranks.index(other.type):
            return False

        for i in range(5):
            if values.index(self.cards[i]) < values.index(other.cards[i]):
                return True
            if values.index(self.cards[i]) > values.index(other.cards[i]):
                return False
        return False

    def __str__(self):
        return f"Cards: {self.cards} Bid: {self.bid}"


hands = []
for i in input:
    c,b = i.split(' ')
    hands.append(hand(c,b))

hands = sorted(hands)
total = 0
for h in range(len(hands)):
    total += (h+1)*int(hands[h].bid)

print(total)





#
