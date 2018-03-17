s = "ABCDEF"
numRows = 3
res = []
for _ in range(numRows):
    res.append([])
flag = True
index = 0
for data in s:
    res[index%numRows].append(data)
    print(data,str(index%numRows),str(index))
    if flag:
        index+=1
    else:
        index-=1
    if index == numRows-1 or index == 0:
        flag = not flag
ret = []
for i in res:
    ret += i
print(''.join(ret))