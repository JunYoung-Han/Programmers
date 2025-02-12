#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

/*
	���� Ǯ��

	DFS�� ��� ����� ���� �Ǵ��Ѵ�.

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
		// ���ι��� �Ǻ�: ������ col���̸� ���ΰ�ħ
		// �밢���� �Ǻ�: ���Ⱑ 1�̸� �밢
		if (col[j] == col[row] || abs(col[row] - col[j]) == (row - j))
			return false;
	}
	return true;
}

void DFS(int row)
{
	// i == 0, j == 0
	// �� j == 1 ����
	// ���� ħ���Ǹ� �ٷ� return
	// �ȵǸ� ���� i�� �Ѿ��

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
//    // ������ ���� ������ ħ������ �ʴ� ��ǥ ���
//    // N�� Ȧ�����, (0, 0)���� ����, x�� (0 + i), y�� (0 + (2*i) % n)
//    if (N % 2 == 1)
//    {
//        for (int i = 0; i < N; i++)
//            board[i] = (2 * i) % N;
//    }
//    // N�� ¦�� ���, 
//    else
//    {
//        // N % 6 == 0 �� Ȧ�� �� ¦�� ��ġ
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