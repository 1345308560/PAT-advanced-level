// 23:55 - 00:00 - 14分
//       - 00:05 - 21分
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,num[100005],MAX[100005],MIN[100005];
vector<int> ans;
bool check(int n){
    if(n==0)return num[n]<MIN[n+1];
    else if(n==N-1)return num[n]>MAX[n-1];
    else return num[n]<MIN[n+1]&&num[n]>MAX[n-1];
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>num[i];
    MAX[0]=num[0];MIN[N-1]=num[N-1];
    for(int i=1;i<N;i++)MAX[i]=max(MAX[i-1],num[i]);
    for(int j=N-2;j>=0;j--)MIN[j]=min(MIN[j+1],num[j]);
    for(int i=0;i<N;i++)
        if(check(i))
            ans.push_back(num[i]);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i<ans.size()-1)cout<<' ';
    }
    cout<<endl;
}