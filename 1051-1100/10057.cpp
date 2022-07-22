//17:53 堆 15分
// 膜拜柳神 30分
// 树状数组
// 模板 lowbit, update, getsum
#include<iostream>
#include<stack>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int MAXN=100005;
int c[MAXN]={},N;
stack<int> S; 
void update(int x,int num){
    for(int i=x;i<MAXN;i+=lowbit(i)){
        c[i]+=num;
    }
}
int getsum(int x){
    int sum=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        sum+=c[i];
    }
    return sum;
}
int median(){
    int l=1,r=MAXN,mid,k=(S.size()+1)/2;
    while(l<r){
        mid=(l+r)/2;
        if(getsum(mid)>=k)r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        if(str[1]=='u'){
            int num;
            cin>>num;
            S.push(num);
            update(num,1);
        }
        else if(str[1]=='o'){
            if(S.size()==0)cout<<"Invalid\n";
            else {
                update(S.top(),-1);
                cout<<S.top()<<endl;
                S.pop();
            }
        }
        else{
            if(S.size()==0)cout<<"Invalid\n";
            else cout<<median()<<endl;
        }
    }
}


// #include<iostream>
// #include<stack>
// #include<queue>
// #include<map>
// using namespace std;
// priority_queue<int> P_max;
// priority_queue<int,vector<int>,greater<int> > P_min;
// map<int,int>delayed;
// stack<int> St;
// int N;
// void make_balance(){
//     if(P_max.size()>P_min.size()+1){
//         P_min.push(P_max.top());
//         P_max.pop();
//     }
//     else if(P_max.size()<P_min.size()){
//         P_max.push(P_min.top());
//         P_min.pop();
//     }
// }
// void insert(int num){
//     if(St.empty())P_max.push(num);
//     else if(num<P_max.top())P_max.push(num);
//     else P_min.push(num);
//     St.push(num);
//     make_balance();
// }
// void pop(){
//     if(St.empty())cout<<"Invalid";
//     else{
//         int num=St.top();
//         cout<<num;
//         St.pop();
//         delayed[num]++;
//         while(delayed[P_max.top()]>0||delayed[P_min.top()]>0){
//             if(delayed[P_max.top()]>0){delayed[P_max.top()]--;P_max.pop();}
//             else {delayed[P_min.top()]--;P_min.pop();}
//             make_balance();
//         }
//     }
// }
// void PeekMedian(){
//     if(St.empty())cout<<"Invalid";
//     else{
//         cout<<P_max.top();
//     }
// }
// int main(){
//     cin>>N;
//     bool f=true;
//     for(int i=0;i<N;i++){
//         string str;
//         cin>>str;
//         if(str=="Pop"){
//             if(f)f=false;
//             else cout<<endl;
//             pop();
//         }
//         else if(str=="PeekMedian"){
//             if(f)f=false;
//             else cout<<endl;
//             PeekMedian();
//         }
//         else{
//             int num;
//             cin>>num;
//             insert(num);
//         }
        
//     }
// }