//23:05 - 23:14 - 25分
#include<iostream>
using namespace std;
int N,in[50005],pre[50005],find_ans=0,ans;
void f(int l1,int r1,int l2,int r2){
    if(find_ans)return;
    if(l1>r1)return;
    int root=pre[l1],pos=l2;
    for(;pos<=r2;pos++)if(in[pos]==root)break;
    f(l1+1,l1+pos-l2,l2,pos-1);
    f(l1+pos-l2+1,r1,pos+1,r2);
    if(find_ans)return;
    ans=root;
    find_ans=1;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>pre[i];
    for(int i=0;i<N;i++)cin>>in[i];
    f(0,N-1,0,N-1);
    cout<<ans;
}