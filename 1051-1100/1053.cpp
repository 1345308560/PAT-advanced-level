// 14:03 - 14:26 - 28分 段错误
//       - 14:56 - 30分
// 参考使用functional的greater不会出现段错误
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int N,M,S;
int w[105];
vector<vector<int> > ans;
vector<int> V[105];
bool cmp2(int num1,int num2){
    return w[num1]>w[num2];
}
void DFS(vector<int>& temp,int sum,int root){
    sum+=w[root];
    temp.push_back(w[root]);
    if(sum==S&&V[root].size()==0)ans.push_back(temp);
    else if(sum>=S);
    else
        for(int i=0;i<V[root].size();i++)
            DFS(temp,sum,V[root][i]);
    sum-=w[root];
    temp.pop_back();
    return ;
}
int main(){
    cin>>N>>M>>S;
    for(int i=0;i<N;i++)cin>>w[i];
    for(int i=0;i<M;i++){
        int ID,k;
        cin>>ID>>k;
        for(int j=0;j<k;j++){
            int num;
            cin>>num;
            V[ID].push_back(num);
        }
        sort(V[ID].begin(),V[ID].end(),cmp2);
    }
    vector<int> temp;
    DFS(temp,0,0);
    sort(ans.begin(),ans.end(),greater<vector<int> >());
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
            if(j<ans[i].size()-1)cout<<' ';
        }
        if(i<ans.size()-1)cout<<endl;
    }
}