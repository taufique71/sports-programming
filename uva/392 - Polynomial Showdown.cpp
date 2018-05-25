#include <iostream>
using namespace std;

int mod(int n)
{
    if(n>=0) return n;
    else return (-n);
}

char sign(int n)
{
    if(n>=0) return '+';
    else if(n<0) return '-';
}

int main()
{
    int arr[9];
    int flag=0,count=0;

    while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5]>>arr[6]>>arr[7]>>arr[8])
    {
        flag=0;
        count=0;
        for(int i=0;i<9;i++)
        {
            if(arr[i]==0) continue;
            else
            {
                if(flag==0)
                {
                    if(sign(arr[i])=='-') cout<<'-';
                    flag=1;
                }
                else cout<<' '<<sign(arr[i])<<' ';
                if(mod(8-i)==0) cout<<mod(arr[i]);
                else if(mod(8-i)==1)
                {
                    if(mod(arr[i])>1) cout<<mod(arr[i])<<"x";
                    else cout<<"x";
                }
                else
                {
                    if(mod(arr[i])>1) cout<<mod(arr[i])<<"x^"<<mod(8-i);
                    else cout<<"x^"<<mod(8-i);
                }
                count=1;
            }
        }
        if(count==0) cout<<0;
        cout<<endl;
    }
    return 0;
}
