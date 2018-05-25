#include <iostream>
#include <cmath>
using namespace std;

class my_class{
        public:
        int count,n,m,x[10010],*a,prime[6000],p;
        bool isprime(int n){
                int i=0,f=sqrt(n);
				while(prime[i]<=f){
					if(n%prime[i]==0)return false;
					i++;
				}
                return true;
            }
        void init(){
			bool temp[11000]={0};
			prime[0]=2;
			p=1;

			int i,j;
			for( i=3;i*i<=11000;i+=2)
				if(temp[i]==false){
					prime[p]=i;
					p++;
					for( j=i*i;j<=11000;j+=i)temp[j]=true;
				}
			for(i;i<=11000;i+=2)
				if(temp[i]==false){
					prime[p]=i;
					p++;
				}
			x[0]=0;
			a=&x[1];
			for(i=0;i<=10000;i++){
				if(isprime(i*i+i+41))a[i]=a[i-1]+1;
				else a[i]=a[i-1];
			}
		}
        void calculation(){
                //cout<<a[m]-a[n-1]<<endl;
                printf("%.2lf\n",((double)(a[m]-a[n-1])*100.00/(double)(m-n+1))+1e-9);
            }
    };

int main()
{
    my_class ob;
	ob.init();
    while(scanf("%d %d",&ob.n,&ob.m)!=EOF){
            if(ob.n>ob.m){
                    int temp=ob.n;
                    ob.n=ob.m;
                    ob.m=temp;
                }
            ob.calculation();
            /*
                for(int i=42;i<100;i++)if(ob.isprime(i))cout<<"prime "<<i<<endl;
            cout<<ob.count<<endl;
            */
        }
	return 0;
}
