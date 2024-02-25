from math import*
import sys
input = sys.stdin.readline
n = int(input())
l = []
l2 = []
for i in range(n):
     bib = float(input())
     l.append(bib)
     if (int(bib) == bib):
          l2.append(bib)
     else:
          l2.append(ceil(bib))
ss = sum(l2)
ind = 0
for i in range(n):
     if l[i] != l2[i]:
          if ss > 0:
               l2[i] -= 1
               ss -= 1
          if ss == 0:
               break
for i in l2:
     print(int(i))
