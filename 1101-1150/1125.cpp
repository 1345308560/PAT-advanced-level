#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
priority_queue<double,vector<double>,greater<double> > Pq;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        double num;
        cin>>num;
        Pq.push(num);
    }
    while(Pq.size()>1){
        double a=Pq.top();
        Pq.pop();
        double b=Pq.top();
        Pq.pop();
        Pq.push((a+b)/2);
    }
    cout<<round(Pq.top());
}