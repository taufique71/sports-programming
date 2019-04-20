#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m, n, rotate;
    cin >> m >> n;
    vector< vector<int> > grid(m);
    for(int i = 0; i < m ; i++){
        grid[i] = vector<int>(n, 0);
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    cin >> rotate;
    if(rotate == -1){
        for(int j = n-1; j >= 0; j--){
            for(int i = 0; i <= m-1; i++){
                cout << grid[i][j];
                if(i < m-1) cout << " ";
            }
            cout << endl;
        }
    }
    else{
        for(int j = 0; j <= n-1; j++){
            for(int i = m-1; i >= 0; i--){
                cout << grid[i][j];
                if(i > 0) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
