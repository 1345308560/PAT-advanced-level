//16:41 - 16:46 - 30分
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int in[35],pos[35],cnt=0;
struct Node{
    int key,level,cnt;
    bool operator<(const Node& other){
        if(level!=other.level)return level<other.level;
        else{
            if(level%2==1)
                return this->cnt>other.cnt;
            else return this->cnt<other.cnt;
        }
    }
}Nt[35];
void f(int l1,int r1,int l2,int r2,int l){
    if(l1>r1)return;
    int root=pos[r2],position;
    for(int i=l1;i<=r1;i++)
        if(in[i]==root){
            position=i;
            break;
        }
    Nt[cnt].key=root;
    Nt[cnt].level=l;
    Nt[cnt].cnt=cnt;
    cnt++;
    f(l1,position-1,l2,l2+position-l1-1,l+1);
    f(position+1,r1,l2+position-l1,r2-1,l+1);
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>in[i];
    for(int j=0;j<N;j++)cin>>pos[j];
    f(0,N-1,0,N-1,1);
    sort(Nt,Nt+cnt);
    for(int i=0;i<N;i++){
        cout<<Nt[i].key;
        if(i<N-1)cout<<' ';
    }
}