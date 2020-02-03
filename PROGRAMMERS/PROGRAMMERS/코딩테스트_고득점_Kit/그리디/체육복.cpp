#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	// 1. lost, reserve�� �Ѵ� ���Ե� ��� ����
	answer = n - lost.size(); // �ʱⰪ: ��ü-���»��
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (reserve[j] == lost[i])
			{
				answer++;
				//  -1�� �����ؼ� ���ܽ�Ŵ
				reserve[j] = -1;
				lost[i] = -1;
				break;
			}
		}
	}
	// 2. ���»�� ó������ ���������� ����Ž��
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			// ���� ��ġ�ϸ� 
			if (reserve[j] == lost[i] - 1 ||
				reserve[j] == lost[i] + 1)
			{
				answer++;
				// �޴»�� ���ܽ�Ŵ
				reserve[j] = -1;
				break;
			}
		}
	}
	return answer;
}