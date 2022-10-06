#include<iostream>
#include<map>
using namespace std;
int N,M,num[10005],u=-1,m=-1;
int cnt[10005]={},cnt2[10005]={};
map<int,int> Mp;
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int MAX=-1;
        fill(cnt2,cnt2+N,0);
        Mp.clear();
        for(int j=0;j<N;j++){
            cin>>num[j];
            Mp[num[j]]++;
        }
        for(int j=0;j<N;j++){
            cnt2[j]=N-Mp[num[j]];
            MAX=max(MAX,cnt2[j]);
        }
        for(int j=0;j<N;j++)
            if(cnt2[j]==MAX)cnt[j]++;
    }
    for(int i=0;i<N;i++){
        if(cnt[i]>m){
            u=i;
            m=cnt[i];
        }
    }
    cout<<u+1;
}