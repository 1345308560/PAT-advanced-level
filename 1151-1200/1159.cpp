#include<iostream>
#include<algorithm>
using namespace std;
int pos[35],in[35],N,M,ROOT=-1,is_full=true;
struct Node{
    int l=-1,r=-1,level=0,f;
}Nt[1005];
int f(int l1,int r1,int l2,int r2,int l,int ft){
    if(l1>r1)return -1;

    int rt=pos[r1],p=l2;
    for(;p<=r2;p++)if(in[p]==rt)break;
    Nt[rt].f=ft;
    Nt[rt].level=l;
    Nt[rt].l=f(l1,l1+p-l2-1,l2,p-1,l+1,rt);
    Nt[rt].r=f(l1+p-l2,r1-1,p+1,r2,l+1,rt);
    return rt;
}
void check1(){
    string str2;
    getline(cin,str2);
    if(is_full)cout<<"Yes\n";
    else cout<<"No\n";
}
void check_f(int R){
    if(R==-1)return;
    if(Nt[R].l==-1&&Nt[R].r!=-1)is_full=false;
    if(Nt[R].l!=-1&&Nt[R].l==-1)is_full=false;
    check_f(Nt[R].l);
    check_f(Nt[R].r);
}
void check2(string s1,string s2){
    string temp;
    getline(cin,temp);
    int num1=stoi(s1),num2=stoi(s2);
    if(Nt[num1].f==Nt[num2].f)cout<<"Yes\n";
    else cout<<"No\n";
}
void check3(string s1,string s2){
    string temp;
    getline(cin,temp);
    int num1=stoi(s1),num2=stoi(s2);
    if(Nt[num1].level==Nt[num2].level)cout<<"Yes\n";
    else cout<<"No\n";
}
void check4(string s){
    if(stoi(s)==ROOT)cout<<"Yes\n";
    else cout<<"No\n";
}
void check5(string s){
    string s1,s2;
    cin>>s1>>s2;
    int p1=stoi(s),p2=stoi(s2);
    if(Nt[p2].f==p1)cout<<"Yes\n";
    else cout<<"No\n";
}
void check6(string s){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int p1=stoi(s),p2=stoi(s3);
    if(Nt[p2].l==p1)cout<<"Yes\n";
    else cout<<"No\n";
}
void check7(string s){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int p1=stoi(s),p2=stoi(s3);
    if(Nt[p2].r==p1)cout<<"Yes\n";
    else cout<<"No\n";
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>pos[i];
    for(int i=0;i<N;i++)cin>>in[i];
    ROOT=f(0,N-1,0,N-1,0,ROOT);
    check_f(ROOT);
    cin>>M;getchar();
    for(int i=0;i<M;i++){
        string str;
        cin>>str;
        if(str[0]=='I')check1();
        else{
            string str2;
            cin>>str2;
            if(str2[0]=='a'){
                string str3,str4;
                cin>>str3>>str4>>str4;
                if(str4[0]=='s')check2(str,str3);
                else check3(str,str3);
            }
            else{
                string str3,str4;
                cin>>str3>>str4;
                if(str4[0]=='r'&&str4[1]=='o')check4(str);
                else if(str4[0]=='p')check5(str);
                else if(str4[0]=='l')check6(str);
                else check7(str);
            }
        }
    }
}