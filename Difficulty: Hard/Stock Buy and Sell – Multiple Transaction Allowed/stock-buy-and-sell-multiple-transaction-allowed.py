from typing import List


class Solution:
    def maximumProfit(self,prices) -> int:
        # code here
        p = 0
        n=len(prices)
        for i in range(1,n):
            if prices[i] > prices[i-1]:
                p += prices[i] - prices[i-1]
        return p



#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        solution = Solution()
        res = solution.maximumProfit(arr)
        print(res)

# } Driver Code Ends