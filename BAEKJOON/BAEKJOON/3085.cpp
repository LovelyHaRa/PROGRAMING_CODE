#include<iostream>
#include<string>
#include<vector>

using namespace std;

char candy[4] = { 'C','P','Z','Y' };

// swap
void swap(vector<string>&arr, int p, int q, int r, int s)
{
	char t = arr[p][q];
	arr[p][q] = arr[r][s];
	arr[r][s] = t;
}

// �� �˻�
int eatRowCandy(const vector<string>&arr, int row)
{	
	int max = 0, cnt = 0;
	// ĵ�� ������ŭ �ݺ�
	for (int i = 0; i < 4; i++)
	{
		// ���ӵ� ī��Ʈ ����
		cnt = 0;
		for (int j = 0; j < arr.size(); j++)
		{
			if (candy[i] == arr[j][row])
				cnt++;
			else
			{
				max = max < cnt ? cnt : max;
				cnt = 0;
			}
		}
		// ī��Ʈ �ִ밪 ����
		max = max < cnt ? cnt : max;
	}
	// �ִ밪 ����
	return max;
}

// �� �˻�
int eatColCandy(const vector<string>&arr, int col)
{
	int max = 0, cnt = 0;
	// ĵ�� ������ŭ �ݺ�
	for (int i = 0; i < 4; i++)
	{
		// ���ӵ� ī��Ʈ ����
		cnt = 0;
		for (int j = 0; j < arr.size(); j++)
		{
			if (candy[i] == arr[col][j])
				cnt++;
			else
			{
				max = max < cnt ? cnt : max;
				cnt = 0;
			}
		}
		// ī��Ʈ �ִ밪 ����
		max = max < cnt ? cnt : max;
	}
	// �ִ밪 ����
	return max;
}

int main(void)
{
	int n;
	cin >> n;
	vector<string> bomboni(n);
	for (int i = 0; i < n; i++)
		cin >> bomboni[i];
	int max = -1;
	// 1. ����Ž��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cnt;
			// 2. �ೢ�� ��ȯ
			if (i + 1 < n) // ������ ���� ��ȯ ����
			{
				// 3. ����ĭ, ��ĭ ��ȯ
				swap(bomboni, i, j, i + 1, j);
				// 4. ����ĭ �� �˻� �� �ִ밪 ����
				cnt=eatRowCandy(bomboni, j);
				max = max < cnt ? cnt : max;
				// 5. ����ĭ �� �˻� �� �ִ밪 ����
				cnt = eatColCandy(bomboni, i);
				max = max < cnt ? cnt : max;
				// 6. ��ĭ �� �˻� �� �ִ밪 ����
				cnt = eatColCandy(bomboni, i + 1);
				max = max < cnt ? cnt : max;
				// 7. ���� ����
				swap(bomboni, i, j, i + 1, j);
			}
			// 8. ������ ��ȯ
			if (j + 1 < n) // ������ ���� ��ȯ ����
			{
				// 9. ����ĭ, ��ĭ ��ȯ
				swap(bomboni, i, j, i, j + 1);
				// 10. ����ĭ �� �˻� �� �ִ밪 ����
				cnt=eatRowCandy(bomboni, j);
				max = max < cnt ? cnt : max;
				// 11. ��ĭ �� �˻� �� �ִ밪 ����
				cnt = eatRowCandy(bomboni, j + 1);
				max = max < cnt ? cnt : max;
				// 12. ����ĭ �� �˻� �� �ִ밪 ����
				cnt = eatColCandy(bomboni, i);
				max = max < cnt ? cnt : max;
				// 13. ���� ����
				swap(bomboni, i, j, i, j + 1);
			}
		}
	}
	// 14. �ִ밪 ���
	cout << max;
}