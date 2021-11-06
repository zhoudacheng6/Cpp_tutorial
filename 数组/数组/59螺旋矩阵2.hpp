#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		//定义二维数组：n列一维数组[0,0,0...]
		vector<vector<int>> res(n, vector<int>(n, 0));
		int start_x = 0 , start_y = 0;
		int offset = 1;
		int i, j;
		int loop = n / 2;
		int count = 1;
		while (loop--)
		{
			i = start_x;
			j = start_y;
			for (j = start_y; j < n+start_x - offset; j++)
			{
				res[i][j] = count++;
			}
			for (i = start_x; i < n + start_y - offset; i++)
			{
				res[i][j] = count++;
			}
			for ( ; j > start_y ; j--)
			{
				res[i][j] = count++;
			}
			for (; i > start_x; i--) {
				res[i][j] = count++;
			}

			// 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
			start_x++;
			start_y++;

			// offset 控制每一圈里每一条边遍历的长度
			offset += 2;
		}
		if (n % 2 == 1)
		{
			res[n / 2][n / 2] = count;
		}
		return res;
	}
};