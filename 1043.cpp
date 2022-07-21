// 10：37
#include<iostream>
#include<vector>
using namespace std;
int num[1005];
int N;
vector<int> ans;
bool check(int beg,int len,int type){
    if(len==1){
        ans.push_back(num[beg]);
        return true;
    }
    int root=num[beg],pos=beg,flag=0;
    if(type){
        for(;pos<beg+len;pos++)if(num[pos]>=num[beg])break;
        for(int i=pos;i<beg+len;i++)if(num[i]<num[beg])flag=1;
        if(flag)return false;
    }
    else{
        for(;pos<beg+len;pos++)if(num[pos]<num[beg])break;
        for(int i=pos;i<beg+len;i++)if(num[i]>=num[beg])flag=1;
        if(flag)return false;
    }
    flag=check(beg+1,pos-beg-1,type)&&check(pos,len-pos+beg,type);
    if(!flag)return false;
    ans.push_back(num[beg]);
    return true;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>num[i];
    
    int root=num[0];
    int pos=1,flag=0;
    for(;pos<N;pos++)if(num[pos]>=num[0])break;
    for(;pos<N;pos++)if(num[pos]<num[0])flag=1;
    if(flag){
        int pos2=1,flag2=0;
        for(;pos2<N;pos2++)if(num[pos2]<num[0])break;
        for(;pos2<N;pos2++)if(num[pos2]>=num[0])flag2=1;
        if(flag2){
            cout<<"NO";
            return 0;
        }
        else flag=check(0,N,0);
    }
    else flag=check(0,N,1);
    if(!flag){
        cout<<"NO";
        return 0;
    }
    else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i<ans.size()-1)cout<<' ';
        }
    }
}