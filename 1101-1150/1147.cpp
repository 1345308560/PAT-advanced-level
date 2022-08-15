//10:45 - 11:08 - 30分
#include<iostream>
#include<vector>
using namespace std;
int M,N,num[1005],flag=1;
vector<int> ans;
void check(int pos,int type){
    if(pos*2+1<N){
        if(type&&num[pos]<num[pos*2+1])flag=0;
        else if(!type&&num[pos]>num[pos*2+1])flag=0;
        check(pos*2+1,type);
    }
    if(pos*2+2<N){
        if(type&&num[pos]<num[pos*2+2])flag=0;
        else if(!type&&num[pos]>num[pos*2+2])flag=0;
        check(pos*2+2,type);
    }
}
void DFS(int pos){
    if(pos>=N)return;
    DFS(pos*2+1);
    DFS(pos*2+2);
    ans.push_back(num[pos]);
}
int main(){
    cin>>M>>N;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++)cin>>num[j];
        flag=1;
        check(0,1);
        if(flag)cout<<"Max Heap"<<endl;
        else{
            flag=1;
            check(0,0);
            if(flag)cout<<"Min Heap"<<endl;
            else cout<<"Not Heap"<<endl;
        }
        ans.clear();
        DFS(0);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i<N-1)cout<<' ';
        }
        cout<<endl;
    }
}