#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

double num[1005]={};
int k1,k2;

int main(){
    cin>>k1;
    for(int i=0;i<k1;i++){
        int n;double an;
        cin>>n>>an;
        num[n]+=an;
    }
    cin>>k2;
    for(int i=0;i<k2;i++){
        int n;double an;
        cin>>n>>an;
        num[n]+=an;
    }
    int cnt=0;
    for(int i=0;i<1005;i++)if(num[i]>0)cnt++;
    cout<<cnt;
    for(int i=1004;i>=0;i--){
        if(num[i]>0)
            printf(" %d %.1f",i,num[i]);
    }
}