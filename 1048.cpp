//21：00 - 21:07 - 23分
// 膜拜柳神
// 读题马虎 21:12 - 25分
#include<iostream>
#include<map>
using namespace std;
int N,M;
map<int,int> Mp;
int main(){
    cin>>N>>M;
    int ans1=0x7fffffff,ans2=-1;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        if(num<=M&&Mp.count(M-num)>0){
            if(M-num<ans1||num<ans1){
                ans1=min(M-num,num);
                ans2=max(M-num,num);
            }
        }
        Mp[num]=1;
    }
    if(ans1==0x7fffffff)cout<<"No Solution";
    else {
        cout<<ans1<<" "<<ans2;
    }
}