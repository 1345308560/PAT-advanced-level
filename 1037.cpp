#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<long> pos1,pos2,neg1,neg2;
long num,ans=0;
int N1,N2;
int main(){
    cin>>N1;
    for(int i=0;i<N1;i++){
        cin>>num;
        if(num>0)pos1.push_back(num);
        else if(num<0)neg1.push_back(-1*num);
    }
    cin>>N2;
    for(int i=0;i<N2;i++){
        cin>>num;
        if(num>0)pos2.push_back(num);
        else if(num<0)neg2.push_back(-1*num);
    }
    sort(pos1.begin(),pos1.end());
    sort(pos2.begin(),pos2.end());
    sort(neg1.begin(),neg1.end());
    sort(neg2.begin(),neg2.end());
    int i=pos1.size()-1,j=pos2.size()-1;
    while(i>=0&&j>=0){
        ans+=(pos1[i]*pos2[j]);
        i--;
        j--;
    }
    i=neg1.size()-1;
    j=neg2.size()-1;
    while(i>=0&&j>=0){
        ans+=(neg1[i]*neg2[j]);
        i--;
        j--;
    }
    cout<<ans;
}