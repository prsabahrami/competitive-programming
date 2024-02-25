x , y , z = map(int ,input().split())
if (x > y + z):
    print('+')
    exit()
if y > x + z:
    print('-')
    exit()
if y == x and z == 0:
    print(0)
    exit()
print('?')