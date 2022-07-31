//11:58 - 12:10 - 25分
// 需要记忆set操作函数
// set_intersection set_union
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int N,M,K;
set<int> S[55];
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>M;
        for(int j=0;j<M;j++){
            int num;
            cin>>num;
            S[i].insert(num);
        }
    }
    cin>>K;
    for(int i=0;i<K;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        set<int> S1,S2;
        set_intersection(S[a].begin(),S[a].end(),S[b].begin(),S[b].end(),inserter(S1,S1.begin()));
        set_union(S[a].begin(),S[a].end(),S[b].begin(),S[b].end(),inserter(S2,S2.begin()));
        double per=100.0*S1.size()/S2.size();
        printf("%.1f",per);
        cout<<"%";
        if(i<K-1)cout<<endl;
    }
}
