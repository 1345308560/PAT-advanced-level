#include<iostream>
#include<vector>
using namespace std;
vector<int> V[1005];
bool vis[1005];
int N,M,K,num1,num2,num[1005];
bool check(){
    fill(vis,vis+N+1,false);
    vis[num[0]]=true;
    for(int i=1;i<N;i++){
        if(vis[num[i]])return false;
        int cnt=0,find_path=0;
        for(int j=0;j<V[num[i-1]].size();j++){
            if(!vis[V[num[i-1]][j]]){
                cnt++;
                if(V[num[i-1]][j]==num[i])find_path=1;
            }
        }
        vis[num[i]]=true;
        if(find_path==0&&cnt>0)return false;
    }
    return true;
}
int main(){
    cin>>N>>M>>K;
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        V[num1].push_back(num2);
    }
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++)cin>>num[j];
        if(check())cout<<"yes\n";
        else cout<<"no\n";
    }
}