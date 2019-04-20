#include <iostream>
#include <vector>
using namespace std;

int main(){
    long int n, k;
    vector<long int> digits;

    cin >> n >> k;
    long int i = 1;
    digits.push_back(i);
    k--;
    if(k == 0) cout << 1 << endl;
    while(n){
        i *= 2;
        //cout << "pow " << i << endl;
        long int j = i;
        vector<long int> temp;
        while(j/10){
            temp.push_back(j%10);
            //cout << "digits " << j % 10 << endl;
            j = j / 10;
        }
        temp.push_back(j);
        //cout << "digits " << temp.size() << endl;
        for(int j = temp.size()-1; j >= 0; j--){
            //cout << "pushing " << temp[j] << endl;
            digits.push_back(temp[j]);
            k--;
            if(k == 0) cout << temp[j] << endl;
        }
        n--;
    }
    //for(int j = 0; j < digits.size(); j++){
        //cout << digits[i] << " ";
    //}
    //cout << endl;
    //cout << n << k;
    return 0;
}
