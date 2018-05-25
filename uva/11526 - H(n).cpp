/*#include <cmath>
#include <cstdio>

int main(void){
	int t; scanf("%d", &t);
	for(int n; t-- && scanf("%d", &n) == 1; )
	{
	long long s = 0;
	if(n > 0){
	int L = floor(sqrt(n));
	for(int i = 1, q, pq = n; i <= L; ++i){
	q = n / i;
	s += q + (pq - q) * (i - 1);
	pq = q;
	}
	if(n / L > L) s += L;
	}
	printf("%lld\n", s);
    }
}*/

/*#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long int n;
    unsigned long long int lim;
    int n_case;
    cin >> n_case;

    while(n_case--)
    {
        cin >> n;
        long long int res = 0;
        if(n >= 1)
        {
            lim = floor(sqrt(n));
            long long int i;
            long long int now;
            long long int prev = n;
            for(i = 1 ; i <= lim ; i++)
            {
                now = n/i;
                res += now;
                res += (prev-now)*(i-1);
                prev = now;
            }
        }
        if(n/lim > lim) res += lim;
        printf("%lld\n",res);
    }

}*/

#include <iostream>
#include <cmath>
using namespace std;

long long H(long long n){
    if(n<=0)return 0;
      long long res =n;
      long long i,pre=n,tmp;
      for(i=2;i<=n;i++)
        {
            res+=(tmp=n/i);
            if(tmp!=pre)
                {
                    res+=(n/tmp-i)*(tmp);
                    i=n/tmp;
                    pre=tmp;
                }

        }
     return res;
}
int main()
{
    long long n,t;
    cin>>t;
    while(t--)cin>>n,cout<<H(n)<<endl;
    return 0;
}
