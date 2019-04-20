#include <iostream>
#include <vector>
using namespace std;

int absdiff(int a, int b){
    if(a > b) return a-b;
    else return b-a;
}

int func(int sum1, int sum2, vector<int> w, int idx){
    if(idx == w.size()){
        return absdiff(sum1, sum2);
    }
    else{
        int x = func(sum1+w[idx], sum2, w, idx+1);
        int y = func(sum1, sum2+w[idx], w, idx+1);
        if(x < y) return x;
        else return y;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    int x = func(0, 0, w, 0);
    cout << x << endl;
    return 0;
}
