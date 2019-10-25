#include <math.h>
#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>

struct timeval tv1,tv2,dtv;
struct timezone tz;

void time_start()
{
	gettimeofday(&tv1, &tz);
}

long time_stop()
{
	gettimeofday(&tv2, &tz);
	dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
	dtv.
}

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


int main()
{
	time_t start, end;
	double x;
	printf("Vvedite chislo			");
	scanf("%lf", &x);
	time(&start);
	printf("\nKoren' chisla:		%f \n",sqrtm(x));
	time(&end);
	double seconds = difftime(end, start);
	printf("Time:		%f\n",seconds);
}
