#include<iostream>
#include<vector>
using namespace std;
long n,MAXP,ansDel=-1,nowDel;
long nowBeg,ansBeg=-1;
bool isPrime[100005]={};
vector<long> Prime,ans,temp;
bool check(long a,long b){
    a=Prime[a];
    b=Prime[b];
    temp.clear();
    temp.push_back(a);
    temp.push_back(b);
    while(temp.size()<n){
        if(b-a+b>0&&!isPrime[b-a+b]){
            temp.push_back(b-a+b);
            int t=b-a+b;
            a=b;
            b=t;
        }
        else return false;
    }
    nowDel=a-b;
    if(nowDel>ansDel){
        ansDel=nowDel;
        ansBeg=temp[temp.size()-1];
        return true;
    }
    else if(nowDel==ansDel){
        if(temp[temp.size()-1]>ansBeg){
            ansBeg=temp[temp.size()-1];
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>MAXP;
    for(long i=2;i<=MAXP;i++){
        if(!isPrime[i])Prime.push_back(i);
        for(long j=i*i;j<=MAXP;j+=i)
            isPrime[j]=true;
    }
    if(n==1){
        cout<<Prime[Prime.size()-1]<<endl;
        return 0;
    }
    for(long i=Prime.size()-1;i>=n;i--){
        for(long j=i-1;j>=n-1;j--){
            if(check(i,j))ans=temp;
        }
    }
    if(ans.size()==0)cout<<Prime[Prime.size()-1];
    else for(int i=0;i<ans.size();i++){
        cout<<ans[ans.size()-i-1];
        if(i<ans.size()-1)cout<<' ';
        else cout<<endl;
    }
}