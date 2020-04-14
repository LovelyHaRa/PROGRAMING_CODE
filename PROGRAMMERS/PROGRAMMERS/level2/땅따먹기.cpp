#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
	// dp �̿�
	// ��ȭ�� => land[i][j]=(i-1)!=j, max(land[i-1][j=0~3])+land[i][j]
	//            ���� ���� ��ġ�� ������ ���� �� �ִ밪�� ����
	// 1. 1�࿡�� �ִ밪 ���ϱ�
	for (int i = 0; i < land[0].size(); i++) {
		answer = answer < land[0][i] ? land[0][i] : answer;
	}
	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < 4; j++) {
			// 2. ��ȭ��
			int max = 0;
			for (int k = 0; k < 4; k++) {
				if (j == k) continue;
				max = max < land[i - 1][k] ? land[i - 1][k] : max;
			}
			land[i][j] += max;
			// 3. �ִ밪 ����
			answer = answer < land[i][j] ? land[i][j] : answer;
		}
	}
	// 4. �ִ밪 ����
	return answer;
}