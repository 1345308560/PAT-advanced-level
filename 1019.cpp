#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,b;
vector<int> num;
int main(){
    cin>>n>>b;
    if(n==0){cout<<"Yes\n0";return 0;}
    while(n){
        num.push_back(n%b);
        n/=b;
    }
    reverse(num.begin(), num.end());
    for(int i=0;i<num.size();i++){
        if(num[i]!=num[num.size()-1-i]){
            cout<<"No\n";
            for(int j=0;j<num.size();j++){
                cout<<num[j];
                if(j<num.size()-1)cout<<" ";
            }
            return 0;
        }
    }
    cout<<"Yes\n";
            for(int j=0;j<num.size();j++){
                cout<<num[j];
                if(j<num.size()-1)cout<<" ";
            }
}