#include <string>
#include <vector>
#include<iostream>
#include <cstring>
#include<map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;
	// 1. id <-> ����� �̸� ��Ī
	for (int i = 0; i < record.size(); i++) {
		// char* ����ȯ
		char t[30];
		strcpy(t, record[i].c_str());
		// ���ڿ� ��ū �и�
		char *token = strtok(t, " ");
		char cmd[3][20];
		int j = 0;
		while (token != NULL) {
			strcpy(cmd[j++], token);
			token = strtok(NULL, " ");
		}
		// key value ����
		if (!strcmp(cmd[0], "Enter") || !strcmp(cmd[0], "Change")) {
			m[cmd[1]] = cmd[2];
		}
	}
	// 2. message ���
	for (int i = 0; i < record.size(); i++) {
		// char* ����ȯ
		char t[30];
		strcpy(t, record[i].c_str());
		// ���ڿ� ��ū �и�
		char *token = strtok(t, " ");
		char cmd[3][20];
		int j = 0;
		while (token != NULL) {
			strcpy(cmd[j++], token);
			token = strtok(NULL, " ");
		}
		// Ŀ�ǵ忡 ���� �޽��� ����
		if (!strcmp(cmd[0], "Enter")) {
			string res(m[cmd[1]] + "���� ���Խ��ϴ�.");
			answer.push_back(res);
		}
		else if (!strcmp(cmd[0], "Leave")) {
			string res(m[cmd[1]] + "���� �������ϴ�.");
			answer.push_back(res);
		}
	}
	return answer;
}