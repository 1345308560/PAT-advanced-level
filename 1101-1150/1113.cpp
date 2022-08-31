#include<iostream>
#include<algorithm>
using namespace std;
int N,num[100005];
int del=0,sum=0;
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>num[i];
    sort(num,num+N);
    if(N%2==0)del=0;
    else del=1;
    for(int i=0;i<N/2;i++)
        sum+=(num[i+N/2]-num[i]);
    if(del)sum+=num[N-1];
    cout<<del<<' '<<sum;
}