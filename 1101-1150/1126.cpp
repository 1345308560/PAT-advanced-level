// 12:18 - 12:26 - 20分
// 确保图的连通性！
//       - 12:33 - 25分
#include<iostream>
#include<vector>
using namespace std;
int N,M,num1,num2,even=0,odd=0;
bool vis[505]={};
vector<int> V[505];
void DFS(int num){
    vis[num]=true;
    for(int i=0;i<V[num].size();i++)
        if(!vis[V[num][i]])
            DFS(V[num][i]);
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        V[num1].push_back(num2);
        V[num2].push_back(num1);
    }
    for(int i=1;i<=N;i++){
        cout<<V[i].size();
        if(V[i].size()%2==0)even++;
        else odd++;
        if(i<N)cout<<' ';
        else cout<<endl;
    }
    DFS(1);
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            cout<<"Non-Eulerian";
            return 0;
        }
    }
    if(N==1||N==0)cout<<"Eulerian";
    else if(odd==2)cout<<"Semi-Eulerian";
    else if(odd==0)cout<<"Eulerian";
    else cout<<"Non-Eulerian";
}