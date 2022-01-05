#include <math.h>
#include <limits.h>
#include <vector>
#include "TnT.h"

int f(int max)
{
	int ret = max;
	long long poww = (long long)max * max;
	long long sub = 2ll * max - 1;
	long long dec_scale = pow(10, (int)trunc(log10(max)) + 1);

	while (1)
	{
		ret--;
		poww -= sub;
		sub -= 2;

		if (dec_scale > 10ll * ret)
			dec_scale /= 10;

		//printf("%d ; %lld, %lld\n", ret, poww, dec_scale);

		if (poww % dec_scale == ret)
			return ret;
	}

}

int f_v2(int max)
{
	long long dec_scale = pow(10, (int)trunc(log10(max)) + 1);

	for (int i = max-1; i > 0; i--)
	{
		if (dec_scale > 10ll * i)
			dec_scale /= 10;

		if (((long long)i * i) % dec_scale == i)
			//return left;
			printf("%d\n", i);
	}

	return 0;
}

int f_faster(int till)
{
	int dp[SHRT_MAX];
	int eoa = 0;
	
					if (till <= 1)	return -1;
	dp[eoa++] = 1;	if (till <= 5)	return dp[eoa-1];
	dp[eoa++] = 5;	if (till <= 6)	return dp[eoa-1];
	dp[eoa++] = 6;	if (till <= 10)	return dp[eoa-1];


	for(long long dec_scale = 10; ;dec_scale *= 10)
	{ 
		int max = eoa;

		for (int left = 1; left < 10; left++)
		{
			for (int index = 0; index < max; index++)
			{
				long long sample = dec_scale * left + dp[index];

				if (sample >= till)
					return dp[eoa-1];

				if (((long long)sample * sample) % (dec_scale * 10) == sample)
					dp[eoa++] = sample;
					//printf("%lld\n", sample);
			}
		}
	}
}

int main(int argc, char** args)
{
	StopWatch timer;
	printf("\n%d", f_faster(INT_MAX));
	timer.Stop();
}