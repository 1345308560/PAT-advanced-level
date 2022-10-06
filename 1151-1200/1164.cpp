// 17:25
#include<iostream>
#include<vector>
using namespace std;
struct Node{
    string str[7];
}Ns[26];
string str,temp="";
vector<string> ans;
void Print(string s){
    string blank[7];
    int l=s.length()*5+s.length()-1;
    for(int i=0;i<7;i++){
        for(int j=0;j<l;j++)blank[i]+=' ';
    }
    for(int i=0;i<s.length();i++){
        int pos=i*5+i;
        for(int j=0;j<7;j++){
            for(int k=pos;k<pos+5;k++)
                blank[j][k]=Ns[s[i]-'A'].str[j][k-pos];
        }
    }
    for(int i=0;i<7;i++)cout<<blank[i]<<endl;
}
int main(){
    for(int i=0;i<26;i++){
        for(int j=0;j<7;j++){
            cin>>Ns[i].str[j];
            // cout<<Ns[i].str[j]<<'\n';
        }
    }
    getchar();
    getline(cin,str);
    for(int i=0;i<str.length();i++){
        if(str[i]>='A'&&str[i]<='Z')
            temp+=str[i];
        else{
            if(temp.size()>0)ans.push_back(temp);
            temp="";
        }
        if(i==str.length()-1)
            if(temp.size()>0)ans.push_back(temp);
    }
    for(int i=0;i<ans.size();i++){
        Print(ans[i]);
        if(i<ans.size()-1)cout<<endl;
    }
}