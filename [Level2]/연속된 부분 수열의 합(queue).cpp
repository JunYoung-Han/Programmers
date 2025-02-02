#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

/*
	문제풀이

	queue에 숫자를 넣고,
	queue 안의 숫자 합 sum에 더한다.
	1. sum이 k 인 경우,
	ㄴ sum을 초기화하고, q.pop 해줌, 해당 idx 저장.
	ㄴ 해당 인덱스부터 다시 queue 저장 시작
	2. sum이 k 이상인 경우
	ㄴ queue의 합이 k보다 작거나 같아질 때 까지 pop 한다.
	ㄴ 작아진 경우는 다음 인덱스로 진행

	개선 사항
	- 근데 굳이 모든 정답 케이스를 vecIdx에 저장해서 sorting 해줄 필요 없고, 그때 그때 answer를 갱신해주면 된다.
	- for문 안에 구문도 좀 더 명확히 코드 개선 진행
	- 초기 answer 의 idx 값을 최대로 넣기 위해 answer[1]에 최대값 기입해줌

*/

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer(2);
	answer[1] = 1000000;

	queue<int> q;
	int sum = 0;
	int sIdx = 0;
	for (int i = 0; i < sequence.size(); i++)
	{
		q.push(sequence[i]);
		sum += sequence[i];

		if (sum > k)
		{
			while (sum > k)
			{
				sum -= q.front();
				q.pop();
				sIdx++;
			}
		}
		if (sum == k)
		{
			if (answer[1] - answer[0] > i - sIdx)
			{
				answer[0] = sIdx;
				answer[1] = i;
			}
			sum -= q.front();
			q.pop();
			sIdx++;
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution({ 1, 1, 1, 2, 3, 4, 5 }, 5);

	return 0;
}