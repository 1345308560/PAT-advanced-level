//12:50 - 12:54 - 20分
#include<iostream>
#include<set>
using namespace std;
int N,num,temp=0;
set<int> S;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        temp=0;
        while(num){
            temp+=num%10;
            num/=10;
        }
        S.insert(temp);
    }
    int s=S.size(),cnt=0;
    cout<<s<<endl;
    for(auto i:S){
        cout<<i;
        if(cnt<s-1)cout<<' ';
        cnt++;
    }
}