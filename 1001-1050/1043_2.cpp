#include<iostream>
#include<vector>
using namespace std;
int N,ROOT=-1,num[1005],is_b=true,is_bm=true;
vector<int> ans;
struct Node{
    int l=-1,r=-1;
}Nt[1005];
void check(int l,int r){
    // cout<<l<<' '<<r<<endl;
    if(l>r)return;
    int root=num[l],pos=-1;
    for(int i=l+1;i<=r;i++)if(num[i]>=root){pos=i;break;}
    if(pos==-1){
        check(l+1,r);
        ans.push_back(root);
    }
    else{
        for(int i=pos;i<=r;i++)if(num[i]<root)is_b=false;
        if(is_b){
            check(l+1,pos-1);
            check(pos,r);
            ans.push_back(root);
        }
    }
}
void check2(int l,int r){
    if(l>r)return;
    int root=num[l],pos=-1;
    for(int i=l+1;i<=r;i++)if(num[i]<root){pos=i;break;}
    if(pos==-1){
        check2(l+1,r);
        ans.push_back(root);
    }
    else{
        for(int i=pos;i<=r;i++)if(num[i]>=root)is_bm=false;
        if(is_bm){
            check2(l+1,pos-1);
            check2(pos,r);
            ans.push_back(root);
        }
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>num[i];
    check(0,N-1);
    if(is_b){
        cout<<"YES\n";
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i<N-1)cout<<' ';
        }
    }
    else{
        check2(0,N-1);
        ans.clear();
        if(is_bm){
            cout<<"YES\n";
            for(int i=0;i<N;i++){
                cout<<ans[i];
                if(i<N-1)cout<<' ';
            }
        }
        else cout<<"NO\n";
    }
}