#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<stack>
using namespace std;
int address,N,K;
stack<int> St;
vector<int> ans,L;
map<int,int> Mp;
struct Node{
    int address,data,next;
}Nl[100005];
int main(){
    cin>>address>>N>>K;
    for(int i=0;i<N;i++){
        cin>>Nl[i].address>>Nl[i].data>>Nl[i].next;
        Mp[Nl[i].address]=i;
    }
    while(address!=-1){
        L.push_back(Mp[address]);
        address=Nl[Mp[address]].next;
    }
    for(int i=0;i<L.size();i++){
        St.push(L[i]);
        if(St.size()==K){
            while(St.size()>0){
                ans.push_back(St.top());
                St.pop();
            }
        }
    }
    while(St.size()>0){
        ans.push_back(St.top());
        St.pop();
    }
    for(int i=ans.size()-1;i>0;i--)
    printf("%05d %d %05d\n",Nl[ans[i]].address,Nl[ans[i]].data,Nl[ans[i-1]].address);
    printf("%05d %d -1",Nl[ans[0]].address,Nl[ans[0]].data);
}