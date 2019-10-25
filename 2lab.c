#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <iostream>

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

int main()
{
	time_t start, end;
	double x;
	time(&start);
	for(int i = 0; i < 500000; i++)
	{
		sint(162843121);
	}
	time(&end);
	double seconds = difftime(end, start);
	printf("Time:		%f\n",seconds);
}
