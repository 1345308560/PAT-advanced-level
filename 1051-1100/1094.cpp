//16:17 - 16:45 - 23分
//      - 16:49 - 25分
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N,M,ID,K,num,root=-1,ans1=-1,ans2=-1;
int has_father[105]={};
bool vis[105]={};
vector<int> V[105];
queue<int> Q;
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>ID>>K;
        for(int j=0;j<K;j++){
            cin>>num;
            has_father[num]=true;
            V[ID].push_back(num);
        }
    }
    for(int i=0;i<105;i++)
        if(V[i].size()>0&&!has_father[i])
            root=i;
    Q.push(root);
    vis[root]=true;
    for(int i=1;!Q.empty();i++){
        int s=Q.size();
        if(s>ans2){
            ans2=s;
            ans1=i;
        }
        for(int j=0;j<s;j++){
            int id=Q.front();
            Q.pop();
            for(int k=0;k<V[id].size();k++)
                if(!vis[V[id][k]])
                    Q.push(V[id][k]);
        }
    }
    cout<<ans2<<' '<<ans1;
}