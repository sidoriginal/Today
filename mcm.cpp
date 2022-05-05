// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[1000][1000]={{-1}};
    int solve(int i,int j,int N,int arr[]){
        if(i>=j){
            return 0;
        }
         if(t[i][j]!=-1){
            return t[i][j];
        }
        int mn=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp=solve(i,k,N,arr)+solve(k+1,j,N,arr)+arr[i-1]*arr[k]*arr[j];
            if(temp<mn){
                mn=temp;
            }
        }
        return t[i][j]=mn;
        
    }

    int matrixMultiplication(int N, int arr[])
    {
       int i=1;
        int j=N-1;
        solve(i,j,N,arr);
    }
    
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
