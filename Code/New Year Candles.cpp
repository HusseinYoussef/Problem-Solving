#include <iostream>

using namespace std;

int main()
{
	int original_Candles, recycle,hours,bonus_hours;
	int remained=0,waste=0;
//*****************************************

	cin >> original_Candles >> recycle;

	hours = original_Candles;                             // Each available candle provides 1 hour
	                                                      // the Division will result the number of candles that can 
	                                                      // be recycled using the went-out candles
	while (true)
	{
		remained = 0;
		remained = original_Candles % recycle;
		waste += remained;
		bonus_hours = (original_Candles - remained) / recycle;

		hours += bonus_hours;
		original_Candles = bonus_hours;
		if (original_Candles < recycle)
		{
			waste += original_Candles;
			break;
		}
	}
	remained = 0;
	while (true)
	{
		                                              // emsk wr2a w 2lm 3shan t3rf t3mlha xD
		remained = waste % recycle;
		waste = (waste - remained) / recycle;
		hours += waste;
		if (waste + remained == recycle)
		{
			hours++;
			break;
		}
		else if (waste < recycle)
			break;
	}
	cout << hours;
	return 0;
}