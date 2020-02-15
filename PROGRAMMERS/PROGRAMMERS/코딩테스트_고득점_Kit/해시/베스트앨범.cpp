#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

// pair ���Լ� �ۼ���
template<template <typename> class P = less>
struct compare_pair_second {
	template<class T1, class T2> bool operator()(const pair<T1, T2>&left, const pair<T1, T2>&right) {
		// �� ���� ������ �ε����� ���� ������ ����
		if (left.second == right.second)
			return less<T1>()(left.first, right.first);
		return P<T2>()(left.second, right.second);
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	// 1. �帣�� ��ü ��� ���� map���� ����
	map<string, int> total_play;
	for (int i = 0; i < plays.size(); i++) {
		total_play[genres[i]] += plays[i];
	}
	// 2. �������� ���� (map�� ������ �ȵǱ� ������ vector �迭�� �ű� �� ����)
	vector<pair<string, int>> total(total_play.begin(), total_play.end());
	sort(total.begin(), total.end(), compare_pair_second<greater>());
	// 3. ���� �� Ž��
	for (int i = 0; i < total.size(); i++) {
		// 4. ���� �帣 �� ����
		vector<pair<int, int>> genre;
		for (int j = 0; j < plays.size(); j++) {
			if (genres[j] == total[i].first) {
				genre.push_back({ j, plays[j] });
			}
		}
		// 5. ���� �帣 ��� �� �������� ����
		sort(genre.begin(), genre.end(), compare_pair_second<greater>());
		// 6. �ִ� 2�� �̾Ƽ� �ε����� ����
		for (int j = 0; j < genre.size() && j < 2; j++) {
			answer.push_back(genre[j].first);
		}
	}
	return answer;

}