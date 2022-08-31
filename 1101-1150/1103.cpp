// 10:16 - 10:35 - 23分
//       - 10:40 - 25分
//       - 10:46 - 27分
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int N,K,P;
vector<int> f;
vector<vector<int> >ans;
bool cmp(vector<int> &a,vector<int> &b){
    int sum1=0,sum2=0;
    for(int i=0;i<K;i++)sum1+=a[i];
    for(int i=0;i<K;i++)sum2+=b[i];
    if(sum1!=sum2)return sum1>sum2;
    else{
        for(int i=0;i<K;i++)
            if(a[i]!=b[i])
                return a[i]>b[i];
        return true;
    }
}
void DFS(int n,int l,vector<int> &temp){
    if(n<K-l)return;
    if(l>K)return;
    else if(l==K){
        if(n==0){
            if(f.size()==0)f=temp;
            else if(cmp(temp,f))f=temp;
        }
        return;
    }
    for(int i=1;i<pow(n,1.0/P)+0.5;i++){
        if(temp.size()>0&&i>temp[temp.size()-1])break;
        if(pow(i,P)<=n){
            if(n-pow(i,P)<K-l-1)return;
            temp.push_back(i);
            DFS(n-pow(i,P),l+1,temp);
            temp.pop_back();
        }
    }
}
int main(){
    cin>>N>>K>>P;
    vector<int> temp;
    DFS(N,0,temp);
    ans.push_back(f);
    if(f.size()==0)
        cout<<"Impossible";
    else{
        cout<<N<<" = ";
        for(int i=0;i<ans[0].size();i++){
            cout<<ans[0][i]<<"^"<<P;
            if(i<ans[0].size()-1)cout<<" + ";
        }
    }
}