//16:06 - 16:52 - 20分
// 公共后缀
#include<iostream>
using namespace std;
string str[105];
int N,ans=-1;
int main(){
    cin>>N;
    getchar();
    for(int i=0;i<N;i++)getline(cin,str[i]);
    for(int i=1;i<N;i++){
        int temp=0;
        for(int j=0;j<min(str[i].length(),str[i-1].length());j++){
            char c1=str[i][str[i].length()-j-1];
            char c2=str[i-1][str[i-1].length()-j-1];
            if(c1==c2)temp++;
            else break;
        }
        if(ans!=-2&&temp>0){
            if(ans==-1)ans=temp;
            else ans=min(ans,temp);
        }
        else ans=-2;
    }
    if(ans<=0)cout<<"nai";
    else 
        cout<<str[0].substr(str[0].length()-ans);
}