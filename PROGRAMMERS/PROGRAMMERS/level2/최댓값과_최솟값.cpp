#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer = "";
	// stringstream ���
	stringstream st;
	st.str(s); // ���ڿ� ����
	int min = 1987654321, max = -1987654321, k;
	// ������ �����ϰ� st�� ���� k�� �ڷ���(int)�� �ƴ� �� ���� �ݺ�
	while (st >> k) {
		// k�� st�� �κ� ���ڿ��� ����ȯ �� ����
		// �ּڰ�, �ִ밪�� �Ǻ�
		min = min > k ? k : min;
		max = max < k ? k : max;
	}
	answer += to_string(min) + ' ' + to_string(max);
	return answer;
}