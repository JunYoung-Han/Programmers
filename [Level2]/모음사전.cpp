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

int answer = 0;
vector<char> vec = { 'A', 'E', 'I', 'O', 'U' };
bool isDone = false;
string stopStr;

void DFS(string w)
{
	if (stopStr == w)
		isDone = true;

	if (w.size() == 5 || isDone)
		return;

	for (int i = 0; i < vec.size(); i++)
	{
		if (isDone)
			return;
		answer++;
		DFS(w + vec[i]);
	}
}

int solution(string word) {

	stopStr = word;
	string str;
	DFS(str);

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution("EIO");

	return 0;
}