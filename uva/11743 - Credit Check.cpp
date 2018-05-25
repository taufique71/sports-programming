#include <iostream>
using namespace std;

int main()
{
    char credit_no[20];
    int dbl[10];
    int non_dbl[10];
    int count = 0;
    char gar[5];
    int n_case;
    int i,j,k;

    cin >> n_case;
    gets(gar);
    while(n_case--)
    {
        gets(credit_no);
        j = 0;
        k = 0;
        count = 0;
        for(i = 0 ; credit_no[i] ; i++)
        {
            switch(i)
            {
                case 0:
                dbl[j++] = (credit_no[i] - 48) * 2;
                break;

                case 1:
                non_dbl[k++] = (credit_no[i] - 48);
                break;

                case 2:
                dbl[j++] = (credit_no[i] - 48) * 2;
                break;

                case 3:
                non_dbl[k++] = (credit_no[i] - 48);
                break;

                case 5:
                dbl[j++] = (credit_no[i] - 48) * 2;
                break;

                case 6:
                non_dbl[k++] = (credit_no[i] - 48);
                break;

                case 7:
                dbl[j++] = (credit_no[i] - 48) * 2;
                break;

                case 8:
                non_dbl[k++] = (credit_no[i] - 48);
                break;

                case 10:
                dbl[j++] = (credit_no[i] - 48) * 2;
                break;

                case 11:
                non_dbl[k++] = (credit_no[i] - 48);
                break;

                case 12:
                dbl[j++] = (credit_no[i] - 48) * 2;
                break;

                case 13:
                non_dbl[k++] = (credit_no[i] - 48);
                break;

                case 15:
                dbl[j++] = (credit_no[i] - 48) * 2;
                break;

                case 16:
                non_dbl[k++] = (credit_no[i] - 48);
                break;

                case 17:
                dbl[j++] = (credit_no[i] - 48) * 2;
                break;

                case 18:
                non_dbl[k++] = (credit_no[i] - 48);
                break;
            }
        }

        for(i = 0 ; i < 8 ; i++)
        {
            count += non_dbl[i];
            if(dbl[i] >= 10)
            {
                count += dbl[i] % 10;
                count += dbl[i] / 10;
            }
            else count += dbl[i];
        }

        if((count % 10) == 0) cout << "Valid" << endl;
        else cout << "Invalid" << endl;
    }
    return 0;
}
