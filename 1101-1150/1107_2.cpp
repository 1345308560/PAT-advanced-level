// 16:18
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<int> h[1005],ans;
map<int,int> Mp;
int N,K,num,root[1005];
int find_root(int n){
    if(n!=root[n])root[n]=find_root(root[n]);
    return root[n];
}
void union_m(int a,int b){
    int ra=find_root(a),rb=find_root(b);
    if(ra!=rb)root[ra]=rb;
}
bool cmp(int a,int b){
    return Mp[a]>Mp[b];
}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        root[i]=i;
        cin>>K;getchar();
        for(int j=0;j<K;j++){
            cin>>num;
            h[num].push_back(i);
        }
    }
    for(int i=1;i<1005;i++){
        if(h[i].size()>1)
            for(int j=1;j<h[i].size();j++)
                union_m(h[i][j],h[i][j-1]);
    }
    for(int i=1;i<=N;i++){
        if(Mp.count(find_root(i))==0)ans.push_back(root[i]);
        Mp[root[i]]++;
    }
    sort(ans.begin(),ans.end(),cmp);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<Mp[ans[i]];
        if(i<ans.size()-1)cout<<' ';
    }
}