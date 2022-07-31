//11:29 - 11:42 - 23分
//      - 11:59 - 25分
// 漏掉了num[0]==0的情况
#include<iostream>
using namespace std;
int N,num[1000005],root[100005],cnt,cnt2=0;
bool flag[1000005];
int find_root(int num){
    if(num!=root[num])root[num]=find_root(root[num]);
    return root[num];
}
void m_union(int a,int b){
    int ra=find_root(a),rb=find_root(b);
    if(ra!=rb)root[ra]=rb;
}
int main(){
    cin>>N;
    cnt=N;
    for(int i=0;i<N;i++)root[i]=i;
    for(int i=0;i<N;i++){
        cin>>num[i];
        if(num[i]==i){flag[i]=false;cnt--;}
        else {flag[i]=true;m_union(num[i],i);}
    }
    for(int i=0;i<N;i++)
        if(flag[i]&&find_root(i)==i)
            cnt2++;
    if(num[0]==0)cout<<max(cnt+cnt2,0);
    else cout<<max(cnt+cnt2-2,0);
}