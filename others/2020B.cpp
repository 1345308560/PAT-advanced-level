#include<iostream>
using namespace std;
string str1,str2;
string ans="";
void check(int pos){
    if(str1[pos]!=str2[0])return;

    int cnt=0,temp=pos;
    for(int i=0;i<str2.length();i++){
        for(;temp<str1.length();temp++)
            if(str1[temp]==str2[i]){
                temp++;
                cnt++;
                break;
            }
    }
    if(cnt==str2.length()){
        if(temp-pos<ans.length()||ans.length()==0)
            ans=str1.substr(pos,temp-pos);
    }
}
int main(){
    cin>>str1>>str2;
    for(int i=0;i<str1.length();i++)
        check(i);
    cout<<ans;
}