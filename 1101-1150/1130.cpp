//23:34 - 23:44 - 25分
#include<iostream>
using namespace std;
int N,cnt[25]={},root=1;
struct Node{
    string key;
    int left,right;
}Nt[25];
void LMR(int r){
    if(r==-1)return;
    bool f=true;
    if(Nt[r].left==-1&&Nt[r].right==-1)f=false;
    if(r==root)f=false;
    if(f)cout<<'(';
    LMR(Nt[r].left);
    cout<<Nt[r].key;
    LMR(Nt[r].right);
    if(f)cout<<')';
}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>Nt[i].key>>Nt[i].left>>Nt[i].right;
        if(Nt[i].left!=-1)cnt[Nt[i].left]++;
        if(Nt[i].right!=-1)cnt[Nt[i].right]++;
    }
    for(int i=1;i<=N;i++)if(cnt[i]==0)root=i;
    LMR(root);
}