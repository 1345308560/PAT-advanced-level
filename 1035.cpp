#include<iostream>
#include<vector>
using namespace std;
struct Node{
    string name;
    string str;
};
vector<Node> V;
string f(string str){
    string ans="";
    for(int i=0;i<str.length();i++){
        if(str[i]=='1')ans+="@";
        else if(str[i]=='0')ans+="%";
        else if(str[i]=='l')ans+="L";
        else if(str[i]=='O')ans+='o';
        else ans+=str[i];
    }
    return ans;
}
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string str1,str2,str3;
        cin>>str1>>str2;
        str3=f(str2);
        if(str2==str3);
        else{
            Node temp;
            temp.name=str1;
            temp.str=str3;
            V.push_back(temp);
        }
    }
    if(V.size()==0){
        if(N==1)
            cout<<"There is "<<N<<" account and no account is modified";
        else
            cout<<"There are "<<N<<" accounts and no account is modified";
        return 0;
    }
    cout<<V.size();
    for(int i=0;i<V.size();i++){
        cout<<endl<<V[i].name<<" "<<V[i].str;
    }
}