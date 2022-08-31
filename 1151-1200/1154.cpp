#include<iostream>
#include<vector>
#include<set>
using namespace std;
int N,M,K,num1,num2;
int num[10005];
vector<int> V[10005];
bool check(){
    for(int i=0;i<N;i++)
        for(int j=0;j<V[i].size();j++)
            if(num[i]==num[V[i][j]])return false;
    return true;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        V[num1].push_back(num2);
        V[num2].push_back(num1);
    }
    cin>>K;
    for(int i=0;i<K;i++){
        set<int> Se;
        for(int j=0;j<N;j++){
            cin>>num[j];
            Se.insert(num[j]);
        }
        if(check())cout<<Se.size()<<"-coloring\n";
        else cout<<"No\n";
    }
}