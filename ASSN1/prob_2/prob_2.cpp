#include <iostream>

//나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
//I completed this programming task without the improper help of others.


int main()
{
	using namespace std;

	int student, l_student, a_student, number, count;			//student는 학생수를 나타내고, l_student는 잃어버린 학생 수, a_student는 추가적인 우산을 가지고 있는 학생 수
																// number의 경우에는 l_student 또는 a_student가 몇 번째 학생인지를 받아주기 위한 값, count는 최종 학생수를 출력해줄 변수이다.
	cin >> student >> l_student >> a_student;

	int* student_ary = new int[student];					

	for (int i = 0; i < student; i++)
	{
		student_ary[i] = 1;										// 학생들은 기본적으로 한 개의 리코더를 들고 있다.
	}

	for (int i = 0; i < l_student; i++)
	{
		cin >> number;
		student_ary[number - 1] = student_ary[number - 1] - 1;	// 두부가 리코더를 뺏어간 학번의 학생은 1개의 우산을 잃게 된다.
	}

	for (int i = 0; i < a_student; i++)
	{
		cin >> number;
		student_ary[number - 1] = student_ary[number - 1] + 1;	// additional 리코더를 들고 있는 학생은 1개를 추가해준다.
	}

	count = 0;

	for (int i = 0; i < student; i++)
	{
		if (i == 0)			// 맨 앞과 맨 뒤의 학생만 예외 처리를 해주면 되므로
		{
			if ((student_ary[i] == 2) && (student_ary[i + 1] == 0))	// 맨 앞의 학생은 뒤의 학생이 리코더가 0개이고, 내가 2개인 경우만 보면 된다.
			{
				student_ary[i + 1] = 1;
				student_ary[i] = 1;
			}
		}
		else if (i < student - 1)	//만약 내가 2개의 리코더를 가지고 있고, 앞의 학생이 리코더를 안가지고 있다면 기본적으로는 앞의 학생에게 하나를 준다.
		{
			if ((student_ary[i] == 2) && (student_ary[i - 1] == 0))
			{
				student_ary[i] = 1;
				student_ary[i - 1] = 1;
			}
			if ((student_ary[i] == 2) && (student_ary[i + 1] == 0))	//앞의 학생이 이미 리코더를 가지고 있고, 뒤의 학생이 리코더가 없다면 나는 뒤의 학생에게 하나를 준다.
			{
				student_ary[i] = 1;
				student_ary[i + 1] = 1;
			}
		}
		else
		{
			if ((student_ary[i] == 2) && (student_ary[i - 1] == 0))	// 맨 뒤 학생의 경우 앞의 학생이 리코더가 없고, 내가 2개를 가지고 있을 경우만 고려해주면 된다.
			{
				student_ary[i] = 1;
				student_ary[i - 1] = 1;
			}
		}
	}
	for (int i = 0; i < student; i++)
	{
		if ((student_ary[i] == 1) || (student_ary[i] == 2))			// 2개를 가지고 있거나, 1개를 가지고 있는 학생 수를 세면 총 리코더를 사용할 수 있는 경우이므로
			count++;
	}

	delete[] student_ary;											// 동적 할당을 해제해준다.

	cout << count;

	return 0;
}