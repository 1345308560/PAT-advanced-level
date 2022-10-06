#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int N,M,cnt=0;
map<string,int> Mp;
string str,ans="";
bool check(string s1,string s2){
    if(s2.length()==0)return true;
    int num1=stoi(s1.substr(6,7)),num2=stoi(s2.substr(6,7));
    if(num1<num2)return true;
    else return false;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str;
        Mp[str]=1;
    }
    cin>>M;
    for(int j=0;j<M;j++){
        cin>>str;
        if(Mp.count(str)>0)cnt++;
        if(check(str,ans))ans=str;
    }
    cout<<cnt<<"\n"<<ans;
}