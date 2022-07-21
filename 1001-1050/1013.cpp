// 11:35 - 11:50 AC
#include<iostream>
#include<vector>
using namespace std;
int N,M,K;
int f[1005];
vector<pair<int,int> > Vw;

int find_root(int n){
    if(n!=f[n]){
        f[n]=find_root(f[n]);
    }
    return f[n];
}

void m_union(int a,int b){
    int ra=find_root(a);
    int rb=find_root(b);
    if(ra==rb)return;
    else f[ra]=rb;
}

int main(){
    cin>>N>>M>>K;
    for(int i=0;i<M;i++){
        int l,r;
        cin>>l>>r;
        Vw.push_back(make_pair(l,r));
    }
    for(int i=0;i<K;i++){
        int r;
        cin>>r;
        for(int j=1;j<=N;j++)f[j]=j;
        for(int j=0;j<M;j++){
            if(Vw[j].first!=r&&Vw[j].second!=r){
                m_union(Vw[j].first,Vw[j].second);
            }
        }
        int cnt=0;
        for(int j=1;j<=N;j++)if(j==f[j]&&j!=r)cnt++;
        cout<<cnt-1;
        if(i<K-1)cout<<endl;
    }
}