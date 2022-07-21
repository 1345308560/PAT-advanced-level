// 16：09 - 16:26 AC
#include<iostream>
using namespace std;
string str;
int len,n1,n2;
int main(){
    cin>>str;
    len=str.length();
    n1=n2=(len+2)/3;
    if(n1+n2+n1<len+2){
        n2+=(len+2-n1-n2-n1);
    }
    //cout<<len<<" "<<n1<<endl;
    for(int i=0;i<n1-1;i++){
        cout<<str[i];
        for(int j=0;j<n2-2;j++)cout<<' ';
        cout<<str[len-1-i];
        cout<<endl;
    }
    for(int i=0;i<n2;i++)cout<<str[n1+i-1];
}