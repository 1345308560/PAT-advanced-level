// 23:52 - 23:55 - 20分
#include<iostream>
using namespace std;
int cnt[10005]={},num[100005];
int N;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
        cnt[num[i]]++;
    }
    for(int i=0;i<N;i++)
        if(cnt[num[i]]==1){
            cout<<num[i];
            return 0;
        }
    cout<<"None";
}