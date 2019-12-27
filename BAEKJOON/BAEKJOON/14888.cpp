// ��Ʈ��ŷ ����

#include<iostream>
#include<vector>

using namespace std;

vector<int> a; // ���� ����
int oper[4]; // + - * /
int n;
int _max = -1987654321, _min = 1987654321;

// ���� �Լ�
int calc(int a, int b, int op)
{
	switch (op)
	{
	case 0:
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	default:
		return 0;
	}
}

void back(int idx, int mid)
{
	// ���� �ϼ��Ǿ��� ���
	if (idx == n - 1)
	{
		// �ִ밪�� �ּڰ� ���θ� Ȯ���Ѵ�
		_max = mid > _max ? mid : _max;
		_min = mid < _min ? mid : _min;
		return;
	}
	// ������ ������ 4���̴�
	for (int i = 0; i < 4; i++)
	{
		// �����ڰ� �����ϸ�
		if (oper[i])
		{
			int tmp = mid; // ��Ʈ��ŷ�� ���� �߰� ��갪 ����
			oper[i]--; // ������ ���� ����
			// �߰��� ���
			mid = !idx ? calc(a[idx], a[idx + 1], i) : calc(mid, a[idx + 1], i);
			back(idx + 1, mid); // ���� �ε����� �̵�
			// ��Ʈ��ŷ ó��
			oper[i]++;
			mid = tmp; 
		}
	}
}

int main(void)
{	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	back(0, 0);
	cout << _max << '\n' << _min << '\n';
}