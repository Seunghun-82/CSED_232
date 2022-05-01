#include <iostream>
int max(int case1, int case2, int case3);

//나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
//I completed this programming task without the improper help of others.


int main()
{
	using namespace std;

	int n = 0;

	cin >> n;													// 받아올 위스키의 잔 수를 받아옴

	int* input = new int[n + 1];								// n+1개의 array를 할당하는 이유는 input에서는 상관이 없지만 dynamic 즉 최대값을 저장하는 array 에서는
	int* dynamic = new int[n + 1];								// 밑의 프로그램을 보다보면 아무것도 먹지 않은 dynamic[0] 의 케이스가 필요하기 때문이다.

	dynamic[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}

	dynamic[1] = input[1];										// 처음 먹은 잔의 최대는 첫번째 잔을 먹은 케이스이다.
	dynamic[2] = input[1] + input[2];							// 두 번째 경우에는 최대값은 두 잔 다 먹은 경우이다.

	for (int i = 3; i <= n; i++)
	{
		dynamic[i] = max(dynamic[i - 1], dynamic[i - 2] + input[i], dynamic[i - 3] + input[i - 1] + input[i]);		// 3번째 잔부터는 첫 두 잔을 먹은 경우인 dynamic[2]
	}															// dynamic[1]과 input[3]을 먹은 경우, 또는 dynamic[0]과 input[2] input[3]을 먹은 경우이기 때문에 이 경우의 가장 큰 값을
																// 먹은 케이스 중 가장 큰 값이라고 dynamic[3]을 넣어주면 되고, 이것을 계속 반복해주면 다음과 같은 식이 나오게 된다.
	cout << dynamic[n];											// dynamic[n]에 들어가 있는 값이 가장 큰 케이스의 값이므로 이 값을 출력해주면 된다.

	delete[] dynamic;											// 동적할당을 모두 해제해준다.
	delete[] input;

	return 0;
}

int max(int case1, int case2, int case3)						// case1,2,3의 가장 큰 값을 찾아주는 함수이다.
{
	int max = case1;

	if (max < case2)
	{
		max = case2;
	}
	if (max < case3)
	{
		max = case3;
	}
	
	return max;
}