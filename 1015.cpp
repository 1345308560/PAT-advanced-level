#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
// 18：50
int N,D;
vector<bool> ans;
bool IsPrime(int num){
    if(num==1)return false;
    for(int i=2;i<num;i++){
        if(num%i==0)return false;
    }
    return true;
}
bool check(int a,int b){
    string str1="";
    if(!IsPrime(a))return false;
    while(a>=0){
        if(a<b){
            str1+=to_string(a);
            a=-1;
        }
        else{
            int num1=a/b,num2=a%b;
            str1+=to_string(num2);
            a=num1;
        }
    }
    reverse(str1.begin(),str1.end());
    int num=0;
    for(int i=0;i<str1.length();i++){
        num+=pow(b,i)*(str1[i]-'0');
    }
    if(IsPrime(num))return true;
    else return false;
}
int main(){
    while(1){
        cin>>N;
        if(N<0)break;
        cin>>D;
        if(check(N,D))ans.push_back(true);
        else ans.push_back(false);
    }
    for(int i=0;i<ans.size();i++){
        if(ans[i])cout<<"Yes";
        else cout<<"No";
        if(i<ans.size()-1)cout<<endl;
    }
}