#include<iostream>
using namespace std;

void nrecursive(int n){
    int a=0, b=1,c;
    cout<<a<<" "<<b<<" ";
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
        cout<<c<<" ";
    }
    
}
int recursive(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return recursive(n-1)+recursive(n-2);
}
int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"The Fibonacci series up to "<<n<<" terms is: ";
    for(int i=0;i<=n;i++){
        cout<<recursive(i)<<" ";
    }
    cout<<endl;
    return 0;
}