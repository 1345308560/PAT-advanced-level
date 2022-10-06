#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int ans,p1[3],p2[3];
vector<int> V;
string day[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
string day2[3]={"yesterday","today","tomorrow"};
bool check(int a,int b){
    int t1,t2;
    if(a==0)t1=(p1[0]+1)%7;
    else if(a==1)t1=p1[1];
    else if(a==2)t1=(p1[2]+6)%7;
    if(b==0)t2=(p2[0]+1)%7;
    else if(b==1)t2=p2[1];
    else t2=(p2[2]+6)%7;
    if(t1!=t2)return false;
    ans=t1;
    V.push_back(a);
    V.push_back(b);
    return true;
}
int main(){
    for(int i=0;i<3;i++)cin>>p1[i];
    for(int i=0;i<3;i++)cin>>p2[i];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(check(i,j))
                break;
    cout<<day[ans]<<endl;
    cout<<day2[V[0]]<<endl<<day2[V[1]];
}