#User function Template for python3
class Solution:
	def addBinary(self, s1, s2):
	    
		# code here
		if len(s1)<len(s2):
		    s1,s2=s2,s1
        s2="0"*(len(s1)-len(s2))+s2
 
        def helper(b1,b2,car):
            if b1=="1" and b2=="1" and car=="1":
                return ["1","1"]
            elif b1=="1" and b2=="1" and car=="0":
                return ["0","1"]
            elif (b1=="1" or b2=="1") and car=="1":
                return ["0","1"]
            elif (b1=="1" or b2=="1") and car=="0":
                return ["1","0"]
            elif b1=="0" and b2=="0" and car=="1":
                return ["1","0"]
            else:
                return ["0","0"]
                
        carry="0"
        res=""
        for i in range(len(s2)-1,-1,-1):
            cur=helper(s1[i],s2[i],carry)
            val,carry=cur[0],cur[1]
            res=val+res
        if carry=="1":
            res=carry+res
        i=0
        while i<len(res):
            if res[i]!="0":
                break
            i+=1
        return res[i:]
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        a = input().strip()
        b = input().strip()
        ob = Solution()
        answer = ob.addBinary(a, b)

        print(answer)
        print("~")

# } Driver Code Ends