#include <math.h>
#include <stdio.h>
#include <inttypes.h>
#include <time.h>

typedef unsigned long long TimeVal;

double fabss(double x)
{
	return x < 0 ? -x : x;
}

double sqrtm(double x)
{	
	static const double eps = 1e-20;
	
	double prev;
	double next = x;
	int n=0;
	do
	{
		prev = next;
		next = (prev + x / prev) / 2;
		n++;
	}while (n<400000000);
	return next;
}

static TimeVal getticks()
{
	unsigned a, d;
	asm("cpuid");
	asm volatile ("rdtsc": "=a" (a), "=d" (d));
	return (((TimeVal)a) | (((TimeVal)d) << 32));
}

int main()
{
	TimeVal first, second;
	double x;
	printf("Vvedite chislo			");
	scanf("%lf", &x);
	first = getticks();
	printf("\nKoren' chisla:		%f \n",sqrtm(x));
	second = getticks();
	unsigned time = (unsigned)((second - first) / 2600000);//3200000
	printf("Time:		%lf\n",time/1000.);//1000.
}
