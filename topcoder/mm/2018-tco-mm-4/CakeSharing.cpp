// C++11
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CakeSharing {
public:
    vector<string> cut(vector<string> roses, int NP) {
        vector<string> ret(4);
        ret[0] = "2 0 2 10";
        ret[1] = "6 10 6 0";
        ret[2] = "2 6 6 4";
        ret[3] = "7 0 9 10";
        return ret;
    }
};
// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
}

int main() {
    CakeSharing cs;
    int H;
    cin >> H;
    vector<string> roses(H);
    getVector(roses);
    int NP;
    cin >> NP;

    vector<string> ret = cs.cut(roses, NP);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
