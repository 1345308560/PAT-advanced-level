//10:45 - 11:04 - 25分
#include<iostream>
#include<vector>
using namespace std;
int N,M,K,n,num1,num2,num[1000];
vector<int> V[205];
bool check(int s){
    if(s!=N+1)return false;
    if(num[0]!=num[s-1])return false;

    bool vis[205];
    fill(vis,vis+205,false);
    for(int i=0;i<s-1;i++){
        if(vis[num[i]])return false;
        bool find_path=false;
        for(int j=0;j<V[num[i]].size();j++)
            if(V[num[i]][j]==num[i+1])find_path=true;
        if(!find_path)return false;
        vis[num[i]]=true;
    }
    return true;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        V[num1].push_back(num2);
        V[num2].push_back(num1);
    }
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>num[j];
        if(check(n))cout<<"YES\n";
        else cout<<"NO\n";
    }
}