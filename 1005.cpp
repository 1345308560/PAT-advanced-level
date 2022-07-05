#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
string w[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
    string str;
    cin>>str;
    int ans;
    for(int i=0;i<str.length();i++){
        ans+=(str[i]-'0');
    }
    if(ans==0){
        cout<<"zero";
        return 0;
    }
    vector<int> num;
    while(ans){
        num.push_back(ans%10);
        ans/=10;
    }
    for(int i=num.size()-1;i>=0;i--){
        cout<<w[num[i]];
        if(i>0)cout<<' ';
    }

}