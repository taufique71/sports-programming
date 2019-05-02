#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int max(int m, int n){
        if (m > n) return m;
        else return n;
    }
    bool canJump(vector<int>& nums) {
        int m = 0;
        for(int i = 0; (i < nums.size()) && (i <= m); i++){
            m = max(m, nums[i]+i);
        }
        if(m >= nums.size()-1) return true;
        else return false;
    }
};

int main(){
    vector<int> v;

    //v.push_back(2);
    //v.push_back(3);
    //v.push_back(1);
    //v.push_back(1);
    //v.push_back(4);
    
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(4);

    Solution s;
    cout << s.canJump(v) << endl;
    return 0;
}
