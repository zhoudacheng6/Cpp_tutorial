#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		//�����ά���飺n��һά����[0,0,0...]
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

			// �ڶ�Ȧ��ʼ��ʱ����ʼλ��Ҫ���Լ�1�� ���磺��һȦ��ʼλ����(0, 0)���ڶ�Ȧ��ʼλ����(1, 1)
			start_x++;
			start_y++;

			// offset ����ÿһȦ��ÿһ���߱����ĳ���
			offset += 2;
		}
		if (n % 2 == 1)
		{
			res[n / 2][n / 2] = count;
		}
		return res;
	}
};