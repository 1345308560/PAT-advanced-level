#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string f(string str){
    string ans="00";
    int n=stoi(str),num1=n/13,num2=n%13;
    if(num1>9)ans[0]='A'+num1-10;
    else ans[0]='0'+num1;
    if(num2>9)ans[1]='A'+num2-10;
    else ans[1]='0'+num2;

    return ans;
} 
int main(){
    string a,b,c;
    cin>>a>>b>>c;
    cout<<"#"<<f(a)<<f(b)<<f(c);
}