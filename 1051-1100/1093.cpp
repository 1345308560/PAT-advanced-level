// 9:58 - 10:03 - 25分
#include<iostream>
using namespace std;
string str;
int P[100005]={},T[100005]={};
long long ans=0;
int main(){
    cin>>str;
    for(int i=1;i<=str.length();i++){
        P[i]+=P[i-1];
        if(str[i-1]=='P')P[i]++;
    }
    for(int i=str.length();i>0;i--){
        T[i]+=T[i+1];
        if(str[i-1]=='T')T[i]++;
    }
    for(int i=1;i<str.length();i++){
        if(str[i]=='A'){
            ans+=(P[i]*T[i+2])%1000000007;
            ans%=1000000007;
        }
    }
    cout<<ans;
}