// �׸��� �˰���
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	int n;
	vector<vector<int>> meeting;
	cin >> n;
	meeting.resize(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		/**
		* 2���� ���� ���Ľ� ù ���� �������� �����ϹǷ� ��ġ�� �ٲ㼭 �Է¹���
		*/
		meeting[i].push_back(b);
		meeting[i].push_back(a);
	}
	/*
	1. ȸ�ǰ� ������ �ð��� �������� �������� �����Ѵ�.
	2. ù��° �ð��� ������ �ְ���(�׸��� �˰��� Ư��, res = 1)
	3. ���� Ž���Ѵ�.
	4. ���� ȸ�ǰ� ������ �ð����� ���� ȸ�� ���۽ð��� ũ�ų� ������ ȸ�ǰ���
	5. ȸ�ǰ� �����ϸ� ���������� 3~4�� �ݺ��Ѵ�.
	6. ����Ž���� ������ �����ϸ� ������ ����Ѵ�.
	*/
	// 1.
	sort(meeting.begin(), meeting.end());
	// 2.
	int k = 0, res = 1;
	while (1)
	{
		int i;
		// 3.
		for (i = k + 1; i < n; i++)
		{
			// 4.
			if (meeting[k][0] <= meeting[i][1])
			{
				// 5.
				res++;
				k = i;
				break;
			}
		}
		// 6.
		if (i == n)
			break;
	}
	cout << res << '\n';
}