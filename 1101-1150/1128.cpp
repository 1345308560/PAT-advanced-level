//15:11 - 15:19 - 20分
// 模拟
#include<iostream>
using namespace std;
bool line[1005];
bool l[2005],r[2005];
int main(){
    int N,K,num;
    cin>>N;
    for(int i=0;i<N;i++){
        bool f=true;
        cin>>K;
        fill(line,line+K+1,false);
        fill(l,l+K*2+2,false);
        fill(r,r+K*2+2,false);
        for(int j=1;j<=K;j++){
            cin>>num;
            if(line[num])f=false;
            if(l[j+num])f=false;
            if(r[num-j+K])f=false;
            line[num]=l[j+num]=r[num-j+K]=true;
        }
        if(f)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}