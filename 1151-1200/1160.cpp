#include<iostream>
#include<vector>
using namespace std;
int N,K,m;
struct Node{
    vector<int> A;
    int n;
};
vector<Node> ans;
void check(vector<int>& temp){
    
}
void DFS(int l,int res,vector<int>& temp){
    if(l==K){
        if(res==0)
            check(temp);
        return;
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>K>>m;

    }
}