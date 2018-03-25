# coding=utf-8
import sys

(m,n) = sys.stdin.readline().split()
m = int(m)
n = int(n)
lm = [int(i) for i in sys.stdin.readline().split()]
ln = [int(i) for i in sys.stdin.readline().split()]

aver_m = sum(lm) / m
aver_n = sum(ln) / n
lm.sort()
ln.sort()
print(lm,ln)
times = 0
while True:
    data = None
    item_remove = lm
    item_append = ln
    for i in lm:
        if i >= aver_m:
            break
        else:
            if i > aver_n and i not in ln:
                data = i
                break
    if not data:
        for i in ln:
            if i >= aver_n:
                break
            else:
                if i > aver_m and i not in lm:
                    item_append = lm
                    item_remove = ln
                    data = i
                    break
    if not data:
        break
    else:
        times += 1
        item_remove.remove(data)
        item_append.append(data)
        if item_remove is lm:
            m -= 1
            n += 1
            aver_m = (aver_m * (m + 1) - data) / m
            aver_n = (aver_n * (n - 1) + data) / n
        else:
            m += 1
            n -= 1
            aver_m = (aver_m * (m - 1) + data) / m
            aver_n = (aver_n * (n + 1) - data) / n
print(times)