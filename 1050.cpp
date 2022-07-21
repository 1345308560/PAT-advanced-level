//21：41 - 21:43 - 20分
#include<iostream>
#include<map>
using namespace std;
map<char,int> M;
int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    for(int i=0;i<str2.length();i++)M[str2[i]]=1;
    for(int i=0;i<str1.length();i++)
        if(M.count(str1[i])==0)
            cout<<str1[i];
}