	#include <iostream>


	using namespace std;

	char board[6][6];
	char input[11];
	bool checker[6][6][11];

	#define null '\0'

	void initboard()
	{
		for (int i = 1;i < 6;i++)
		{
			for (int j = 1;j < 6;j++)
			{
				board[i][j] = null;
			}
		}
	}

	void initChecker()
	{
		for (int i = 0;i < 6;i++)
		{
			for (int j = 0;j < 6;j++)
			{
				for (int k = 0;k < 11;k++)
				{
					checker[i][j][k] = true;
				}
			}
		}
	}

	void getboard()
	{
		for (int i = 1;i < 6;i++)
		{
			for (int j = 1;j < 6;j++)
			{
				scanf(" %c", &board[i][j]);
			}
		}
	}

	int dy[8] = { 1, 1, 0, -1, -1, -1,0,  1 };
	int dx[8] = {  0, 1, 1,  1,  0, -1,-1,-1 };

	bool isBound(int y, int x)
	{
		if (y < 1 || y > 5 || x < 1 || x > 5) return false;

		return true;
	}

	bool findstring(int y, int x, char* s, int idx)
	{
		//checker[y][x][idx] = true;
		if (isBound(y, x) == false) return false;
		if (s[0] == null)			return true;
		if (s[0] != board[y][x]) return false;

		for (int i = 0; i < 8; i++)
			if (checker[y + dy[i]][x + dx[i]][idx + 1] == true) {
				if (findstring(y + dy[i], x + dx[i], s + 1, idx + 1) == true)
					return true;
			}

		checker[y ][x ][idx ] = false;
		return false;
	}

	void initstring()
	{
		for (int i = 0;i < 11;i++)
			input[i] = null;
	}
	int main(void)
	{

		int t, m;
		int flag = 0;
		scanf("%d", &t);

		for (;t > 0;t--)
		{
			initboard();
			getboard();

			scanf("%d", &m);

			for (int i = 0;i < m;i++)
			{
				initstring();
				initChecker();
				scanf("%s", input);
				flag = 0;
				for (int k = 1; k < 6;k++) {
					for (int l = 1; l < 6;l++) {
						if (findstring(k, l, input, 0) == true) {
							printf("%s YES\n", input);
							flag = 1;
							break;
						}
					}
					if (flag == 1) break;
				}
				if (flag == 0)
					printf("%s NO\n", input);
			}
		}

		return 0;
	}
