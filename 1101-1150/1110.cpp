//12:45 - 13:01 - 19分
//      - 13:09 - 25分
// id应该是string
#include<iostream>
#include<algorithm>
using namespace std;
int N,root=0,cnt[25]={},t[25],flag=1;
string c1,c2;
struct Node{
    int l=-1,r=-1;
}Nt[25];
void DFS(int r,int pos){
    if(pos>=25||r==-1)return;
    t[pos]=r;
    DFS(Nt[r].l,pos*2+1);
    DFS(Nt[r].r,pos*2+2);
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>c1>>c2;
        if(c1!="-"){Nt[i].l=stoi(c1);cnt[Nt[i].l]++;}
        if(c2!="-"){Nt[i].r=stoi(c2);cnt[Nt[i].r]++;}
    }
    for(int i=0;i<N;i++)if(cnt[i]==0)root=i;
    fill(t,t+N,-1);
    DFS(root,0);
    for(int i=0;i<N;i++)if(t[i]==-1)flag=0;
    if(flag){
        cout<<"YES "<<t[N-1];
    }
    else{
        cout<<"NO "<<root;
    }
}