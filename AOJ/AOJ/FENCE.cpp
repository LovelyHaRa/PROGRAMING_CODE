#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(const vector<int> &h, int left, int right)
{
	// ���� ���: ������ 1�̸� ���� ���̸� ����
	if (left == right) return h[left];
	// ���� ����
	int mid = (left + right) / 2;
	// ���� ����
	int ret = max(solve(h, left, mid), solve(h, mid + 1, right));
	// ���� 3: �� �κп� ��� ��ġ�� �簢�� �� ���� ū ���� ã�´�.
	int low = mid, high = mid + 1; // �ʱ� ����
	int height = min(h[low], h[high]); // �ּ� ����
	ret = max(ret, height * 2); // ������ �ִ밪 ����
	// �簢���� ��� ���� �� �� ���� �ݺ�
	while (left < low || high < right)
	{
		// �������� �� ū ��� or ���� Ž���� ���� ���
		if (high < right && (low == left || h[low - 1] < h[high + 1]))
		{
			high++; // ������ �簢���� ����
			height = min(height, h[high]); // ���� ����
		}
		// �׷��� ���� ���
		else
		{
			low--; // ���� �簢���� ����
			height = min(height, h[low]); // ���� ����
		}
		// ������ �ִ밪 ����
		ret = max(ret, (high - low + 1)*height);
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> h(n);
		for (int i = 0; i < n; i++)
			cin >> h[i];
		cout << solve(h, 0, n - 1)<<'\n';
	}
}