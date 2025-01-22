#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <queue>

using namespace std;

/*
	문제풀이

	stack을 활용한다.

	order의 현재와 i가 같을때까지 i를 stack에 보관
	order와 일치하면 answer 증가
	order와 일치하지 않으면 i가 저장된 stack에서 꺼낼 수 있는지 체크
	ㄴ 꺼낼 수 있으면 stack에 꺼내고 answer 증가
	ㄴ 꺼낼 수 없으면 i를 stack에 넣기

	order와 가 일치했을 떄,
	다음 order와 stack.top을 비교.
	ㄴ 같지 않을 때 까지 or stack 비울때까지 반복
*/

int solution(vector<int> order) {
	int answer = 0;

	stack<int> stack;

	int curOrder = 0;
	for (int j = 1; j <= order.size(); j++)
	{
		if (order[curOrder] == j)
		{
			curOrder++;
			answer++;
		}
		else
		{
			if (stack.empty() == false && stack.top() == order[curOrder])
			{
				stack.pop();
				curOrder++;
				answer++;
			}
			else
			{
				stack.push(j);
			}
		}

		// 이후, top과 같은지 반복해서 체크해야한다.

		while (stack.empty() == false)
		{
			int topVal = stack.top();
			if (topVal == order[curOrder])
			{
				stack.pop();
				curOrder++;
				answer++;
			}
			else
				break;
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution({ 4, 3, 1, 2, 5 });
	solution({ 5, 4, 3, 2, 1 });
	// 1, 2, 3, 4 까지 stack에 넣음
	// 5일 때 드디어 일치하므로 넣음
	// 이후 order의 다음 순서(4) 와 stack의 값이 일치하므로 뺌
	// ㄴ or

	return 0;
}