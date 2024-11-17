//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        int n=arr.size();

        vector<pair<int,int>>v;

        for(auto &it:arr){

            //pushing (the ending time,starting time)

            v.push_back({it[1],it[0]});

        }

        //sorting according to ending time

        sort(v.begin(),v.end());

        int e=v[0].first;

        for(int i=1;i<n;i++){

            //comparing the starting time with earliest ending time

            //if starting time is less than e overlap occurs

            if(v[i].second<e){

                return false;

            }

            //assigning e for subsequent comparison 

            e=v[i].first;

        }

        return true;


    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends

// by Ronit
