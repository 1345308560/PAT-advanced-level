// 9:49 - 10:46 - 25分
#include<iostream>
#include<vector>
#include<map>
#define MAXN 0x7fffffff
using namespace std;
int N,K,w;
string beg,city1,city2,tar="ROM";
struct Node{
    string name;
    int happiness;
}Nc[205];
struct Edge{
    string name;
    int weight;
    Edge(string nn,int ww){
        name=nn;
        weight=ww;
    }
};
map<string,int> Mp; 
vector<string> ans;
vector<Edge> V[205];
void Dijkstra(){
    bool vis[205]={};
    int dis[205]={},cnt[205]={},father[205]={};
    int cnt2[205]={};
    int happiness[205]={};
    fill(cnt2,cnt2+N,0);
    fill(happiness,happiness+N,MAXN);
    fill(cnt,cnt+N,1);
    fill(dis,dis+N,MAXN);

    dis[Mp[beg]]=0;
    happiness[Mp[beg]]=0;
    for(int i=0;i<N;i++){
        int u=-1,MIN=MAXN;
        for(int j=0;j<N;j++){
            if(!vis[j]&&MIN>dis[j]){
                MIN=dis[j];
                u=j;
            }
        }
        if(u==-1)break;
        vis[u]=true;
        for(int j=0;j<V[u].size();j++){
            int dir=Mp[V[u][j].name];
            int w=V[u][j].weight;
            if(!vis[dir]&&dis[dir]>dis[u]+w){
                dis[dir]=dis[u]+w;
                cnt[dir]=1;
                cnt2[dir]=cnt2[u]+1;
                father[dir]=u;
                happiness[dir]=happiness[u]+Nc[dir].happiness;
            }
            else if(!vis[dir]&&dis[dir]==dis[u]+w){
                cnt[dir]+=cnt[u];
                if(happiness[dir]<happiness[u]+Nc[dir].happiness){
                    father[dir]=u;
                    happiness[dir]=happiness[u]+Nc[dir].happiness;
                }
                else if(happiness[dir]==happiness[u]+Nc[dir].happiness){
                    if(cnt2[dir]>cnt2[u]+1){
                        father[dir]=u;
                        cnt2[dir]=cnt2[u]+1;
                    }
                }
            }
        }
    }
    int temp=Mp[tar];
    while(temp!=0){
        ans.push_back(Nc[temp].name);
        temp=father[temp];
    }
    ans.push_back(beg);
    double ave=1.0*happiness[Mp[tar]]/(ans.size()-1);
    cout<<cnt[Mp[tar]]<<' '<<dis[Mp[tar]]<<' '<<happiness[Mp[tar]];
    cout<<' '<<(int)ave<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[ans.size()-1-i];
        if(i<ans.size()-1)cout<<"->";
    }
}
int main(){
    cin>>N>>K>>beg;
    Mp[beg]=0;
    for(int i=1;i<N;i++){
        cin>>Nc[i].name>>Nc[i].happiness;
        Mp[Nc[i].name]=i;
    }
    for(int i=0;i<K;i++){
        cin>>city1>>city2>>w;
        V[Mp[city1]].push_back(Edge(city2,w));
        V[Mp[city2]].push_back(Edge(city1,w));
    }
    Dijkstra();
}