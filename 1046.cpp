#include<iostream>
using namespace std;
int N,M;
int num[100005];
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>num[i];
        num[i]+=num[i-1];
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int aa,bb,a,b;
        cin>>aa>>bb;
        a=min(aa,bb);
        b=max(aa,bb);
        cout<<min(num[b-1]-num[a-1],num[N]-num[b-1]+num[a-1]);
        if(i<M-1)cout<<endl;
    }
}