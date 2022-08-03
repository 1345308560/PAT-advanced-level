//16:32 - 17:01 - 25分
// 前序+中序->后序
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int N,num;
//          前序 中序
vector<int> num1,num2,num3;
stack<int> St;
void f(int l1,int r1,int l2,int r2){
    if(l1>r1)return;
    int root=num1[l1],pos;
    for(pos=l2;pos<=r2;pos++)if(num2[pos]==root)break;
    f(l1+1,l1+pos-l2,l2,pos-1);
    f(l1+pos-l2+1,r1,pos+1,r2);
    num3.push_back(num1[l1]);
}
int main(){
    cin>>N;
    for(int i=0;i<N*2;i++){
        string str;
        cin>>str;
        if(str=="Push"){
            cin>>num;
            St.push(num);
            num1.push_back(num);
        }
        else{
            num2.push_back(St.top());
            St.pop();
        }
    }
    f(0,N-1,0,N-1);
    for(int i=0;i<N;i++){
        cout<<num3[i];
        if(i<N-1)cout<<' ';
    }
}