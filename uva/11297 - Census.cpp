#include <iostream>
#define N 505
using namespace std;

int main()
{
	int i,j,mat[N][N],n,m,c,x1,x2,y1,y2,v,max,min;
	char ch;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)scanf("%d",&mat[i][j]);
	scanf("%d",&c);
	while(c--){
		cin.get();
		scanf("%c",&ch);
		if(ch=='c'){
			scanf("%d %d %d",&x1,&y1,&v);
			mat[x1][y1]=v;
		}
		else{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			//cin>>x1>>y1>>x2>>y2;
			//output
			max=min=mat[x1][y1];
			for(i=x1;i<=x2;i++)
				for(j=y1;j<=y2;j++){
					if(max<mat[i][j])max=mat[i][j];
					if(min>mat[i][j])min=mat[i][j];
				}
			//
			printf("%d %d\n",max,min);
		}
	}
	return 0;
}