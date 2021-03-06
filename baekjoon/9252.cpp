
#include<iostream>
#include<algorithm>

using namespace std;

char s1[1002], s2[1002], lcs[1001]; // 문자열
int dp[1001][1001], i, j; // 메모제이션 배열, 반복문 변수

int main(void)
{
	cin >> s1 + 1 >> s2 + 1; // 인덱스를 1부터 시작
	/* LCS 문제
	  - 2차원 메모제이션 배열 생성
	  - 좌상단부터 좌측으로 비교 문자가 같으면 좌대각위의 값 +1 저장
	  - 같지 않으면 좌측,상단값중 최대값 저장
	  - 마지막 값이 LCS 길이의 값
	  - 문자를 구하기 위해서는 백트래킹 해야한다
	*/
	for (i = 1; s2[i]; i++)
	{
		for (j = 1; s1[j]; j++)
		{
			if (s2[i] == s1[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int len = dp[i - 1][j - 1];
	lcs[len] = '\0';
	cout << len << endl;
	i--;
	j--;
	/*
	  문자열 추출방법
	  테이블의 가로를 s1, 세로를 s2라고 했을 때
	  dp[i][j]==dp[i][j-1] 이면 테이블의 좌측 값이 온 것이므로 왼쪽으로 옮긴다
	  dp[i][j]==dp[i-1][j] 이면 테이블의 상단 값이 온 것이므로 위쪽으로 옮긴다
	  위 두 경우가 아닌 경우에는 대각선에서 온 것이고 이는 문자가 일치한다는 의미이므로
	  테이블의 가로 기준인 s1[j] 값을 저장 한 뒤 대각선으로 옮기면 된다.
	  저장한 문자열을 역으로 출력하면 된다.
	*/
	while (len)
	{
		// 왼쪽과 일치하는 경우
		if (dp[i][j] == dp[i][j - 1])
			j--;
		// 상단과 일치하는 경우
		else if (dp[i][j] == dp[i - 1][j])
			i--;
		// 대각선과 일치하는 경우
		else
		{
			lcs[--len] = s1[j]; // 현재 위치 문자 저장
			i--;
			j--;
		}
	}
	cout << lcs << endl;
}
