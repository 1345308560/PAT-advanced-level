#include<iostream>
#include<algorithm>
using namespace std;
string s;
int k;
void ADD(string s2){
    int flag=0;
    for(int i=0;i<s.length();i++){
        s[i]+=s2[i]-'0'+flag;
        flag=0;
        if(s[i]>'9'){
            s[i]=s[i]-10;
            flag=1;
        }
    }
    if(flag)s+="1";
    reverse(s.begin(), s.end());
}
int main(){
    cin>>s>>k;
    int i;
    for(i=0;i<=k;i++){
        string str=s;
        reverse(str.begin(),str.end());
        if(str==s||i==k)break;
        ADD(str);
    }
    cout<<s<<endl<<i;
}