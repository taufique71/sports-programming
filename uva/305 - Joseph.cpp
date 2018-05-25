#include <iostream>
using namespace std;

#define SIZE 30

class queue
{
    int arr[SIZE];
    int f;
    int r;
public:
    queue()
    {
        f=0;
        r=0;
    }

    int size()
    {
        return ((SIZE-f+r)%SIZE);
    }

    void enqueue(int i)
    {
        arr[r]=i;
        r=(r+1)%SIZE;
    }

    int dequeue()
    {
        int a;
        a=arr[f];
        f=(f+1)%SIZE;
        return a;
    }
};
/****************************************************************************
******************************************************************************
********************************************************************************
int main()
{
    int k;
    long int m;

    while(cin>>k)
    {
        if(k<=0) break;
        else
        {
            for(m=1;1;m++)
            {
                int flag=1;
                queue q;
                for(int i=1;i<=(2*k);i++) q.enqueue(i);
                while(q.size()>k)
                {
                    for(long int i=1;i<m;i++)
                    {
                        q.enqueue(q.dequeue());
                    }
                    q.dequeue();
                }
                for(long int i=1;i<=k;i++)
                {
                    int check=q.dequeue();
                    if((check>=1)&&(check<=k)) flag=1;
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==1) break;
            }
        }
        cout<<m<<endl;
    }
    return 0;
}
*****************************************************************************************************
****************************************************************************************************
***************************************************************************************************/




/***************************************************************************************************
int main(void)
{
    int k=1,i=0;
    long int m;
    long int ans[13];

    while(i<=12)
    {
        for(m=1;1;m++)
        {
            int flag=1;
            queue q;
            for(int i=1;i<=(2*k);i++) q.enqueue(i);
            while(q.size()>k)
            {
                for(long int i=1;i<m;i++)
                {
                    q.enqueue(q.dequeue());
                }
                q.dequeue();
            }
            for(long int i=1;i<=k;i++)
            {
                int check=q.dequeue();
                if((check>=1)&&(check<=k)) flag=1;
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1) break;
        }
        ans[i]=m;
        i++;
        k++;
    }
    cout<<endl<<endl;
    while(cin>>k)
    {
        if(k==0) break;
        else cout<<ans[k-1]<<endl;
    }
    return 0;
}
*********************************************************************************************************/


long int ans[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
int main()
{
    int k;
    while(cin>>k)
    {
        if(k==0) break;
        else cout<<ans[k]<<endl;
    }
    return 0;
}
