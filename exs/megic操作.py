# coding=utf-8
import sys

(m,n) = sys.stdin.readline().split()
m = int(m)
n = int(n)
lm = [int(i) for i in sys.stdin.readline().split()]
ln = [int(i) for i in sys.stdin.readline().split()]

#求平均值
aver_m = sum(lm) / m
aver_n = sum(ln) / n
#排序
lm.sort()
ln.sort()

#定义magic操作的次数
times = 0

while True:
    #记录要操作的元素
    data = None

    #记录取元素和追加元素的列表
    item_remove = lm
    item_append = ln

    for i in lm:
        #因为已经排序了，所以遇到大于平均值的就不用去找了
        if i >= aver_m:
            break
        else:
            if i > aver_n and i not in ln:
                data = i
                break
    if not data:
        #在第一个列表里找不到就去第二个找
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
        #优化了求平均值
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