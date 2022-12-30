numCows = int(input())
cows = [int(i) for i in input().split()]
cows.sort()

maxTuition = 0
maxCharge = 0

for i, currentPrice in enumerate(cows):
    currentAmount = (numCows - i) * currentPrice
    if currentAmount > maxTuition:
        maxTuition = currentAmount
        maxCharge = currentPrice

print(f"{maxTuition} {maxCharge}")
