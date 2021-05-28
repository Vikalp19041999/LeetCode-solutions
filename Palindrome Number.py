class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        temp = x
        rev = 0
        while(x > 0):
            d = x % 10
            rev = rev * 10 + d
            x = x // 10
        print(rev)
        if(temp == rev):
            return True
        else:
            return False
        