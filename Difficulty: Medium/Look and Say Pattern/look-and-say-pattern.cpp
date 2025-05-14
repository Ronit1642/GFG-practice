//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        vector<string>ans(n,"");
        ans[0]="1";
        
        for(int i=1;i<n;i++){
            int cnt=1;
            for(int j=1;j<=ans[i-1].size();j++){
                if(j<ans[i-1].size() && ans[i-1][j]==ans[i-1][j-1]){
                    cnt++;
                }
                else{
                    ans[i]+=to_string(cnt)+ans[i-1][j-1];
                    cnt=1;
                }
            }
            
        }
        
        return ans[n-1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends