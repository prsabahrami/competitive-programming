n = int(input())
strt = 1
n -= 1
cnt = 9
while n > strt * cnt:
    n -= cnt * strt
    cnt *= 10
    strt += 1
ans = (8 + 2) ** (strt - 1)
ans += n // strt
print(str(ans)[n % strt])
