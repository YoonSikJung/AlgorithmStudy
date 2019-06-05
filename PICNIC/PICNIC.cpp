

#include <iostream>	

using namespace std;

int Person;
int Cnt[100];
int Pair[10][100];
int check[10];
int ans;

void Init()
{
	Person = ans = 0;
	for (int i = 0;i < 10;i++){
		check[i] = 0;
		Cnt[0] = 1;
		Pair[i][0] = i;
		for (int j = 1;j < 100;j++) {
			Pair[i][j] = Pair[i][j] = -1;
			Cnt[j] = 1;
		}
	}
}

void Swap(int& a, int& b) {
	int t;
	t = a; 	a = b; 	b = t;
}

void GetPeople()
{
	int t1, t2, c;
	scanf("%d %d", &Person, &c);
	
	for (int i = 0;i < c; i++) {
		scanf("%d %d", &t1, &t2);
		if (t1 > t2) Swap(t1, t2);

		Pair[t1][Cnt[t1]++] = t2;
		//Pair[t2][Cnt[t2]++] = t1;
	}
}



void Calc(int p1, int p2, int n)
{
	bool isEnd = 1;
	

	for (int i = 0;i < Person;i++) {
		if (check[i] != 1) isEnd = 0;
	}
	if (isEnd != 0) {
		ans++;
		return;
	}

	while ( (++n)<= Person) {
		
		if (Pair[n][1] == -1) continue;

		if (check[Pair[n][0]] != 1) {
			for (int i = 1; i < Cnt[n]; i++) {
				if (check[Pair[n][i]] != 1) {
					check[Pair[n][0]] = check[Pair[n][i]] = 1;
					Calc(Pair[n][0], Pair[n][i], n);
					check[Pair[n][0]] = check[Pair[n][i]] = 0;
				}
			}
		}
	}
	//check[p1] = check[p2] = 0;
}

int main(void)
{
	int t;

	scanf("%d", &t);

	for (int i = 0;i < t; i++) {
		Init();
		GetPeople();

		for (int j = 1; j < Cnt[0]; j++)
		{
			check[Pair[0][0]] = check[Pair[0][j]] = 1;
			Calc(Pair[0][0], Pair[0][j], 0);
			check[Pair[0][0]] = check[Pair[0][j]] = 0;
		}
		printf("%d\n", ans);
	}

}
