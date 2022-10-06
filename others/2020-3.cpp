
#include<vector>
#include<iostream>
using namespace std;
int N;
int in[25],pos[25],level_cnt[25]={};
vector<int> ans;
void f(int l1,int r1,int l2,int r2,int l){
    if(l1>r1)return;
    int root=pos[l2],pos=l1;
    for(;pos<=r1;pos++)if(in[pos]==root)break;

    if(level_cnt[l]==0){
        ans.push_back(root);
        level_cnt[l]=1;
    }
    f(l1,pos-1,l2+1,l2+pos-l1,l+1);
    f(pos+1,r1,l2+pos-l1+1,r2,l+1);
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>in[i];
    for(int j=0;j<N;j++)cin>>pos[j];
    f(0,N-1,0,N-1,0);
    for(int  i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i<ans.size()-1)cout<<' ';
    }
}