// 23:08 - 23:19 - 30分
// 中序遍历->层序遍历
#include<iostream>
#include<algorithm>
using namespace std;
int N,num[105],cnt=0,cnt2=0;
struct Node{
    int l,r,number,level,pos;
    bool operator<(const Node other){
        if(level!=other.level)return level<other.level;
        else return pos<other.pos;
    } 
}Nt[105];
void DFS(int root,int l){
    if(root==-1)return;
    DFS(Nt[root].l,l+1);
    Nt[root].level=l;
    Nt[root].pos=cnt2++;
    Nt[root].number=num[cnt++];
    DFS(Nt[root].r,l+1);
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>Nt[i].l>>Nt[i].r;
    for(int i=0;i<N;i++)
        cin>>num[i];
    sort(num,num+N);
    DFS(0,0);
    sort(Nt,Nt+N);
    for(int i=0;i<N;i++){
        cout<<Nt[i].number;
        if(i<N-1)cout<<' ';
    }
}