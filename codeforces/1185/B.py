import sys
input = sys.stdin.readline

def chk(s, t):
    i = 0
    j = 0
    while True:
        if i < len(s) and j < len(t) and s[i] == t[j]:
            while j < len(t) - 1 and t[j+1] == t[j] and (i == len(s)-1 or s[i+1] != s[i]):
                j += 1
            i += 1
            j += 1
            # print(i, j)
            if i == len(s) and j == len(t):
                return "YES"
        else:
            return "NO"

for _ in range(int(input())):
    print(chk(input(), input()))