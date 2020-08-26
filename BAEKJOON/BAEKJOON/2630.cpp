// �������� ����Ʈ��
#include<iostream>

using namespace std;

int cp[150][150];
int white, blue;
// �������� ���
// 1. �������� ����
// 2. �迭�� ��� ��ȸ�ϸ鼭 ���������� �޶����� �κ��� ������
//   2-1. ���̸� ������ ������
//   2-2. ������ 4���� ������
//   2-3. �� ������ ���� �� ������ ������ ���� �Ű������� �Ͽ� ����Ѵ�.
//   2-4. ��Ͱ� ������ �ٷ� �����Ѵ�
// 3. 2�� ������ �迭 ������ �������� �ʴ´ٸ�
// 4. �ϳ��� ���� �� �ִٴ� ���� �ǹ��ϹǷ� ���� ������ ������Ų��.
void quadTree(int x, int y, int length)
{
	int start = cp[x][y]; // 1
	// 2
	for (int i = x; i < x + length; i++)
	{
		for (int j = y; j < y + length; j++)
		{
			if (cp[i][j] != start)
			{
				quadTree(x, y, length / 2);
				quadTree(x, y + length / 2, length / 2);
				quadTree(x + length / 2, y, length / 2);
				quadTree(x + length / 2, y + length / 2, length / 2);
				return;
			}
		}
	}
	// 3, 4
	start ? blue++ : white++;
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> cp[i][j];
	}
	// 1. ������ ���� �ʱ�ȭ.
	white = blue = 0;
	quadTree(0, 0, n);
	cout << white << '\n' << blue << '\n';
}