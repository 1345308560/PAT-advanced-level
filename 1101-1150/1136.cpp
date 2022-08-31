#include<iostream>
#include<algorithm>
using namespace std;
string str1,str2,str3;
int N;
string Add(string a,string b){
    int num[1005]={},s=a.length();
    string temp="";
    for(int i=0;i<a.length();i++){
        num[i]+=a[i]-'0';
        num[i]+=b[i]-'0';
        if(num[i]>=10){
            num[i+1]++;
            num[i]%=10;
        }
    }
    if(num[s]>0)s++;
    for(int i=0;i<s;i++){
        char c='0'+num[s-i-1];
        temp+=c;
    }
    return temp;
}
int main(){
    cin>>str1;
    for(int i=0;i<10;i++){
        str2=str1;
        reverse(str2.begin(),str2.end());
        if(str1==str2){
            cout<<str1<<" is a palindromic number.\n";
            return 0;
        }

        str3=Add(str1,str2);
        cout<<str1<<" + "<<str2<<" = "<<str3<<endl;
        str1=str3;
    }
    cout<<"Not found in 10 iterations.\n";
}