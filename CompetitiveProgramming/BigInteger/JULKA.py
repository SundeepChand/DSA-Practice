t = 10

while t > 0:
    t -= 1
    n = int(input())
    k = int(input())
    x2 = n + k
    if x2 % 2 == 1:
        x = x2 // 2
        print(x)
        print(n - x)
        continue
    x = x2 // 2
    print(x)
    print(x - k)
