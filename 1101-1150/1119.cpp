#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int N,uq=1;
int pre[35],pos[35];
vector<int> ans,temp;
bool check(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2)return true;
    if(pre[l1]==pos[r2])return true;
    else return false;
}
void DFS(int l1,int r1,int l2,int r2,vector<int> &temp){
    if(temp.size()==N&&ans.size()==0){
        ans=temp;
        return;
    }
    if(l1>r1)return;
    int cnt=0;
    for(int i=0;i<=r1-l1;i++){
        if(check(l1+1,l1+i,l2,l2+i-1)&&check(l1+i+1,r1,l2+i,r2-1)){
            cnt++;
            DFS(l1+1,l1+i,l2,l2+i-1,temp);
            temp.push_back(pre[l1]);
            DFS(l1+i+1,r1,l2+i,r2-1,temp);
        }
    }
    if(cnt>1)uq=0;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>pre[i];
    for(int i=0;i<N;i++)cin>>pos[i];
    DFS(0,N-1,0,N-1,temp);
    if(uq)printf("Yes\n");
    else printf("No\n");
    for(int i=0;i<N;i++){
        cout<<ans[i];
        if(i<N-1)cout<<' ';
    }
}