// 21:00 - 21:08 - 19分
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
long long N,temp;
vector<int> ans,ans2;
int main(){
    cin>>N;
    if(N==1){
        cout<<"1\n1";
        return 0;
    }
    for(int i=2;i<sqrt(N)+1;i++){
        temp=N;
        ans.clear();
        for(int j=i;temp!=1;j++){
            if(temp%j==0){
                temp/=j;
                ans.push_back(j);
                if(ans.size()>ans2.size())ans2=ans;
            }
            else break;
        }
        if(temp==1)break;
    }
    cout<<ans2.size()<<endl;
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i];
        if(i<ans2.size()-1)cout<<"*";
    }
}