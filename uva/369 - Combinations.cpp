#include <stdio.h>
#include <math.h>

int main ()
{
	int i,j;
	double n,m,up,down,result;

	while(scanf("%lf %lf",&n,&m)){
		if(n==0&& m==0)break;
		//initialization
		up=down=1.0;

		if(m>(n-m)){
			i=(int)m+1;
			j=(int)n;
			for(i;i<=j;i++)up*=i;
			j=(int)(n-m);
			for(i=1;i<=j;i++)down*=i;
		}
		else {
			i=(int)(n-m)+1;
			j=(int)n;
			for(i;i<=j;i++)up*=i;
			j=(int)m;
			for(i=1;i<=j;i++)down*=i;
		}
		result=floor((up/down)+0.5);
		printf("%.0lf\n",result);
		//printf("%.0lf things taken %.0lf at a time is %.0lf exactly.\n",n,m,result);
	}
	return 0;
}
