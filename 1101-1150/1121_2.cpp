#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
map<int,int> Mp,Mp2;
vector<int> ans;
int N,M,num1,num2,num[10005];

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num1>>num2;
        Mp[num1]=num2;
        Mp[num2]=num1;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>num[i];
        Mp2[num[i]]=1;
    }
    for(int i=0;i<M;i++){
        if(Mp.count(num[i])!=0&&Mp2.count(Mp[num[i]])!=0);
        else ans.push_back(num[i]);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        printf("%05d",ans[i]);
        if(i<ans.size()-1)cout<<' ';
    }
        
}