#include <iostream>
#include<vector>
using namespace std;

int min(int a, int b, int c) {
	return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int solution(vector<vector<int>> board)
{
	int answer = board[0][0];
	// dp�� �ذ�
	// 1. ��ȭ�� => board[i][j]>0, i>0,j>0, board[i][j]=min(board[i-1][j-1],board[i-1][j],board[i][j-1])+1
	//              �»��, ����, ���� ���� �ּڰ��� 1�� ���� ����
	//              board[i][j] = ���� �� �ִ� ���簢���� �Ѻ��� ����
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			// 1. ��ȭ�� ����
			if (i && j) {
				board[i][j] = board[i][j] > 0 ? min(board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]) + 1 : 0;
			}
			// 2. �ִ� ����
			answer = answer < board[i][j] ? board[i][j] : answer;
		}
	}
	// 3. ���� ����
	return answer * answer;
}