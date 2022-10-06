#include<iostream>
#include<algorithm>
using namespace std;
int N,cnt2=0;
struct Node{
    int data,level,cnt;
    bool operator<(const Node other)const{
        if(level!=other.level)return level<other.level;
        else return cnt<other.cnt;
    }
}Nt[35];
void check(int l,int r,int le){
    if(l>r)return;
    int root=0x7fffffff,pos;
    for(int i=l;i<=r;i++)
        if(root>Nt[i].data){
            pos=i;
            root=Nt[i].data;
        }
    Nt[pos].level=le;
    Nt[pos].cnt=cnt2++;
    check(l,pos-1,le+1);
    check(pos+1,r,le+1);
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>Nt[i].data;
    check(0,N-1,0);
    sort(Nt,Nt+N);
    for(int i=0;i<N;i++){
        cout<<Nt[i].data;
        if(i<N-1)cout<<' ';
    }
}