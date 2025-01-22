#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*
	����Ǯ��

	1. ���� Head�� number�� �����ش� �Լ�
	2. head �κ����� ���� �� ����
	// �� �̶� �ҹ��ڷ� üũ, ������ ���, �Է¼�����
	3. ���� Number�� ����
	// �� 0023 ���� ���ڿ� 12�� ���ϴ� �Լ� �����

	�Ǽ� ����!!! 
	sort �ҰŸ� sort ����� vector�� ������ �̷���� compare �Լ��� ������ �Ѵ�.
	���� sort�� �ε����� ����� ���͸� �ϰ� compare �Լ��� �ش� �ε����� �����ϴ� map���� ���� ������ ���ϴ� ������ �ߴ�.
	�̷��� �ȵȴ�!!!

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
		// �����̸�
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
		// �����̸�
		if (start == false && str[i] >= '0' && str[i] <= '9')
			start = true;

		// ���ڰ� �ƴϸ�
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

	// index �� HEAD �� NUMBER
	for (int i = 0; i < files.size(); i++)
	{
		Value val;
		val.HEAD = GetHead(files[i]);
		val.NUMBER = GetNumber(files[i]);
		val.index = i;
		vec.push_back(val);
	}

	// head�� �����ϰ� head�� ���� ��� number ���� �ؾ��Ѵ�.
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