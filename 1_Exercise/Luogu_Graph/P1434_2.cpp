#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> INT_1;
typedef vector<vector<int>> INT_2;
int R, C;
int answer(INT_2 &dp, INT_2 &high, int i, int j)
{
	if (dp[i][j] != 0)
		return dp[i][j];
	int a1 = 1, a2 = 1;
	// if (i-1>=1&&dp[i - 1][j] == 0)dp[i - 1][j] = answer(dp, high, i - 1, j);
	// if (i+1<=R&&dp[i + 1][j] == 0)dp[i + 1][j] = answer(dp, high, i + 1, j);
	// if (j+1<=C&&dp[i][j + 1] == 0)dp[i][j + 1] = answer(dp, high, i, j + 1);
	// if (j-1>=1&&dp[i][j - 1] == 0)dp[i][j - 1] = answer(dp, high, i, j - 1);

	if (high[i][j] > high[i - 1][j] && high[i][j] > high[i + 1][j])
	{
		if (i - 1 >= 1 && dp[i - 1][j] == 0)
			dp[i - 1][j] = answer(dp, high, i - 1, j);
		if (i + 1 <= R && dp[i + 1][j] == 0)
			dp[i + 1][j] = answer(dp, high, i + 1, j);
		a1 = max(dp[i - 1][j], dp[i + 1][j]) + 1;
	}

	if (high[i][j] <= high[i - 1][j] && high[i][j] > high[i + 1][j])
	{
		if (i + 1 <= R && dp[i + 1][j] == 0)
			dp[i + 1][j] = answer(dp, high, i + 1, j);
		a1 = dp[i + 1][j] + 1;
	}

	if (high[i][j] > high[i - 1][j] && high[i][j] <= high[i + 1][j])
	{
		if (i - 1 >= 1 && dp[i - 1][j] == 0)
			dp[i - 1][j] = answer(dp, high, i - 1, j);
		a1 = dp[i - 1][j] + 1;
	}

	/////////////////////////////////////////////////////////////////////
	if (high[i][j] > high[i][j - 1] && high[i][j] > high[i][j + 1])
	{
		if (j + 1 <= C && dp[i][j + 1] == 0)
			dp[i][j + 1] = answer(dp, high, i, j + 1);
		if (j - 1 >= 1 && dp[i][j - 1] == 0)
			dp[i][j - 1] = answer(dp, high, i, j - 1);
		a2 = max(dp[i][j - 1], dp[i][j + 1]) + 1;
	}
	if (high[i][j] > high[i][j - 1] && high[i][j] <= high[i][j + 1])
	{
		if (j - 1 >= 1 && dp[i][j - 1] == 0)
			dp[i][j - 1] = answer(dp, high, i, j - 1);
		a2 = dp[i][j - 1] + 1;
	}
	if (high[i][j] <= high[i][j - 1] && high[i][j] > high[i][j + 1])
	{
		if (j + 1 <= C && dp[i][j + 1] == 0)
			dp[i][j + 1] = answer(dp, high, i, j + 1);
		a2 = dp[i][j + 1] + 1;
	}
	return dp[i][j] = max(a1, a2);

	// int mx = 0;
	// if (high[i][j] > high[i - 1][j])
	// 	mx = max(mx, answer(dp, high, i - 1, j));
	// if (high[i][j] > high[i + 1][j])
	// 	mx = max(mx, answer(dp, high, i + 1, j));
	// if (high[i][j] > high[i][j - 1])
	// 	mx = max(mx, answer(dp, high, i, j - 1));
	// if (high[i][j] > high[i][j + 1])
	// 	mx = max(mx, answer(dp, high, i, j + 1));
	// return dp[i][j] = mx + 1;
}
int main(void)
{
	cin >> R >> C;
	if (R == C && R == 0)
	{
		cout << 0;
		return 0;
	}
	INT_2 high(R + 2, INT_1(C + 2, 2147483647));
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> high[i][j];
	INT_2 dp(R + 2, INT_1(C + 2, 0));

	// for (int i = 0; i < R + 2; i++)
	//	dp[i][0] = dp[i][C+1] = -2147483647;
	// for (int i = 0; i < C + 2; i++)
	//	dp[0][i] = dp[R + 1][0] = -2147493647;
	int ans = 0;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (dp[i][j] == 0)
				dp[i][j] = answer(dp, high, i, j);
			ans = max(dp[i][j], ans);
		}
	}
	cout << ans;
	return 0;
}