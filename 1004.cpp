#include<vector>
#include<iostream>
#include<algorithm>

#define INF 0x7fffffff

using namespace std;

int h[105];
int N,M;
int ans[105]={0};
vector<int> V[105];

int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        string str;
        cin>>str;
        int index=stoi(str);
        int K;
        cin>>K;
        for(int i=0;i<K;i++){
            string str1;
            cin>>str1;
            V[index].push_back(stoi(str1));
        }
    }
    for(int i=0;i<105;i++)
        if(V[i].size()>0)
            sort(V[i].begin(),V[i].end());
    for(int i=0;i<105;i++)h[i]=INF;
    int hiMax=0;
    h[1]=0;
    for(int i=0;i<105;i++)
        if(V[i].size()>0){
            for(int j=0;j<V[i].size();j++){
                h[V[i][j]]=h[i]+1;
                hiMax=max(hiMax,h[V[i][j]]);
            }
        }
    for(int i=0;i<105;i++)
        if(h[i]<INF){
            if(V[i].size()==0)ans[h[i]]++;
        }
    for(int i=0;i<=hiMax;i++){
        cout<<ans[i];
        if(i<hiMax)cout<<' ';
    }
}