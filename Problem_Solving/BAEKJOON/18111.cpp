#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, b;
	cin >> n >> m >> b;
	vector<vector<int>> land(n, vector<int>(m));
	int maxHeight = 0, minHeight = 256; // ���� �ִ� ���� ������ �ּ� ���� ����
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> land[i][j];
			// ���� �ִ� ���� ������ �ּ� ���� ������ ���Ѵ�
			if (land[i][j] < minHeight) minHeight = land[i][j];
			if (land[i][j] > maxHeight) maxHeight = land[i][j];
		}
	}
	// �ּ� �ð�, �ּ� �ð��� ���� ����
	int minTime = 1987654321, minTimeHeight = 64 * 10e6;
	// �ּ� ���̺��� �ִ� ���̱��� Ž���Ѵ�
	for (int h = minHeight; h <= maxHeight; h++)
	{
		int remove = 0, build = 0; // ������ ��� ��, ��ġ�� ��� ��
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int diff = land[i][j] - h; // ���� ���� ���
				if (diff > 0) remove += diff; // ����� �����ؾ� �Ѵ�
				else if (diff < 0) build += (-diff); // ������ ��ġ�ؾ� �Ѵ�
			}
		}
		// ������ ��(������ ���� ������� ȯ��) + b �� ��ġ�� �������� ���ƾ�
		// �׼��� ���� �ϴ�
		if (remove + b >= build)
		{
			int time = remove * 2 + build; // �ð� ���
			// �ּ� �ð� ����(���� ��� ���̸� ����, ���̴� Ž���� ���� ������ �ִ밪)
			if (time <= minTime)
			{
				minTime = time;
				minTimeHeight = h;
			}
		}
	}
	cout << minTime << ' ' << minTimeHeight << '\n';
}