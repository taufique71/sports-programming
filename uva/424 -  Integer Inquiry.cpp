/***********************************************************************************************
#include <iostream>
#include <cstring>

using namespace std;

int check(char num[])
{
    int flag=0,i=0;

    while(num[i]!='\0')
    {

        if(num[i]!='0')
        {
            flag=1;
            break;
        }

        i++;

    }

    return flag;
}

int main()
{
    int i,j,max=0;
    char num[102],sum[102],temp[102];

    for(i=0;i<101;i++)
    {
        sum[i]='0';
        temp[i]='0';
    }

    sum[i]='\0';
    temp[i]='\0';

    cin>>num;

    while(check(num))
    {
        if(strlen(num)>max) max=strlen(num);

        for(i=0;i<101;i++) temp[i]='0';

        temp[i]='\0';
        int car=0;
        i=0,j=0;

        for(j=100,i=strlen(num)-1;i>=0;i--,j--)
        {
            temp[j]=((sum[j]-48+num[i]-48+car)%10)+48;
            car=(sum[j]-48+num[i]-48+car)/10;
        }

        while(j>=0)
        {
            temp[j]=((sum[j]-48+car)%10)+48;
            car=(sum[j]-48+car)/10;
            j--;
        }

        strcpy(sum,temp);

        cin>>num;

    }

    for(i=0;sum[i]=='0';i++);

    if((strlen(sum)-i)<max) i=102-max-1;

    while(sum[i]!='\0')
    {
        cout<<sum[i++];
    }

    cout<<endl;

    return 0;
}
*********************************************************************************************/

#include<stdio.h>
#include<string.h>

int result[11000];

int main()
{
    char a[101][101];
    int i,j,sum,k = 0,max = 0;
    int cary,n,g,l;
    while(scanf("%s",a[k]) && strcmp(a[k],"0"))
      k++;

    for(i = 0; i<k; i++)
      if(strlen(a[i])>max)
	max = strlen(a[i]);


    for(i = 0; i<k; i++)
    {
       g=0;
       l =strlen(a[i]);
       if(l>=99) continue;

       for(j=l-1;j>=0;j--)
       {
	  a[i][99-g] = a[i][j];
	  g++;
       }
       for(j = 0; j<=99-g; j++)   a[i][j] = '0';

   }


    n = 0;
    cary = 0;
   for(i = 99; i>99-max; i--)
   {

      sum = 0;
      for(j = 0; j<k; j++)
	if(a[j][i])
	  sum += a[j][i]-48;
      sum = sum+cary;
      cary = sum/10;
      result[n++] = sum%10;

   }
   if(cary) result[n++] = cary;
   for(i = n-1; i>=0; i--) printf("%d",result[i]);
   printf("\n");
   return 0;
}


