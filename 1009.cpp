#include<iostream>
#include<cstdio>
using namespace std;

double num[2005];

struct Node{
    int N;
    double aN;
}N1[10005],N2[10005];

int main(){
    for(int i=0;i<20005;i++)num[i]=0;
    int K1,K2;
    cin>>K1;
    for(int i=0;i<K1;i++){
        cin>>N1[i].N>>N1[i].aN;
    }
    cin>>K2;
    for(int i=0;i<K2;i++){
        cin>>N2[i].N>>N2[i].aN;
    }
    for(int i=0;i<K1;i++){
        for(int j=0;j<K2;j++){
            num[N1[i].N+N2[j].N]+=N1[i].aN*N2[j].aN;
        }
    }
    int cnt=0;
    for(int i=0;i<2005;i++)if(num[i]!=0)cnt++;
    cout<<cnt;
    for(int i=2004;i>=0;i--)if(num[i]!=0)printf(" %d %.1f",i,num[i]);
}