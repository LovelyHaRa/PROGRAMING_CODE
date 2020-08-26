#include<iostream>
#include<cstring>

using namespace std;
void printDecimal(int a, int b); // �м��� �Ҽ��� ��ȯ�ϴ� �Լ�

int main(void)
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T; // �׽�Ʈ���̽�
	int a, b; // ����, �и�
	cin.sync_with_stdio(false);
	cin >> T;
	while (T > 0)
	{
		cin >> a >> b; // �Է� ����
		printDecimal(a, b); // �Լ� ȣ��
		T--;
	}

}

void printDecimal(int a, int b)
{
	int p[10240 + 1]; // key : ��������, value : �Ҽ��� ��ġ
	int nature = a / b; // �Ҽ��� ���κ�	
	int k = 0; // �Ҽ��� ���� ��ġ
	int start = 0, end = 0; // ��ȯ ����, �� ����
	int res = (a%b) * 10; // ��� �ʱⰪ
	memset(p, -1, sizeof(p)); // �迭 -1�� �ʱ�ȭ
	while (1)
	{
		a = (a%b) * 10; // �ڸ��� ���
		// ��ȯ���� �ľ�
		if (p[a] != -1)
		{
			start = p[a]; //�������� ����
			end = k; // ������ ����
			break; // �ݺ��� ����
		}
		p[a] = k++; //
	}
	cout << nature << '.'; // �Ҽ��� ���κ� ���
	// ��ȯ�Ǳ� �� �Ҽ��κ� ���
	for (int i = 0; i < start; i++)
	{
		cout << res / b;
		res = (res%b) * 10;
	}
	// ��ȯ�κ� ���
	cout << '(';
	for (int i = start; i < end; i++)
	{
		cout << res / b;
		res = (res%b) * 10;
	}
	cout << ')' << endl;
}