#include <iostream>
using namespace std;

int main()
{
    int arr[50];
    int cases,len,i,j,l,swap,temp;
    cin>>cases;
    while(cases--)
    {
        swap=0;
        cin>>len;
        l=len;
		i=0;
        while(l--)
        {            
            cin>>arr[i++];
        }
        for(i=0;i<len;i++)
        {
            for(j=0;j<len-1;j++)
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
        cout<<"Optimal train swapping takes "<<swap<<" swaps.\n";
    }
    return 0;
}
