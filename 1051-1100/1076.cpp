//14:59 - 15:11 - 30分
// BFS
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N,L,K,ans;
vector<int> V[1005];
bool vis[1005];
void f(int num){
    queue<int> Q;
    fill(vis,vis+N+1,false);
    ans=0;
    vis[num]=true;
    Q.push(num);

    for(int i=0;i<L;i++){
        int s=Q.size();
        for(int j=0;j<s;j++){
            int id=Q.front();
            Q.pop();
            for(int k=0;k<V[id].size();k++)
                if(!vis[V[id][k]]){
                    Q.push(V[id][k]);
                    vis[V[id][k]]=true;
                    ans++;
                }
        }
    }
}

int main(){
    cin>>N>>L;
    for(int i=1;i<=N;i++){
        int id,num;
        cin>>num;
        for(int j=0;j<num;j++){
            cin>>id;
            V[id].push_back(i);
        }
    }
    cin>>K;
    for(int i=0;i<K;i++){
        int num;
        cin>>num;
        f(num);
        cout<<ans;
        if(i<K-1)cout<<endl;
    }
}