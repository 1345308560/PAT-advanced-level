//15:16 - 15:29 - 25分
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int cnt=-1;
string str,ans;
map<string,int> M;
int main(){
    getline(cin,str);
    for(int i=0;i<str.length();i++)
        if(str[i]>='A'&&str[i]<='Z')
            str[i]=str[i]-'A'+'a';
    for(int i=0;i<str.length();i++){
        if(isalpha(str[i])||isdigit(str[i])){
            string temp="";
            for(int j=i;j<str.length();j++)
                if(isalpha(str[j])||isdigit(str[j]))temp+=str[j];
                else {i=j;break;}
            if(M.count(temp)==0)M[temp]=0;
            M[temp]++;
            if(M[temp]>cnt){cnt=M[temp];ans=temp;}
            else if(M[temp]==cnt&&temp<ans)ans=temp;
        }
    }
    cout<<ans<<" "<<M[ans];
}