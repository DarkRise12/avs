#include <math.h>
#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>

struct timeval tv1,tv2,dtv;

struct timezone tz;

void time_start() { gettimeofday(&tv1, &tz); }

long time_stop()

{ gettimeofday(&tv2, &tz);

  dtv.tv_sec= tv2.tv_sec -tv1.tv_sec;

  dtv.tv_usec=tv2.tv_usec-tv1.tv_usec;

  if(dtv.tv_usec<0) { dtv.tv_sec--; dtv.tv_usec+=1000000; }

  return dtv.tv_sec*1000+dtv.tv_usec/1000;

}

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
	time_start();
	for(int i = 0; i < 50000000; i++)
	{
		sint(162843121);
	}
	printf("Time: %lf\n", time_stop()/1000.);
}
