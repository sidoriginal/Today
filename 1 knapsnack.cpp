#include<iostream>
#include<cstring>
using namespace std;
int static t[1000][1000];

int solve(int value[],int weight[],int W,int n){
	if(W==0||n==0){
		return 0;
	}
	
	if(t[n][W]!=-1){
		return t[n][W];
	}
	
	if(weight[n-1]>W){
		t[n][W]=solve(value,weight,W,n-1);
		return t[n][W];
	}
	else{
		t[n][W]=max(solve(value,weight,W,n-1),value[n-1]+solve(value,weight,W-weight[n-1],n-1));
		return t[n][W];
	}
	
}

int main(){
    int n=3;
    int value[n]={60,100,120};
    int weight[n]={10,20,30};
    int W=50;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            t[i][j]=-1;
        }
    }
    cout<<solve(value,weight,W,n);
   
}