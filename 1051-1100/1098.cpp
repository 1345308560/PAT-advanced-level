// 21:18 - 22:25 - 23分
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> num1,num2,temp,heap,temp2;
bool is_selection=false;
bool check(int n){
    temp=num1;
    sort(temp.begin(), temp.begin()+n+1);
    return num2==temp;
}

void heap_adj(int pos){
    if(pos>=heap.size()||pos*2+1>=heap.size())return;
    int lch=pos*2+1,flag=pos*2+1,rch=pos*2+2;
    if(rch<heap.size()&&heap[rch]>heap[lch])flag=rch;
    if(heap[pos]<heap[flag]){
        swap(heap[pos],heap[flag]);
        heap_adj(flag);
    }
}
int heap_remove(){
    int num=heap[0],pos=0;
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    heap_adj(0);
    return num;
}
bool check2(){
    temp2.push_back(heap_remove());
    temp.clear();
    for(int i=0;i<heap.size();i++)temp.push_back(heap[i]);
    for(int i=temp2.size()-1;i>=0;i--)temp.push_back(temp2[i]);
    return temp==num2;
}
int main(){
    cin>>N;
    num1.resize(N);
    num2.resize(N);
    for(int i=0;i<N;i++)cin>>num1[i];
    for(int i=0;i<N;i++)cin>>num2[i];
    for(int i=0;i<N;i++){
        if(check(i)&&!check(i+1)){
            is_selection=true;
            break;
        }
    }
    if(is_selection)cout<<"Insertion Sort\n";
    else{
        cout<<"Heap Sort\n";
        vector<int> temp3=num1;
        sort(temp3.begin(),temp3.end());
        int pos;
        for(pos=num2.size()-1;pos>=0;pos--)
            if(num2[pos]!=temp3[pos])break;
        for(int i=0;i<pos+1;i++)heap.push_back(num2[i]);
        check2();
    }
    for(int i=0;i<N;i++){
        cout<<temp[i];
        if(i<N-1)cout<<' ';
    }
}