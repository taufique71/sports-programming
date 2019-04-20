#include <iostream>
using namespace std;

int main(){
    double paper_rate;
    double cover_rate;
    double paper_width;
    double cover_width;
    double n;
    cin >> paper_rate >> cover_rate >> paper_width >> cover_width >> n;
    double time_to_eat_paper = paper_width / paper_rate;
    double time_to_eat_cover = cover_width / cover_rate;
    double time_to_eat_file = time_to_eat_cover + time_to_eat_paper + time_to_eat_cover;
    n = n - time_to_eat_paper;
    if(n < 0.000){
        cout << "paper" << endl;
    }
    else{
        n = n - time_to_eat_cover;
        if(n < 0.000) {
            cout << "cover" << endl;
        }
        else{
            while(n >= 0.000){
                n = n - time_to_eat_cover;
                if(n < 0.000){
                    cout << "cover" << endl;
                    break;
                }
                else{
                    n = n - time_to_eat_paper;
                    if(n < 0.000){
                        cout << "paper" << endl;
                        break;
                    }
                    else {
                        n = n - time_to_eat_cover;
                        if(n < 0.000){
                            cout << "cover" << endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
