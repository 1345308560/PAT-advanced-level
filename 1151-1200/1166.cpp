#include<iostream>
using namespace std;
int N,M,K,num1,num2,num[205],n;
int mp[205][205]={};
bool check2(int x){
    for(int i=0;i<n;i++)if(mp[x][num[i]]==0)return false;
    return true;
}
void check(int id){
    bool flag1=true;
    bool vis[205]={};
    for(int i=0;i<n;i++){
        if(!flag1)break;
        vis[num[i]]=true;
        for(int j=i+1;j<n;j++)
            if(mp[num[i]][num[j]]==0){
                flag1=false;
            }
    }
    if(!flag1)cout<<"Area "<<id+1<<" needs help.\n";
    else{
        for(int i=1;i<=N;i++){
            if(!vis[i]){
                if(check2(i)){
                    cout<<"Area "<<id+1<<" may invite more people, such as "<<i<<".\n";
                    return;
                }
            }
        }
        cout<<"Area "<<id+1<<" is OK.\n";
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        mp[num1][num2]=1;
        mp[num2][num1]=1;
    }
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>n;
        for(int j=0;j<n;j++)cin>>num[j];
        check(i);
    }
}