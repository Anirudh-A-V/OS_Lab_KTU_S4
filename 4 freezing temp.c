#include<stdio.h>
int main()
{
	float temp;
	printf("Enter the value of temperature in celcius:\n");
	scanf("%f", &temp);
	if(temp<0.0)
	{
		printf("Temperature is below freezing temperature:\n");
	}
	else if(temp==0)
	{
		printf("Temperature is equal to freezing temperature:\n");
	}
	else
	{
		printf("Temperature is more the freezing temperature:\n");
	}
	return 0;
}
