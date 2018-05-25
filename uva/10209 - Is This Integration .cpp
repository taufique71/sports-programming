#include <iostream>
#include <cmath>
using namespace std;

#define pi 2*acos(0.0)

int main()
{
	double a;
	double a_qrtr,a_tri,a_slm,a_gmbj;
	double a_stripe,a_dot,a_rest;

	while(cin>>a)
	{
		a_qrtr=(pi*a*a)/4;
		a_tri=(sqrt(3)*a*a)/4;
		a_slm=((pi*a*a)/6)-a_tri;
		a_gmbj=a_slm+a_tri+a_slm;
		a_rest=(a*a)-(a_qrtr+a_qrtr-a_gmbj);
		a_dot=a_qrtr-a_gmbj-a_rest;
		a_stripe=(a*a)-(4*a_dot)-(4*a_rest);
		printf("%0.3lf %0.3lf %0.3lf\n",a_stripe,4*a_dot,4*a_rest);
	}
	return 0;
}
