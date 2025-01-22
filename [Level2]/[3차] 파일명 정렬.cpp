#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*
	문제풀이

	1. 먼저 Head와 number를 구별해는 함수
	2. head 부분으로 사전 순 정렬
	// ㄴ 이때 소문자로 체크, 동일한 경우, 입력순서로
	3. 이후 Number로 정렬
	// ㄴ 0023 같은 숫자와 12를 비교하는 함수 만들기

	실수 조심!!! 
	sort 할거면 sort 대상의 vector의 값으로 이루어진 compare 함수를 만들어야 한다.
	나는 sort는 인덱스만 저장된 벡터를 하고 compare 함수는 해당 인덱스를 참조하는 map에서 값을 가져와 비교하는 식으로 했다.
	이러면 안된다!!!

*/

struct Value
{
	string HEAD;
	int NUMBER;
	int index;
};

vector<Value> vec;

string GetHead(string str)
{
	string rtn;
	for (int i = 0; i < str.length(); i++)
	{
		// 숫자이면
		if (str[i] >= '0' && str[i] <= '9')
			break;
		rtn += str[i];
	}
	return rtn;
}


int TransToRealNumber(string num)
{
	int rtn = 0;
	string str;
	bool start = false;
	for (int i = 0; i < num.length(); i++)
	{
		if (start == false && num[i] != 0)
			start = true;
		if (start)
			str += num[i];
	}
	if (str.size() > 0)
		rtn = stoi(str);
	return rtn;
}

int GetNumber(string str)
{
	string valStr;
	bool start = false;
	for (int i = 0; i < str.length(); i++)
	{
		// 숫자이면
		if (start == false && str[i] >= '0' && str[i] <= '9')
			start = true;

		// 숫자가 아니면
		if (start && (str[i] < '0' || str[i] > '9') || valStr.size() >= 5)
			break;

		if (start)
			valStr += str[i];
	}

	int rtn = TransToRealNumber(valStr);
	return rtn;
}

string TransToLower(string str)
{
	transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
		{
			return std::tolower(c);
		});
	return str;
}

bool SortingFunc(Value a, Value b)
{
	string headA = TransToLower(a.HEAD);
	string headB = TransToLower(b.HEAD);
	if (headA != headB)
		return headA < headB;

	int numberA = a.NUMBER;
	int numberB = b.NUMBER;
	if (numberA != numberB)
		return numberA < numberB;

	return a.index < b.index;
}

vector<string> solution(vector<string> files) {

	vector<string> answer(files);

	// index 별 HEAD 와 NUMBER
	for (int i = 0; i < files.size(); i++)
	{
		Value val;
		val.HEAD = GetHead(files[i]);
		val.NUMBER = GetNumber(files[i]);
		val.index = i;
		vec.push_back(val);
	}

	// head로 정렬하고 head가 같을 경우 number 정렬 해야한다.
	sort(vec.begin(), vec.end(), SortingFunc);

	for (int i = 0; i < vec.size(); i++)
		answer[i] = files[vec[i].index];

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution({ "foo010bar020.zip", "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });
	solution({ "img2.png", "img02.png", "img1.png" });

	return 0;
}