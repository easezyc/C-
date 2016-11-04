#include<stdio.h>
#include<math.h>
int main(void)
{
	int n,i;
	double x,y;
	scanf("%d",&n);

	for(i=1;i<=n;i=i+1)
	{
		scanf("%lf",&x) ;
	if(x<0)
		y=pow((x+1),2)+2*x+1/x;
	else
		y=sqrt(x);
	printf("%.2f\n",y);
	}
	return 0;
}