//10:02 - 10:15 - 19分
//      - 10:18 - 22分
//      - 10:19 - 25分
// 增加last变量解决超时问题
// 转换为<=解决测试点2、3
// 伪dp题
#include<iostream>
#include<algorithm>
using namespace std;
long N,p,num[100005];
int ans=0,last=0;
int main(){
    cin>>N>>p;
    for(int i=0;i<N;i++)cin>>num[i];
    sort(num,num+N);
    for(int i=0;i<N;i++){
        for(int j=max(i,last);j<N;j++){
            long m=num[i],M=num[j];
            double temp=1.0*M/m;
            if(temp<=p){ans=max(ans,j-i+1);last=j;}
            else break;
        }
    }
    cout<<ans;
}