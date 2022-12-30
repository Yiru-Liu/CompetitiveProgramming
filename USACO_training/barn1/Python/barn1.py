"""
ID: yiru.li1
LANG: PYTHON3
TASK: barn1
PROG: barn1
"""

def ranges(nums):
    nums = sorted(set(nums))
    gaps = [[s, e] for s, e in zip(nums, nums[1:]) if s+1 < e]
    edges = iter(nums[:1] + sum(gaps, []) + nums[-1:])
    return list(zip(edges, edges))


fin = open ('barn1.in', 'r')
fout = open ('barn1.out', 'w')

m,s,c = map(int, fin.readline().split())
# m, the maximum number of boards that can be purchased
# s, the total number of stalls
# c, the number of cows in the stalls (one cow per stall)

occupiedStalls = [] # list of stalls that are occupied
for i in range(c):  # get from input file:
    occupiedStalls.append(int(fin.readline()))

consecutiveOccupiedStalls = ranges(occupiedStalls)  # list storing the ranges of consecutive occupied stalls
print(consecutiveOccupiedStalls)

consecutiveStallsBetweenOccupiedStalls = []
for i in range(len(consecutiveOccupiedStalls)-1):
    consecutiveStallsBetweenOccupiedStalls.append([consecutiveOccupiedStalls[i][1] + 1, consecutiveOccupiedStalls[i + 1][0]])

numBoardsUsed = len(consecutiveOccupiedStalls)

theNumberOfStallsBetweenOccupiedStalls = []
for i in range(len(consecutiveStallsBetweenOccupiedStalls)):
    theNumberOfStallsBetweenOccupiedStalls.append(consecutiveStallsBetweenOccupiedStalls[i][1]-consecutiveStallsBetweenOccupiedStalls[i][0])

print(consecutiveStallsBetweenOccupiedStalls)
print(theNumberOfStallsBetweenOccupiedStalls)
theNumberOfStallsBetweenOccupiedStalls.sort()
print(theNumberOfStallsBetweenOccupiedStalls)

stallsBlocked = c

print(stallsBlocked)
print(numBoardsUsed)

currentGapRemoving = 0

while numBoardsUsed > m:
    stallsBlocked += theNumberOfStallsBetweenOccupiedStalls[currentGapRemoving]
    numBoardsUsed -= 1
    currentGapRemoving += 1

print(stallsBlocked)

fout.write (str(stallsBlocked) + "\n")
fout.close()