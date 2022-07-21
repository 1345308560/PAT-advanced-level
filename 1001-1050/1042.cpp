// 00:02 - 00:12 - 20分
#include<iostream>
using namespace std;
int K;
int num[60],num2[60],sf[60];
string f(int i){
    string ans="";
    if(i>=1&&i<=13)ans+='S';
    else if(i<=26)ans+='H';
    else if(i<=39)ans+='C';
    else if(i<=52)ans+='D';
    else if(i==53)return "J1";
    else return "J2";
    i%=13;
    if(i==0)i=13;
    ans+=to_string(i);
    return ans;
}
int main(){
    cin>>K;
    for(int i=1;i<=54;i++){
        num[i]=i;
        cin>>sf[i];
    }
    for(int i=0;i<K;i++){
        for(int j=1;j<=54;j++)num2[sf[j]]=num[j];
        for(int j=1;j<=54;j++)num[j]=num2[j];
    }
    for(int i=1;i<=54;i++){
        cout<<f(num[i]);
        if(i<54)cout<<' ';
    }
}