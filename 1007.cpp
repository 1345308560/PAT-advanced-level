#include<iostream>

using namespace std;

int K;
int num[10005];

int main(){
    cin>>K;
    for(int i=0;i<K;i++)cin>>num[i];

    bool f=true;
    for(int i=0;i<K;i++)if(num[i]>=0)f=false;
    if(f){
        cout<<0<<" "<<num[0]<<" "<<num[K-1];
        return 0;
    }

    int l=0,r=0,nowAns=0,ans=-999,al=0,ar=0;
    while(l<K&&r<K){
        nowAns+=num[r];
        if(nowAns>ans){
            ans=nowAns;
            al=l;
            ar=r;
        }
        if(nowAns>0)r++;
        else{
            nowAns=0;
            l=r+1;
            r=r+1;
        }
    }
    cout<<ans<<" "<<num[al]<<" "<<num[ar];
}