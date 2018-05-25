#include <iostream>
using namespace std;

#define SIZE 1100

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

int main()
{
    int n,m;

    while(cin>>n)
    {
        if(n<=0) break;
        else
        {
            for(m=1;1;m++)
            {
                queue q;
                for(int i=1;i<=n;i++) q.enqueue(i);
                while(q.size()>1)
                {
                    q.dequeue();
                    for(int i=1;i<m;i++)
                    {
                        q.enqueue(q.dequeue());
                    }
                }
                if(q.dequeue()==2) break;
            }
        }
        cout<<m<<endl;
    }
    return 0;
}
