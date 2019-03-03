#include <vector>
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

int binary_search(string s, char c){
    int start = 0;
    int end = s.size()-1;
    while(start <= end){
        int m = (start + end)/2;
        if (s[m] == c){
            return m;
        }
        else if(s[m] < c){
            start = m+1;
        }
        else if(s[m] > c){
            end = m-1;
        }
    }
    return -1;
}

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        for(int i = 0; i < A[0].size(); i++){
            //cout << A[0][i] << endl;
            bool flag = true;
            for(int j = 1; j < A.size(); j++){
                sort(A[j].begin(), A[j].end());
                cout << A[j] << endl;
                int loc = binary_search(A[j], A[0][i]);
                //cout << loc << endl;
                if(loc == -1){
                    //cout << A[0][i] << " not found in " << A[j] << endl;
                    flag = false;
                    break;
                }
                else{
                    A[j][loc] = toupper(A[j][loc]);
                }
            }
            if(flag == true) res.push_back(A[0].substr(i, 1));
        }
        return res;
    }
};

int main(){
    Solution s;
    vector <string> v;
    v.push_back(string("bella"));
    v.push_back(string("label"));
    v.push_back(string("roller"));
    //v.push_back(string("cool"));
    //v.push_back(string("lock"));
    //v.push_back(string("cook"));
    vector<string> res = s.commonChars(v);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}
