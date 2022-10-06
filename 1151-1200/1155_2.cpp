#include<iostream>
#include<vector>
using namespace std;
int N,num[1005],t;
vector<int> Vt;
vector<vector<int> > ans;
bool check(int pos,int type){
    if(pos>=N)return true;
    if(type){
        if(pos*2+1<N&&num[pos]<num[pos*2+1])return false;
        if(pos*2+2<N&&num[pos]<num[pos*2+2])return false;
        return check(pos*2+1,type)&&check(pos*2+2,type);
    }
    else{
        if(pos*2+1<N&&num[pos]>num[pos*2+1])return false;
        if(pos*2+2<N&&num[pos]>num[pos*2+2])return false;
        return check(pos*2+1,type)&&check(pos*2+2,type);
    }
}
void DFS(int pos,vector<int>& temp){
    if(pos>=N)return;
    temp.push_back(pos);
    if(pos<N&&pos*2+1>=N)
        ans.push_back(temp);
    else{
        DFS(pos*2+2,temp);
        DFS(pos*2+1,temp);
    }
    temp.pop_back();
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>num[i];
    DFS(0,Vt);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<num[ans[i][j]];
            if(j<ans[i].size()-1)cout<<' ';
            else cout<<endl;
        }
    }
    if(check(0,1))cout<<"Max Heap\n";
    else if(check(0,0))cout<<"Min Heap\n";
    else cout<<"Not Heap\n";
    
}