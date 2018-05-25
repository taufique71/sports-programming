#include <iostream>
using namespace std;

int main()
{
    int arr[1000];
    int num,len,swap,temp;
    while(cin>>num)
    {
        len=num;
        swap=0;
        int i=0;
        while(num--)
        {
            cin>>arr[i++];
        }
        for(i=0;i<len;i++)
        {
            for(int j=0;j<len-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    swap++;
                }
            }
        }
        cout<<"Minimum exchange operations : "<<swap<<endl;
    }
    return 0;
}
