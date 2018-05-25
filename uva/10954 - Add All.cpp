#include <iostream>
#include <queue>
#define ZERO 0
using namespace std;

int main()
{
    int n;
    int i;
    int number;

    while(scanf("%d",&n) == 1)
    {
        if(n == 0) break;

        priority_queue<int,vector<int>,greater<int> > pq;

        for(i = 0 ; i < n ; i++)
        {
            scanf("%d",&number);
            pq.push(number);
        }

        int temp1,temp2;
        long long int answer = 0;

        i = 0;
        while(pq.size() > 1)
        {
            temp1 = pq.top();
            pq.pop();
            temp2 = pq.top();
            pq.pop();
            answer += temp1+temp2;
            pq.push(temp1+temp2);
        }

        printf("%lld\n",answer);
    }

    return 0;
}
