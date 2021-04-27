#include<stdio.h>

float Calc_Angle(int hour, int min, int sec);

int main()
{
	printf("%lf\n", Calc_Angle(2,10,00));
}


float Calc_Angle(int hour, int min, int sec)
{
	float min_nid = min * 6 + sec / 10;
	float hour_nid = hour * 30 + min_nid / 12;
	float diff = hour_nid - min_nid;

	if (diff < 0)
		diff += 360.0;

	return diff;
}