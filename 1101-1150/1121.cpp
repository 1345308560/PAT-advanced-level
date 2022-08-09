//16:15 - 16:34 - 25分
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
map<int,int> Mp,Mp2;
int N,M,num1,num2,num[100005];
vector<int> ans;
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
        if(Mp.count(num[i])!=0){
            Mp2[num[i]]++;
            Mp2[Mp[num[i]]]++;
        }
    }
    for(int i=0;i<M;i++)
        if(Mp2[num[i]]<2)ans.push_back(num[i]);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        printf("%05d",ans[i]);
        if(i<ans.size()-1)cout<<' ';
    }
}

