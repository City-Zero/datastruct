from functools import reduce
class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        if len(str) == 0:
            return 0
        flag = None
        for i in str:
            if i != ' ':
                ind = str.find(i)
                str = str[ind:]
                break
        if len(str) == 0:
            return 0
        if str[0] == '-':
            flag = -1
            str = str[1:]
        elif str[0] == '+':
            flag = 1
            str = str[1:]
        else:
            flag = 1
        end = len(str)
        if end == 0:
            return 0
        for index,data in enumerate(str):
            if not '0'<=data<='9':
                end = index
                break
        str = str[:end]

        str = str.replace(' ','')

        if len(str) == 0:
            return 0
        ret = reduce(lambda x,y:x*10+y,map(lambda x:ord(x)-ord('0'),str))
        ret = ret * flag
        if ret > 2147483647:
            ret = 2147483647
        elif(ret < -2147483648):
            ret = -2147483648
        return ret


s = Solution()
print(s.myAtoi('1'))