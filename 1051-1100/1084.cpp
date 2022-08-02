//9:42 - 9:48 - 20分
#include<iostream>
#include<map>
using namespace std;
string str1,str2,ans="";
map<char,int> M;
int main(){
    cin>>str1>>str2;
    for(int i=0;i<str2.length();i++){
        M[str2[i]]=1;
        if(str2[i]>='a'&&str2[i]<='z')M[str2[i]-'a'+'A']=1;
        if(str2[i]>='A'&&str2[i]<='Z')M[str2[i]-'A'+'a']=1;
    }
    for(int i=0;i<str1.length();i++)
        if(M.count(str1[i])==0){
            if(str1[i]>='a'&&str1[i]<='z')ans+=(str1[i]-'a'+'A');
            else ans+=str1[i];
            M[str1[i]]=1;
            if(str1[i]>='A'&&str1[i]<='Z')M[str1[i]-'A'+'a']=1;
            if(str1[i]>='a'&&str1[i]<='z')M[str1[i]-'a'+'A']=1;
        }
    cout<<ans;
}