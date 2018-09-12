import sys

n = int(input())

for i in range(n):
    line = sys.stdin.readline()

    metrics = line.rstrip().split(" ")
    pop = int(metrics[0])
    grow = float(metrics[1])
    food = float(metrics[2])
    years = 0
    while(pop <= food):
        pop = int(pop * (1 + (grow/100)))
        years += 1
    print(years)
