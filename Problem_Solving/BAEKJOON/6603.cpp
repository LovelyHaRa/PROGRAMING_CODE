#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> k, check;

// DFS�� �̿��� ���� ����
void combination(int start, int cnt)
{
	// ���� ���: ���� 6���� üũ�ϸ�
	if (cnt == 6)
	{
		for (int i = 0; i < n; i++)
		{
			// üũ �� �͸� ���
			if(check[i])
			cout << k[i] << ' ';
		}
		cout << '\n';
		return;
	}
	// start���� �迭 ���̱��� �ݺ�
	for (int i = start; i < n; i++)
	{
		// �̹� üũ�Ǿ��ٸ� �ǳʶٱ�
		if (check[i]) continue;
		// üũ
		check[i] = 1;
		// DFS Ž��
		combination(i, cnt + 1);
		// ���󺹱�
		check[i] = 0;
	}
}

int main(void)
{
	while (1)
	{		
		cin >> n;
		if (!n) break;
		k.resize(n);
		check.resize(n);
		for (int i = 0; i < n; i++)
			cin >> k[i];
		sort(k.begin(), k.end());
		combination(0, 0);
		cout << '\n';
		k.clear();
		check.clear();
	}
}