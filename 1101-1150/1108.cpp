// 22:19 - 22:54 - 18分
//       - 22:59 - 20分
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int N,num=0;
double ans=0;
string str;
bool check(string s){
    int cnt_p=0,cnt_n=0,pos=0;
    for(int i=0;i<s.length();i++)
        if(s[i]>='0'&&s[i]<='9')continue;
        else if(s[i]=='.'&&cnt_p==0){cnt_p=1;pos=i;continue;}
        else if(s[i]=='-'&&cnt_n==0){cnt_n=1;continue;}
        else return false;
    if(stod(s)>1000||stod(s)<-1000)return false;
    if(cnt_p==1)if(s.length()-pos>3)return false;
    return true;

}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str;
        if(check(str)){
            num++;  
            ans+=stod(str);
        }
        else
            cout<<"ERROR: "<<str<<" is not a legal number\n";
    }
    if(num==1)cout<<"The average of "<<num<<" number is ";
    else cout<<"The average of "<<num<<" numbers is ";
    if(num==0)cout<<"Undefined";
    else printf("%.2f",ans/num);
}