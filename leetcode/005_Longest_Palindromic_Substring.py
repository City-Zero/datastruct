class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        o = set(s)
        max1 = ''
        for data in o:
            l = []
            start = 0
            while True:
                index = s.find(data,start)
                if index == -1:
                    break
                else:
                    l.append(index)
                    start = index+1
            for i in l:
                for j in l:
                    tmp = s[i:j+1]
                    if tmp == tmp[::-1] and len(tmp) > len(max1):
                        max1 = tmp
        return max1

s = Solution()
print(s.longestPalindrome('applea'))
