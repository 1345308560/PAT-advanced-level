// 11:22 - 11:37 - 30分
#include<iostream>
#include<vector>
using namespace std;
int N,num[1005],flag;
vector<vector<int> > ans;
bool check(int pos,int type){
    int left=pos*2+1,right=pos*2+2;
    if(left<N){
        if(type&&num[pos]<num[left])return false;
        else if(!type&&num[pos]>num[left])return false;
        if(!check(left,type))return false;
    }
    if(right<N){
        if(type&&num[pos]<num[right])return false;
        else if(!type&&num[pos]>num[right])return false;
        if(!check(right,type))return false;
    }
    return true;
}
void DFS(int pos,vector<int> &path){
    path.push_back(num[pos]);
    if(pos*2+2>=N&&pos*2+1>=N){
        ans.push_back(path);
    }
    if(pos*2+2<N)DFS(pos*2+2,path);
    if(pos*2+1<N)DFS(pos*2+1,path);
    path.pop_back();
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>num[i];
    vector<int> temp;
    DFS(0,temp);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
            if(j<ans[i].size()-1)cout<<' ';
        }
        cout<<endl;
    }
    if(check(0,0))cout<<"Min Heap";
    else if(check(0,1))cout<<"Max Heap";
    else cout<<"Not Heap";
}