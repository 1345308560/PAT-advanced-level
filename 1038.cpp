#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string str[10005];
bool cmp(string a,string b){
    return a+b<b+a;
}
int N;
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>str[i];
    sort(str,str+N,cmp);
    string ans="";
    for(int i=0;i<N;i++)ans+=str[i];
    int pos=0;
    for(;pos<N;pos++)
        if(ans[pos]!='0')break;
    ans=ans.substr(pos,ans.length());
    cout<<ans;
}