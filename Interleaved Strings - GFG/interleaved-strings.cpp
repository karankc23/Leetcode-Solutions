// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int dp[101][101];
    bool solve(string &s1, string &s2, string &s3, int l1, int l2,int l3){
        if(l1<0 && l2<0 && l3<0) {
            return true;
        }
        if(l1>=0 && l2>=0 && dp[l1][l2]!=-1) {
            return dp[l1][l2];
        }
        if(l1>=0 && s1[l1]==s3[l3] && l2>=0 && s2[l2]==s3[l3] ) {
            return dp[l1][l2] = (solve(s1, s2, s3, l1-1, l2, l3-1) || solve(s1, s2, s3, l1, l2-1, l3-1));
        }
        else if(l1>=0 && s1[l1]==s3[l3])
            return  solve(s1, s2, s3, l1-1, l2, l3-1);
        
        else if(l2>=0 &&s2[l2]==s3[l3])
            return solve(s1, s2, s3, l1, l2-1, l3-1);
        
        else return false;
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        //Your code here
        if(s3.size()!=s1.size() + s2.size())return false;
        memset(dp,-1,sizeof(dp));
        
        return solve(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends