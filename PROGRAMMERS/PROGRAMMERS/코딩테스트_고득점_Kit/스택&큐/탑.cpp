#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	vector<int> tmp; // ���� ž ����
	// ���� ó�� ������ Ž��
	for (int i = heights.size() - 1; i >= 0; i--)
	{
		int j;
		// i��ġ �ٷ� �غ��� Ž��
		for (j = i - 1; j >= 0; j--)
		{
			// ���� ���� i��ġ���� j��ġ�� �� ũ�ٸ�
			if (heights[i] < heights[j])
			{
				tmp.push_back(j + 1); // push
				break;
			}
		}
		// ž�� ���� ���ϸ� 0 push
		if (j < 0)
			tmp.push_back(j + 1);
	}
	// pop �ؼ� answer �迭�� push
	for (int i = tmp.size() - 1; i >= 0; i--)
		answer.push_back(tmp[i]);
	return answer;
}