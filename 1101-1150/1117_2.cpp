#include<algorithm>
#include<iostream>
using namespace std;
int N,num[100005];
bool check(int n){
    int pos=lower_bound(num,num+N,n)-num;
    if(N-pos>=n)return true;
    else return false;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>num[i];
    sort(num,num+N);
    // for(int i=0;i<N;i++)cout<<num[i]<<' ';
    // cout<<endl;
    int l=0,r=num[N-1];
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l;
}