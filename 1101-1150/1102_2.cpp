#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,cnt[15],ROOT=-1;
int level[15],cnt2[15],cnt3=0;
struct Node{
    int l=-1,r=-1;
}Nt[15];
char c1,c2;
vector<int> ans1,ans2;
void LMR(int n){
    if(n==-1)return;
    LMR(Nt[n].r);
    ans1.push_back(n);
    LMR(Nt[n].l);
}
void cnt_level(int n,int l){
    if(n==-1)return;
    level[n]=l;
    cnt2[n]=cnt3++;
    cnt_level(Nt[n].l,l+1);
    cnt_level(Nt[n].r,l+1);
}
bool cmp(int a,int b){
    if(level[a]!=level[b])return level[a]<level[b];
    else return cnt2[a]>cnt2[b];
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>c1>>c2;
        if(c1!='-'){Nt[i].l=c1-'0';cnt[Nt[i].l]=1;}
        if(c2!='-'){Nt[i].r=c2-'0';cnt[Nt[i].r]=1;}
    }
    for(int i=0;i<N;i++)if(cnt[i]==0)ROOT=i;
    cnt_level(ROOT,0);
    for(int i=0;i<N;i++)ans2.push_back(i);
    sort(ans2.begin(),ans2.end(),cmp);
    for(int i=0;i<N;i++){
        cout<<ans2[i];
        if(i<N-1)cout<<' ';
        else cout<<endl;
    }
    LMR(ROOT);
    for(int i=0;i<N;i++){
        cout<<ans1[i];
        if(i<N-1)cout<<' ';
        else cout<<endl;
    }
}