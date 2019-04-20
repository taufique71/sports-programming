#include <iostream>
#include <vector>
#define MAX 503
using namespace std;
long int grid[MAX][MAX];
long int sum[MAX][MAX];
long int res[MAX][MAX];
int a[MAX][MAX];
int b[MAX][MAX];
int c[MAX][MAX];
int d[MAX][MAX];
int n;

long int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];       
        }
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                sum[i][j] = grid[i][j];
            }      
            else if(i == 0){
                sum[i][j] = grid[i][j] + sum[i][j-1];
            }
            else if(j == 0){
                sum[i][j] = grid[i][j] + sum[i-1][j];
            }
            else{
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                a[i][j] = i;
                b[i][j] = j;
                c[i][j] = i;
                d[i][j] = j;
                res[i][j] = grid[i][j];
            }      
            else if(i == 0){
                int x = res[i][j-1] + grid[i][j];
                int y = grid[i][j];
                if(x > y){
                    res[i][j] = x;
                    a[i][j] = a[i][j-1];
                    b[i][j] = b[i][j-1];
                    c[i][j] = i;
                    d[i][j] = j;
                }
                else{
                    res[i][j] = y;
                    a[i][j] = i;
                    b[i][j] = j;
                    c[i][j] = i;
                    d[i][j] = j;
                }
            }
            else if(j == 0){
                int x = res[i-1][j] + grid[i][j];
                int y = grid[i][j];
                if(x > y){
                    res[i][j] = x;
                    a[i][j] = a[i-1][j];
                    b[i][j] = b[i-1][j];
                    c[i][j] = i;
                    d[i][j] = j;
                }
                else{
                    res[i][j] = y;
                    a[i][j] = i;
                    b[i][j] = j;
                    c[i][j] = i;
                    d[i][j] = j;
                }
            }
            else{
                int x = res[i-1][j] + sum[i][j] - sum[c[i-1][j]][d[i-1][j]] - sum[a[i-1][j]][j] ;
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i][j];
            }
        }
    }
    return 0;
}
