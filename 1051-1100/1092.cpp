// 0:17 - 0:22 - 20分
#include<iostream>
#include<map>
using namespace std;
map<char,int> M;
string str1,str2;
int cnt=0;
int main(){
    cin>>str1>>str2;
    for(int i=0;i<str2.length();i++)M[str2[i]]++;
    for(int i=0;i<str1.length();i++)
        if(M[str1[i]]!=0)M[str1[i]]--;
    for(int i=0;i<str2.length();i++)
        if(M[str2[i]]!=0){
            cnt+=M[str2[i]];
            M[str2[i]]=0;
        }
    if(cnt==0)
        cout<<"Yes "<<str1.length()-str2.length();
    else
        cout<<"No "<<cnt;
    
}