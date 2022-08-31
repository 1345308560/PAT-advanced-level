#include<iostream>
#include<cmath>
#define MAXN 10005
using namespace std;
bool isRB=true;
int K,N,num[55],ans=-1;
int tree[MAXN];
void InTree(int pos,int l,int r){
    if(l>r)return;
    tree[pos]=num[l];
    int p=l;
    for(;p<=r;p++)if(fabs(num[p])>fabs(num[l]))break;

    InTree(pos*2+1,l+1,p-1);
    InTree(pos*2+2,p,r);
}
void checkPath(int pos,int cnt){
    if(tree[pos]==0||pos>=MAXN){
        if(ans==-1)ans=cnt;
        else if(ans!=cnt)isRB=false;
        return ;
    }
    if(tree[pos]>0)cnt++;
    checkPath(pos*2+1,cnt);
    checkPath(pos*2+2,cnt);
    if(tree[pos]>0)cnt--;
}
void checkRB(int pos){
    if(tree[pos]==0||pos>=MAXN)return;
    if(tree[pos]<0){
        if(pos*2+1<MAXN&&tree[pos*2+1]<0)isRB=false;
        if(pos*2+2<MAXN&&tree[pos*2+2]<0)isRB=false;
    }
    checkRB(pos*2+1);
    checkRB(pos*2+2);
}
bool check(){
    // 都是红黑
    for(int i=0;i<N;i++)if(num[i]==0)return false;
    // 根是黑
    if(num[0]<0)return false;
    // 放入树中
    fill(tree,tree+MAXN,0);
    InTree(0,0,N-1);
    // 红的子节点都是黑
    checkRB(0);
    if(!isRB)return false;
    // 所有路径的黑个数相同
    for(int i=0;i<MAXN;i++)
        if(tree[i]!=0){
            ans=-1;
            checkPath(i,0);
            if(!isRB)return false;
        }
    return true;
}
int main(){
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>N;
        for(int j=0;j<N;j++)cin>>num[j];
        if(check())cout<<"Yes\n";
        else cout<<"No\n";
    }
}