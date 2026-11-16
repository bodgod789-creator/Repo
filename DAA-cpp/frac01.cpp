#include<iostream>
#include<algorithm>
using namespace std;


int knapsack(int weight[],int value[],int n,int capacity){
    int dp[n+1][capacity+1];

    for(int i=0;i<=n;i++){
        for(int w=0;w<=capacity;w++){
            if(i==0 || w==0){
                dp[i][w]=0;
            }
            else if(weight[i-1]<=w){
                dp[i][w]=max(value[i-1]+dp[i-1][w-weight[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][capacity];
}
int main(){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    int weight[n],value[n];
    cout<<"Enter the weights of the items: ";
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<"Enter the values of the items: ";
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    int capacity;
    cout<<"Enter the capacity of the knapsack: ";
    cin>>capacity;  

    cout<<"The maximum value that can be obtained is: "<<knapsack(weight,value,n,capacity)<<endl;
    
    return 0;
}



// Enter the number of items: 4
// Enter the weights of the items: 1 3 4 5
// Enter the values of the items: 1 4 5 7
// Enter the capacity of the knapsack: 7
// The maximum value that can be obtained is: 9