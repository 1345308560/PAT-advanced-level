#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int N,K,P;
vector<vector<int> >ans;
void DFS(int l,int res,vector<int>& t){
    if(res<K-l)return;
    if(l==K){
        if(res==0)ans.push_back(t);
        return;
    }
    
    for(int i=1;i<=pow(res,1.0/P);i++){
        t.push_back(i);
        res-=pow(i,P);
        DFS(l+1,res,t);
        res+=pow(i,P);
        t.pop_back();
    }
}
bool cmp(vector<int>& a,vector<int>& b){
    int sum1=0,sum2=0;
    for(int i=0;i<K;i++)sum1+=a[i];
    for(int i=0;i<K;i++)sum2+=b[i];
    if(sum1!=sum2)return sum1>sum2;

    for(int i=0;i<K;i++)
        if(a[i]!=b[i])return a[i]>b[i];
    return true;
}
int main(){
    cin>>N>>K>>P;
    vector<int> temp;
    DFS(0,N,temp);
    if(ans.size()==0){
        cout<<"Impossible";
        return 0;
    }
    sort(ans.begin(),ans.end(),cmp);
    cout<<N<<" = ";
    for(int i=0;i<K;i++){
        cout<<ans[0][i]<<"^"<<P;
        if(i<K-1)cout<<" + ";
    }
}