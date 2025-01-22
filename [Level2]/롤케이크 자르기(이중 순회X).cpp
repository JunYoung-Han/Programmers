#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
	int answer = 0;

	unordered_map<int, int> leftMap;
	unordered_map<int, int> rightMap;

	for (int i = 0; i < topping.size(); i++)
		rightMap[topping[i]]++;

	for (int i = 0; i < topping.size(); i++)
	{
		leftMap[topping[i]]++;
		rightMap[topping[i]]--;
		if (rightMap[topping[i]] == 0)
			rightMap.erase(topping[i]);

		if (leftMap.size() == rightMap.size())
			answer++;
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution({ 1, 2, 1, 3, 1, 4, 1, 2 });
	//solution({ 1, 2, 3, 1, 4 });

	return 0;
}