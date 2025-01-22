#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*
	����Ǯ��

	���� ��ɾ ���� vec���ٰ� enter �Ǵ� leave�� ����� ���̵� �����Ѵ�.
	change�� ������ map<id, nickName> ���� �����Ѵ�.
	���������� vec ��ȸ�ϸ鼭 ���̵� -> �г������� ������ �����Ѵ�.

*/

struct MsgVal
{
	bool IsEnter;
	string Id;

	MsgVal(bool isenter, string id)
	{
		IsEnter = isenter;
		Id = id;
	}
};

vector<string> SplitInfo(string str) {
	vector<string> result;
	int start = 0, end = 0;

	while ((end = str.find(' ', start)) != string::npos) {
		result.push_back(str.substr(start, end - start)); // ���� �κ� ���ڿ� ����
		start = end + 1; // ���� ���� ��ġ�� �̵�
	}

	result.push_back(str.substr(start)); // ������ �κ� ���ڿ� �߰�
	return result;
}

vector<string> solution(vector<string> record) {

	vector<MsgVal> vec;
	map<string, string> idToNick; // key: id, value: nickName
	for (int i = 0; i < record.size(); i++)
	{
		vector<string> infos = SplitInfo(record[i]);
		if (infos[0] == "Change")
		{
			idToNick[infos[1]] = infos[2];
		}
		else
		{
			if (infos[0] == "Enter")
			{
				idToNick[infos[1]] = infos[2];
				vec.push_back(MsgVal(true, infos[1]));
			}
			else if (infos[0] == "Leave")
			{
				vec.push_back(MsgVal(false, infos[1]));
			}
		}
	}

	vector<string> answer(vec.size());
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].IsEnter)
			answer[i] = idToNick[vec[i].Id] + "���� ���Խ��ϴ�.";
		else
			answer[i] = idToNick[vec[i].Id] + "���� �������ϴ�.";
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution({ "img2.png", "img02.png", "img1.png" });

	return 0;
}