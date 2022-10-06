#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,ans=0;
int num[100005]={};
int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>num[i];
        num[i]+=num[i-1];
    }
    for(int i=0;i<N;i++){
        int pos=i+1;
        for(int j=i+1;j<=N;j++){
            if(num[j]-num[i]>M){
                break;
            }
            pos=j;
        }
        if(pos==i+1&&num[pos]-num[i]>M);
        else ans+=pos-i;
    }
    cout<<ans;
}