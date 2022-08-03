//12:10 - 12:27 - 25分
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int N,m,n,num[10005],mp[10005][10005]={};
int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
bool cmp(int a,int b){return a>b;}
bool check(int px,int py,int di){
    if(px+x[di]<0||px+x[di]>=m)return false;
    else if(py+y[di]<0||py+y[di]>=m)return false;
    else if(mp[px+x[di]][py+y[di]]!=-1)return false;
    else return true;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>num[i];
    sort(num,num+N,cmp);
    for(int i=ceil(sqrt(N));i<=N;i++)if(N%i==0){m=i;n=N/i;break;}
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            mp[i][j]=-1;
    int dir=0,posx=0,posy=0;
    for(int i=0;i<N;i++){
        mp[posx][posy]=num[i];
        if(!check(posx,posy,dir))dir=(dir+1)%4;
        posx+=x[dir];
        posy+=y[dir];
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            cout<<mp[i][j];
            if(j<n-1)cout<<' ';
            else cout<<endl;
        }
}