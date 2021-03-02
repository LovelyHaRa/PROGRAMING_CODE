#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	// �ؽ�-�� �̿�
	unordered_map<string, int> res;
	// ������ ī����
	for (string p : participant)
		res[p]++;
	// ������ �� ������ ���� (-1 �� ����)
	for (string c : completion)
		res[c]--;
	for (auto r : res)
	{
		// ī���� �Ǿ��ִ� ������ �����ڰ�
		// ���ָ� ���� ������
		if (r.second)
		{
			answer = r.first;
			break;
		}

	}
	return answer;
}