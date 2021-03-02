#include<cstdio>
#include<vector>

using namespace std;

int n, s;
vector<int> v;
int res = 0;

// dfs �̿�
void dfs(int i, int sum)
{
	if (i == n) return; // ���� ����
	if (sum + v[i] == s) res++;
	
	dfs(i + 1, sum); // ���� ���� ���� ���ϴ� ���
	dfs(i + 1, sum + v[i]); // ���� ���� ���� �ϴ� ���
}

int main(void)
{
	scanf("%d %d", &n, &s);
	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	dfs(0, 0);
	printf("%d", res);
}