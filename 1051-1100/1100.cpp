//17:10 - 17:27 - 14分
//      - 17:49 - 16分
//      - 17:53 - 20分
// 36行应该为* 错误写为+
#include<iostream>
#include<algorithm>
using namespace std;
int N;
string m1[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string m2[13]={"&&&","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
void f1(string str){
    int num=stoi(str);
    int a=num/13,b=num%13;
    if(a==0)cout<<m1[b]<<endl;
    else if(b==0)cout<<m2[a]<<endl;
    else cout<<m2[a]<<' '<<m1[b]<<endl;
}
void f2(string str){
    bool has_space=false;
    string l,r;
    for(int i=0;i<str.length();i++)
        if(str[i]==' '){
            has_space=true;
            l=str.substr(0,i);
            r=str.substr(i+1,str.length());
            break;
        }
    if(has_space){
        int num=0;
        for(int i=0;i<13;i++)if(r==m1[i])num+=i;
        for(int i=0;i<13;i++)if(l==m2[i])num+=i*13;
        cout<<num<<endl;
    }
    else{
        for(int i=0;i<13;i++)if(str==m1[i])cout<<i<<endl;
        for(int i=1;i<13;i++)if(str==m2[i])cout<<i*13<<endl;
    }
}
int main(){
    cin>>N;
    getchar();
    for(int i=0;i<N;i++){
        string str;
        getline(cin,str);
        if(str[0]>='0'&&str[0]<='9')f1(str);
        else f2(str);
    }
}