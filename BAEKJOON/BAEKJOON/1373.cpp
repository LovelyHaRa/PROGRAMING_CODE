#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void)
{
	string s; // �Է� ������
	cin >> s;
	int k = 1; // �ڸ��� (1,2,4)
	vector<int> res; // 8���� �迭
	int t = 0; // ������ 8���� ����
	// 1. �������� Ž��
	for (int i = s.size() - 1; i >= 0; i--)
	{
		t += k * (s[i] - '0'); // 2. �ڸ����� ���� 8���� �����
		k *= 2; // 3. �ڸ��� *2
		// 4. 3�ڸ����� 8���� �迭�� ����
		if (k > 4)
		{
			res.push_back(t); // �迭�� ����
			// �ʱ�ȭ
			k = 1;
			t = 0;
		}
	}
	// 5. �����ִ� ������ �� ����
	if (k != 1)
		res.push_back(t);
	// 6. �迭 ���� ���
	for (auto it = res.rbegin(); it != res.rend(); it++)
		cout << *it;
}