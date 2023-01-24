import sys
from math import factorial
N, R, G, B = map(int, sys.stdin.readline().split())

size = 0
for n in range(N + 1): size += n
if R+G+B < size: 
    print(0)
    sys.exit()

comb = [ #RGB
    [[0]], #0
    [[1]], #1
    [[2, 0, 0], [0, 2, 0], [0, 0, 2], [1, 1, 0], [1, 0, 1], [0, 1, 1]], #2
    [[3, 0, 0], [0, 3, 0], [0, 0, 3], [1, 1, 1]], #3
    [[4, 0, 0], [0, 4, 0], [0, 0, 4], [2, 2, 0], [2, 0, 2], [0, 2, 2]], #4
    [[5, 0, 0], [0, 5, 0], [0, 0, 5]], #5
    [[6, 0, 0], [0, 6, 0], [0, 0, 6], [3, 3, 0], [3, 0, 3], [0, 3, 3], [2, 2, 2]], #6
    [[7, 0, 0], [0, 7, 0], [0, 0, 7]], #7
    [[8, 0, 0], [0, 8, 0], [0, 0, 8], [4, 4, 0], [4, 0, 4], [0, 4, 4]], #8
    [[9, 0, 0], [0, 9, 0], [0, 0, 9], [3, 3, 3]], #9
    [[10, 0, 0], [0, 10, 0], [0, 0, 10], [5, 5, 0], [5, 0, 5], [0, 5, 5]], #10
]

def check(floor, r, g, b):
    if floor == 1:
        if r and g and b: return 3
        elif (r and g) or (g and b) or (b and r): return 2
        else: return 1

    ret = 0
    cap = comb[floor]
    for c in cap:
        rr, gg, bb = c
        rep = factorial(rr+gg+bb) / (factorial(rr)*factorial(gg)*factorial(bb))
        if r >= rr and g >= gg and b >= bb: 
            ret = ret + check(floor-1, r-rr, g-gg, b-bb) * rep

    #print(f"fl{floor}, {r}:{g}:{b}, ret={ret}")
    return ret

res = check(N, R, G, B)
print(int(res))
