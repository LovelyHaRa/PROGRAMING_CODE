// �ùķ��̼� ����
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
	int n, w, L;
	cin >> n >> w >> L;
	vector<int> truck(n);
	for (int i = 0; i < n; i++)
		cin >> truck[i];
	queue<int> q;
	int res, sum;
	res = sum = 0;
	// 1. ť�� ����� �� : ť�� Ʈ�� �߰�, ���� ����, �ð� �߰�
	// 2. ť�� ��á�� �� : ť���� Ʈ�� ����, ���� ����
	// 3. 1,2�� �ƴѰ��
	// 4. ���԰� �ʰ��� ��� : ť�� 0�� �߰�(���� �������), �ð� �߰�
	// 5. 4�� �ƴ� ��� : 1�� ���� �۾�
	for (int i = 0; i < truck.size(); i++)
	{
		while (1)
		{
			// 1
			if (q.empty())
			{
				q.push(truck[i]);
				sum += truck[i];
				res++;
				break;
			}
			// 2
			else if (q.size() == w)
			{
				sum -= q.front();
				q.pop();
			}
			// 3
			else
			{
				// 5
				if (sum + truck[i] <= L)
				{
					q.push(truck[i]);
					sum += truck[i];
					res++;
					break;
				}
				// 4
				else
				{
					q.push(0);
					res++;
				}
			}
		}
	}
	// �� �ð� : ���� �ð� + ������ Ʈ���� �ǳʴ� �ð�(�ٸ� ����)
	cout << res + w << '\n';
}