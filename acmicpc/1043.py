import sys
import copy
N, M = map(int, sys.stdin.readline().split())
haters = list(map(int, sys.stdin.readline().split()))
if len(haters) > 1:
    haterSet = set(haters[1:])
else:
    haterSet = set()

party = [list(map(int, sys.stdin.readline().split())) for _ in range(M)]

prevSet = set()
while prevSet != haterSet:
    prevSet = copy.deepcopy(haterSet)
    for p in party:
        if set(p[1:]) & haterSet: haterSet = haterSet | set(p[1:])

res = 0
for p in party:
    if set(p[1:]) & haterSet: res = res + 1
print(M - res)
