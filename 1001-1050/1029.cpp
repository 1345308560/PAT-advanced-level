// 13:51 - 14:03 有错误
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long> V1, V2;
long N1, N2;
int main() {
    cin >> N1;
    for (int i = 0; i < N1; i++) {
        long num;
        cin >> num;
        V1.push_back(num);
    }
    cin >> N2;
    for (int i = 0; i < N2; i++) {
        long num;
        cin >> num;
        V2.push_back(num);
    }
    vector<long> V3(N1 + N2);
    merge(V1.begin(), V1.end(), V2.begin(), V2.end(), V3.begin());
    //cout << V3.size() << endl;
    cout<<V3[(N1+N2+1)/2-1];
}