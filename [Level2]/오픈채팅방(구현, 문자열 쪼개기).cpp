#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*
	문제풀이

	앞의 명령어에 따라 vec에다가 enter 또는 leave와 사용자 아이디를 저장한다.
	change가 들어오면 map<id, nickName> 에서 수정한다.
	최종적으로 vec 순회하면서 아이디 -> 닉네임으로 문장을 저장한다.

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
		result.push_back(str.substr(start, end - start)); // 현재 부분 문자열 저장
		start = end + 1; // 다음 시작 위치로 이동
	}

	result.push_back(str.substr(start)); // 마지막 부분 문자열 추가
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
			answer[i] = idToNick[vec[i].Id] + "님이 들어왔습니다.";
		else
			answer[i] = idToNick[vec[i].Id] + "님이 나갔습니다.";
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