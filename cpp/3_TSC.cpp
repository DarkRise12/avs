#include <iostream>
#include <stdio.h>
#include <inttypes.h>
#include <time.h>

typedef unsigned long long TimeVal;

const double PI=3.1415926535897932384650288;

double sint(double x){
  double sign=1;
  if (x<0){
    sign=-1.0;
    x=-x;
  }
  if (x>360) x -= int(x/360)*360;
  x*=PI/180.0;
  double res=0;
  double term=x;
  int k=1;
  while (res+term!=res){
    res+=term;
    k+=2;
    term*=-x*x/k/(k-1);
  }

  return sign*res;
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
	first = getticks();
	for(int i = 0; i < 50000000; i++)
	{
		sint(162843121);
	}
	second = getticks();
	unsigned time = (unsigned)((second - first) / 2600000);//3200000
	printf("Time:		%lf\n",time/1000.);//1000.
}
