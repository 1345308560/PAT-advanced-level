// 0:00 - 0:15 - 25分
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,cnt[15]={},root=0,cc=0;
vector<int> ans1;
struct Node{
    int key,l,r,level,cnt;
    bool operator<(Node other){
        if(level!=other.level)return level<other.level;
        else return cnt<other.cnt;
    }
}Nt[15];
void LMR(int r,int l){
    if(r==-1)return;
    Nt[r].level=l;
    LMR(Nt[r].r,l+1);
    ans1.push_back(r);
    Nt[r].cnt=cc++;
    LMR(Nt[r].l,l+1);
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        char c1,c2;
        cin>>c1>>c2;
        Nt[i].key=i;
        if(c1=='-')Nt[i].l=-1;
        else Nt[i].l=c1-'0';
        if(c2=='-')Nt[i].r=-1;
        else Nt[i].r=c2-'0';
        if(c1!='-')cnt[c1-'0']++;
        if(c2!='-')cnt[c2-'0']++;
    }
    for(int i=0;i<N;i++)if(cnt[i]==0)root=i;
    LMR(root,1);
    sort(Nt,Nt+N);
    for(int i=0;i<N;i++){
        cout<<Nt[i].key;
        if(i<N-1)cout<<' ';
    }
    cout<<endl;
    for(int i=0;i<N;i++){
        cout<<ans1[i];
        if(i<N-1)cout<<' ';
    }
}