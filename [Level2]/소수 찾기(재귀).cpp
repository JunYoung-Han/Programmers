#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>

using namespace std;

/*
	문제풀이


*/

bool isPrime(int num)
{
	if (num <= 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

string oriStr;
int answer = 0;
map<int, bool> visited;
void CheckString(string str)
{
	int val = stoi(str);
	if (str.length() > oriStr.length() || visited[val])
		return;

	if (isPrime(val))
	{
		visited[val] = true;
		answer++;
	}

	// 현재 숫자 제외하고 하나씩 붙여서 dfs 하기
	string tempStr = oriStr;
	for (int i = 0; i < str.length(); i++)
	{
		int pos = tempStr.find(str[i]);
		if (pos != string::npos)
			tempStr.erase(pos, 1);
	}

	for (int i = 0; i < tempStr.length(); i++)
	{
		string newStr = str + tempStr[i];
		CheckString(newStr);
	}
}

int solution(string numbers) {

	oriStr = numbers;
	for (int i = 0; i < numbers.length(); i++)
	{
		if (numbers[i] == '0')
			continue;

		string str;
		str += numbers[i];
		CheckString(str);
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution("011");

	return 0;
}