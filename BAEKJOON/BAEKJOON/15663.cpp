#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> a, selected, check;
void permutation(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << selected[i] << ' ';
		cout << '\n';
		return;
	}
	vector<int> visited(10001); // ���� �湮�Ǿ����� ���θ� �ľ�
	for (int i = 0; i < n; i++)
	{
		// ���� �� ��ü �ߺ����ο� ���� ��ġ�� �ߺ����θ� ���ÿ� �Ǵ�
		if (visited[a[i]] || check[i]) continue;
		else
		{
			visited[a[i]] = 1; // �� �湮 üũ
			selected[cnt] = a[i]; // ���� ����
			check[i] = 1; // ���� ��ġ üũ
			permutation(cnt + 1);
			check[i] = 0; // ���� ��ġ üũ ����
		}
	}
	
}

int main(void)
{	
	cin >> n >> m;
	a.resize(n);
	selected.resize(m);
	check.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	permutation(0);
}