#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 2022 KAKAO BLIND RECRUITMENT
/*
	문제풀이
	이중포문 안됨

	Stack을 활용한다.
	값의 인덱스를 스택에 넣고, 현재 값을 스택에 들어가 있는 인덱스 원소 값과 비교한다.

*/

vector<int> solution(vector<int> numbers) {
	vector<int> answer(numbers.size(), -1);
	stack<int> stack; // 바뀌지 않은 idx 저장
	for (int i = 0; i < numbers.size(); i++)
	{
		while (stack.empty() == false)
		{
			if (numbers[stack.top()] >= numbers[i])
				break;
			else
			{
				answer[stack.top()] = numbers[i];
				stack.pop();
			}

		}
		stack.push(i);
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution({ 9, 1, 5, 3, 6, 2 });
	solution({ 2, 3, 3, 5 });

	return 0;
}