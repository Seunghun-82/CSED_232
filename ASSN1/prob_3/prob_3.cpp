#include <iostream>
int max(int case1, int case2, int case3);

//���� �� ���α׷��� ������ �ٸ� ����� �������� ���� ���� �ϼ��Ͽ����ϴ�.
//I completed this programming task without the improper help of others.


int main()
{
	using namespace std;

	int n = 0;

	cin >> n;													// �޾ƿ� ����Ű�� �� ���� �޾ƿ�

	int* input = new int[n + 1];								// n+1���� array�� �Ҵ��ϴ� ������ input������ ����� ������ dynamic �� �ִ밪�� �����ϴ� array ������
	int* dynamic = new int[n + 1];								// ���� ���α׷��� ���ٺ��� �ƹ��͵� ���� ���� dynamic[0] �� ���̽��� �ʿ��ϱ� �����̴�.

	dynamic[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}

	dynamic[1] = input[1];										// ó�� ���� ���� �ִ�� ù��° ���� ���� ���̽��̴�.
	dynamic[2] = input[1] + input[2];							// �� ��° ��쿡�� �ִ밪�� �� �� �� ���� ����̴�.

	for (int i = 3; i <= n; i++)
	{
		dynamic[i] = max(dynamic[i - 1], dynamic[i - 2] + input[i], dynamic[i - 3] + input[i - 1] + input[i]);		// 3��° �ܺ��ʹ� ù �� ���� ���� ����� dynamic[2]
	}															// dynamic[1]�� input[3]�� ���� ���, �Ǵ� dynamic[0]�� input[2] input[3]�� ���� ����̱� ������ �� ����� ���� ū ����
																// ���� ���̽� �� ���� ū ���̶�� dynamic[3]�� �־��ָ� �ǰ�, �̰��� ��� �ݺ����ָ� ������ ���� ���� ������ �ȴ�.
	cout << dynamic[n];											// dynamic[n]�� �� �ִ� ���� ���� ū ���̽��� ���̹Ƿ� �� ���� ������ָ� �ȴ�.

	delete[] dynamic;											// �����Ҵ��� ��� �������ش�.
	delete[] input;

	return 0;
}

int max(int case1, int case2, int case3)						// case1,2,3�� ���� ū ���� ã���ִ� �Լ��̴�.
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