// 22:01 - 22:28 - 19分
//       - 22:38 - 21分
//       - 22:41 - 23分
//       - 23:00 - 25分
// 巨坑测试点
#include<iostream>
using namespace std;
int N;
string str1,str2;
struct Node{
    string str;
    int num;
}A,B;
void cut(Node & C){
    if(C.str.length()>N)C.str=C.str.substr(0,N);
    else if(C.str.length()<N){
        while(C.str.length()<N)C.str+='0';
    }
}
void f(string str,Node & C){

    while(str[0]=='0'&&str.length()>1&&str[1]!='.')
        str=str.substr(1,str.length());
    //cout<<str<<endl;

    int pos=-1,flag=1;
    for(int i=0;i<str.length();i++)
        if(str[i]=='.')pos=i;
        else if(str[i]>'0')flag=0;
    if(flag){
        C.str="0";
        C.num=0;
    }
    else if(pos==-1){
        C.str=str;
        C.num=str.length();
    }
    else{
        if(pos==1&&str[0]=='0'){
            int pos2=2;
            while(pos2<str.length()&&str[pos2]=='0')pos2++;
            C.str=str.substr(pos2,str.length());
            C.num=2-pos2;
        }
        else{
            int flag2=1;
            for(int i=0;i<pos;i++)if(str[i]!='0')flag2=0;
            if(flag2){
                int pos2=pos+1;
                while(pos2<str.length()&&str[pos2]=='0')pos2++;
                C.str=str.substr(pos2,str.length());
                C.num=pos-pos2+1;
            }
            else{
                C.str=str.substr(0,pos)+str.substr(pos+1,str.length());
                C.num=pos;
            }
            
        }
    }
    cut(C);
}

int main(){
    cin>>N>>str1>>str2;
    f(str1,A);
    f(str2,B);
    if(N==0){
        cout<<"YES 0.0*10^0";
    }
    else if(A.str==B.str&&A.num==B.num){
        cout<<"YES ";
        cout<<"0."<<A.str<<"*10^"<<A.num;
    }
    else{
        cout<<"NO ";
        cout<<"0."<<A.str<<"*10^"<<A.num<<' ';
        cout<<"0."<<B.str<<"*10^"<<B.num;
    }
}