t = int(input().strip())
while t > 0:
    t = t - 1
    n = int(input().strip())
    a = input().split()
    a.sort()
    pos = 0
    for i in range(len(a)):
        if a[i] > '0':
            pos = i
            break
    tt = a[pos]
    a[pos] = a[0]
    a[0] = tt
    tt = a[pos + 1]
    a[pos + 1] = a[1]
    a[1] = tt
    s = ""
    x = int(a[0])
    y = 0
    for i in range(1, len(a)):
        y = y * 10 + int(a[i])
    print(x * y)