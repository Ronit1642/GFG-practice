
class Solution:
    def countDistinct(self, arr, k):
        # Code here
        i=0
        j=k-1
        d={}
        c=[]
        s=0
        for x in range(0,k):
            if arr[x] not in d.keys():
                d[arr[x]]=1
                s=s+1
            else:
                d[arr[x]]+=1
        c.append(s)      
        d[arr[0]]-=1
        if d[arr[i]]==0:
            s=s-1
        i=i+1
        j=j+1
        while j<len(arr):
            if arr[j] not in d.keys() or d[arr[j]]==0:
                d[arr[j]]=1
                s=s+1
            else:
                d[arr[j]]+=1
            c.append(s)
            d[arr[i]]-=1
            if d[arr[i]]==0:
                s=s-1
            i=i+1
            j=j+1
        return c

#{ 
 # Driver Code Starts
import sys
from collections import defaultdict
if __name__ == '__main__':
    input = sys.stdin.read
    data = input().splitlines()
    t = int(data[0])
    index = 1
    while t > 0:
        arr = list(map(int, data[index].strip().split()))
        index += 1
        k = int(data[index])
        index += 1

        ob = Solution()
        res = ob.countDistinct(arr, k)

        for element in res:
            print(element, end=" ")
        print()
        print("~")

        t -= 1

# } Driver Code Ends