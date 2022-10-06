#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N,K,M,pre[55],level[155],cnt[155]={},cnt2=0,x;
int fa[155]={};
void f(int l,int r,int le,int father){
    if(l>r||l>=N)return;
    int pos[105]={},res=r-l;
    for(int i=0;res>0;i++){
        for(int j=0;j<K;j++){
            if(res<0)break;
            pos[j]+=min((int)pow(K,i),res);
            res-=pow(K,i);
        }
    }
    level[pre[l]]=le;
    cnt[pre[l]]=cnt2++;
    fa[pre[l]]=father;
    int ll=l+1,rr=l+pos[0];
    for(int i=0;i<K;i++){
        rr=ll+pos[i]-1;
        if(pos[i]<0)break;
        f(ll,rr,le+1,pre[l]);
        ll=rr+1;
    }
}
bool cmp(int a,int b){
    if(level[a]!=level[b])return level[a]<level[b];
    else return cnt[a]<cnt[b];
}
void DFS(int x){
    vector<int> temp;
    while(x!=-1){
        temp.push_back(x);
        x=fa[x];
    }
    for(int i=0;i<temp.size();i++){
        cout<<temp[i];
        if(i<temp.size()-1)cout<<' ';
    }
}
int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++)cin>>pre[i];
    f(0,N-1,0,-1);
    sort(pre,pre+N,cmp);
    for(int i=0;i<N;i++){
        cout<<pre[i];
        if(i<N-1)cout<<' ';
    }
    cout<<endl;
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>x;
        x=pre[x];
        DFS(x);
        cout<<endl;
    }
}