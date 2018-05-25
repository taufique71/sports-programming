#include <iostream>
using namespace std;

int main()
{
	int cases,i,j,k,ampl,freq;
	cin>>cases;
	while(cases--)
	{
		cin>>ampl>>freq;
		for(i=1;i<=freq;i++)
		{
			for(j=1;j<=ampl;j++)
			{
				for(k=1;k<=j;k++) cout<<j;
				cout<<'\n';
			}
			for(j=ampl-1;j>=1;j--)
			{
				for(k=1;k<=j;k++) cout<<j;
				cout<<'\n';			
			}
			if((i==freq)&&(cases==0))
				continue;
			cout<<'\n';
		}
		if(!(i>freq)) cout<<'\n';
	}
	return 0;
}