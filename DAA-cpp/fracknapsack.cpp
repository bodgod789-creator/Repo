#include<iostream>
#include<algorithm>
using namespace std;


struct Item{
    int weight;
    int value;
    double ratio;
};
bool compare(Item a,Item b){
    return a.ratio>b.ratio;
}

double fractionalknapsack(Item arr[],int n,int capacity){
    for(int i=0;i<n;i++){
        arr[i].ratio=(double)arr[i].value/arr[i].weight;
    }
    sort(arr,arr+n,compare);
    double totalvalue=0;

    for(int i=0;i<n;i++){
        if(arr[i].weight<=capacity){
            capacity-=arr[i].weight;
            totalvalue+=arr[i].value;
        }
        else{
            totalvalue+=arr[i].ratio*capacity;
            capacity=0;
            break;
        }
    }
    return totalvalue;
}
int main(){
    int n,capacity;
    cout<<"Enter the number of items: ";
    cin>>n;
    Item arr[n];
    cout<<"Enter the weight and value of each item: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i].weight>>arr[i].value;
    }
    cout<<"Enter the capacity of the knapsack: ";
    cin>>capacity;
    double maxvalue=fractionalknapsack(arr,n,capacity);
    cout<<"The maximum value in the knapsack is: "<<maxvalue<<endl;
    return 0;
}




// Enter the number of items: 3
// Enter the weight and value of each item: 
// 10 60
// 20 100
// 30 120
// Enter the capacity of the knapsack: 50
// The maximum value in the knapsack is: 240