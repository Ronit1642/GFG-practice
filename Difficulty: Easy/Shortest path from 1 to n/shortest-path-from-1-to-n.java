//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int n = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.minStep(n));
        
System.out.println("~");
}
    }
}
// } Driver Code Ends

// Created by Ronit Kumar


class Solution{
    public int minStep(int n){
          if(n==1) return 0;
        if(n%3==0) return 1+minStep(n/3);
        return 1+minStep(n-1);
    }
}
