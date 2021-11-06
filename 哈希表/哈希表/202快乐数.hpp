#include<iostream>
#include <vector>

using namespace std;

class Solution202 {
public:
	int getSum(int n)
	{
		int sum = 0;
		while (n)
		{
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		return sum;
	}
	bool isHappy(int n) {

	}
};