#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

/*
	문제 풀이

	DFS로 모든 경우의 수를 판단한다.

*/

using namespace std;

int answer = 0;
int N;
vector<int> col;
vector<int> board;

bool isOk(int row)
{
	for (int j = 0; j < row; j++)
	{
		// 세로방향 판별: 동일한 col값이면 세로겹침
		// 대각방향 판별: 기울기가 1이면 대각
		if (col[j] == col[row] || abs(col[row] - col[j]) == (row - j))
			return false;
	}
	return true;
}

void DFS(int row)
{
	// i == 0, j == 0
	// ㄴ j == 1 부터
	// 영역 침범되면 바로 return
	// 안되면 다음 i로 넘어가기

	if (row == N)
	{
		answer++;
		if (col == board)
			cout << N << ": same" << endl;
		return;
	}

	for (int idx = 0; idx < N; idx++)
	{
		col[row] = idx;
		if (isOk(row))
			DFS(row + 1);
	}
}
//
//void chess_puzzle(int N) {
//    // 퀸들이 서로 영역을 침범하지 않는 좌표 출력
//    // N이 홀수라면, (0, 0)부터 시작, x는 (0 + i), y는 (0 + (2*i) % n)
//    if (N % 2 == 1)
//    {
//        for (int i = 0; i < N; i++)
//            board[i] = (2 * i) % N;
//    }
//    // N이 짝수 라면, 
//    else
//    {
//        // N % 6 == 0 → 홀수 → 짝수 배치
//        int k = 1;
//        for (int i = 0; i < N / 2; i++)
//        {
//            board[i] = k;
//            k += 2;
//        }
//        if (N % 6 == 0 || N % 6 == 4)
//        {
//            k = 0;
//            for (int i = N / 2; i < N; i++)
//            {
//                board[i] = k;
//                k += 2;
//            }
//        }
//        else if (N % 6 == 2)
//        {
//            k = 2;
//            for (int i = N / 2; i < N; i++) {
//                board[i] = k;
//                k += 2;
//            }
//            swap(board[N / 2 + 1], board[N - 1]);
//            board[N / 2 + 1] = 0;
//        }
//    }
//}

int solution(int n) {
	N = n;
	col.resize(n);
	//board.resize(n);

	//chess_puzzle(n);
	DFS(0);
	return answer;
}

int main() {
	int N;
	for (int i = 3; i < 20; i++)
		solution(i);

	return 0;
}