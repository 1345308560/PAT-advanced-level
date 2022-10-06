#include<iostream>
#include<map>
using namespace std;
int N,num[100005],cnt1[100005]={},root=-1;
map<int,int> Rk;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
        if(num[i]!=-1)cnt1[num[i]]++;
    }
    for(int i=0;i<N;i++)
        if(cnt1[i]==0){
            root=i;
            break;
        }
    for(int i=1;root!=-1&&i<=N;i++){
        Rk[root]=i;
        root=num[root];
    }
    for(int i=0;i<N;i++){
        cout<<Rk[i];
        if(i<N-1)cout<<' ';
    }
}