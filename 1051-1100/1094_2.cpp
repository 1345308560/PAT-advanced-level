#include<iostream>
#include<vector>
#include<map>
using namespace std;
int N,M,id,K,ROOT=-1,num,ans1=-1,ans2;
vector<int> V[105];
map<int,int> Mp,level;
void DFS(int pos,int l){
    level[l]++;
    if(level[l]>ans1){
        ans1=level[l];
        ans2=l;
    }
    for(int i=0;i<V[pos].size();i++)
        DFS(V[pos][i],l+1);
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>id>>K;
        for(int j=0;j<K;j++){
            cin>>num;
            V[id].push_back(num);
            Mp[num]=1;
        }
    }
    for(int i=1;i<=N;i++)if(Mp.count(i)==0)ROOT=i;
    DFS(ROOT,1);
    cout<<ans1<<' '<<ans2;
}