#include <iostream>

//���� �� ���α׷��� ������ �ٸ� ����� �������� ���� ���� �ϼ��Ͽ����ϴ�.
//I completed this programming task without the improper help of others.


int main()
{
	using namespace std;

	int student, l_student, a_student, number, count;			//student�� �л����� ��Ÿ����, l_student�� �Ҿ���� �л� ��, a_student�� �߰����� ����� ������ �ִ� �л� ��
																// number�� ��쿡�� l_student �Ǵ� a_student�� �� ��° �л������� �޾��ֱ� ���� ��, count�� ���� �л����� ������� �����̴�.
	cin >> student >> l_student >> a_student;

	int* student_ary = new int[student];					

	for (int i = 0; i < student; i++)
	{
		student_ary[i] = 1;										// �л����� �⺻������ �� ���� ���ڴ��� ��� �ִ�.
	}

	for (int i = 0; i < l_student; i++)
	{
		cin >> number;
		student_ary[number - 1] = student_ary[number - 1] - 1;	// �κΰ� ���ڴ��� ��� �й��� �л��� 1���� ����� �Ұ� �ȴ�.
	}

	for (int i = 0; i < a_student; i++)
	{
		cin >> number;
		student_ary[number - 1] = student_ary[number - 1] + 1;	// additional ���ڴ��� ��� �ִ� �л��� 1���� �߰����ش�.
	}

	count = 0;

	for (int i = 0; i < student; i++)
	{
		if (i == 0)			// �� �հ� �� ���� �л��� ���� ó���� ���ָ� �ǹǷ�
		{
			if ((student_ary[i] == 2) && (student_ary[i + 1] == 0))	// �� ���� �л��� ���� �л��� ���ڴ��� 0���̰�, ���� 2���� ��츸 ���� �ȴ�.
			{
				student_ary[i + 1] = 1;
				student_ary[i] = 1;
			}
		}
		else if (i < student - 1)	//���� ���� 2���� ���ڴ��� ������ �ְ�, ���� �л��� ���ڴ��� �Ȱ����� �ִٸ� �⺻�����δ� ���� �л����� �ϳ��� �ش�.
		{
			if ((student_ary[i] == 2) && (student_ary[i - 1] == 0))
			{
				student_ary[i] = 1;
				student_ary[i - 1] = 1;
			}
			if ((student_ary[i] == 2) && (student_ary[i + 1] == 0))	//���� �л��� �̹� ���ڴ��� ������ �ְ�, ���� �л��� ���ڴ��� ���ٸ� ���� ���� �л����� �ϳ��� �ش�.
			{
				student_ary[i] = 1;
				student_ary[i + 1] = 1;
			}
		}
		else
		{
			if ((student_ary[i] == 2) && (student_ary[i - 1] == 0))	// �� �� �л��� ��� ���� �л��� ���ڴ��� ����, ���� 2���� ������ ���� ��츸 ������ָ� �ȴ�.
			{
				student_ary[i] = 1;
				student_ary[i - 1] = 1;
			}
		}
	}
	for (int i = 0; i < student; i++)
	{
		if ((student_ary[i] == 1) || (student_ary[i] == 2))			// 2���� ������ �ְų�, 1���� ������ �ִ� �л� ���� ���� �� ���ڴ��� ����� �� �ִ� ����̹Ƿ�
			count++;
	}

	delete[] student_ary;											// ���� �Ҵ��� �������ش�.

	cout << count;

	return 0;
}