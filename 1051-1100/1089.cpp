// 13:08 - 13:56 - 17分
//       - 14:05 - 24分
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> num1,num2,temp;
int N;
bool check(int n){
    sort(temp.begin(),temp.begin()+n);
    for(int i=0;i<N;i++)if(temp[i]!=num2[i])return false;
    return true;
}

bool check2(int n){
    for(int pos=0;pos<N;pos+=n)
        if(pos+n>=N&&pos+n/2<N)sort(temp.begin()+pos,temp.end());
        else if(pos+n>=N)break;
        else sort(temp.begin()+pos,temp.begin()+pos+n);
    for(int i=0;i<N;i++)if(temp[i]!=num2[i])return false;
    return true;
}
int main(){
    cin>>N;
    num1.resize(N);
    num2.resize(N);
    for(int i=0;i<N;i++)cin>>num1[i];
    for(int i=0;i<N;i++)cin>>num2[i];
    temp=num1;
    bool is_selection=false;
    for(int i=0;i<N;i++)
        if(check(i)){
            is_selection=true;
            cout<<"Insertion Sort\n";
            check(i+1);
            break;
        }
    if(!is_selection){
        cout<<"Merge Sort\n";
        temp=num1;
        for(int i=2;;i*=2){
            if(check2(i)){
                check2(i*2);
                break;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<temp[i];
        if(i<N-1)cout<<' ';
    }
}