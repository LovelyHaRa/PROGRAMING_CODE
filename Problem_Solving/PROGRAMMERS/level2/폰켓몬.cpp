#include <vector>
#include <map>

using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int solution(vector<int> nums)
{
	int answer = 0;
	map<int, int> m;
	// ������ ����
	for (int i = 0; i < nums.size(); i++) {
		m[nums[i]]++;
	}
	// ������ ��, ��ü ����/2 �� �ּڰ� ����
	return min(m.size(), nums.size() / 2);
}