//23:13 - 23:26 - 25分
#include<iostream>
#include<vector>
using namespace std;
int N,M,K,num1,num2,n,num[1005];
vector<int> V[205];
void check(){
    bool is_clique=true;
    bool vis[205]={};
    for(int i=0;i<n;i++){
        vis[num[i]]=true;
        for(int j=i+1;j<n;j++){
            bool find_path=false;
            for(int k=0;k<V[num[i]].size();k++)
                if(V[num[i]][k]==num[j])
                    find_path=true;
            if(!find_path)is_clique=false;
        }
    }
        
    if(!is_clique)cout<<"Not a Clique\n";
    else{
        bool is_max=true;
        for(int i=1;i<=N;i++){
            if(!vis[i]){
                int cnt=0;
                for(int j=0;j<n;j++){
                    bool find_path=false;
                    for(int k=0;k<V[i].size();k++)
                        if(V[i][k]==num[j])
                            find_path=true;
                    if(find_path)cnt++;
                }
                if(cnt==n)is_max=false;
            }
        }
        if(is_max)cout<<"Yes\n";
        else cout<<"Not Maximal\n";
    }
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
        cin>>n;
        for(int j=0;j<n;j++)cin>>num[j];
        check();
    }
}