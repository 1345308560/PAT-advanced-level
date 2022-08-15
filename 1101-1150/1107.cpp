// 12:25 - 12:37 - 30分
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int N,K,num,f[1005];
map<int,int> cnt;
vector<int> V[1005],ans;
bool check(int a,int b){
    map<int,int> M;
    for(int i=0;i<V[a].size();i++)M[V[a][i]]=1;
    for(int i=0;i<V[b].size();i++)
        if(M.count(V[b][i]))
            return true;
    return false;
}
int find_father(int num){
    if(num!=f[num])
        f[num]=find_father(f[num]);
    return f[num];
}
void union_m(int a,int b){
    int ra=find_father(a);
    int rb=find_father(b);
    if(ra!=rb)f[ra]=rb;
}
bool cmp(int a,int b){
    return cnt[a]>cnt[b];
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        f[i]=i;
        cin>>K;getchar();
        for(int j=0;j<K;j++){
            cin>>num;
            V[i].push_back(num);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(check(i,j))union_m(i,j);
        }
    }
    for(int i=0;i<N;i++){
        if(cnt.count(find_father(i))==0){
            ans.push_back(find_father(i));
            cnt[find_father(i)]=1;
        }
        else cnt[find_father(i)]++;
    }
    sort(ans.begin(),ans.end(),cmp);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<cnt[ans[i]];
        if(i<ans.size()-1)cout<<' ';
    }
}