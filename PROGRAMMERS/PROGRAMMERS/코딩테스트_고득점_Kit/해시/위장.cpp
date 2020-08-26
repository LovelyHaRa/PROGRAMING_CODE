#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> F;
	// 1. �ǻ��� ������ key�� �Ͽ� ī����
	for (int i = 0; i < clothes.size(); i++)
		F[clothes[i][1]]++;
	// 2. map Ž��
	for (auto i : F)
		// 3. �����Ǽ�+1�� ���ؼ� ����(������ ���� ���� �����Ƿ� +1)
		answer *= (i.second + 1);
	// 4. ��� �� ���� ���ϴ� ������ ���� ����
	return answer - 1;
}