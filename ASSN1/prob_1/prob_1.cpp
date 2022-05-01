#include <iostream>

// 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다. 
//I completed this programming task without the improper help of others.

int main ()
{
	using namespace std;

	int width, height, number = 0;													// width, height 가로 세로, number은 최대 공약수를 찾기 위한 변수이다.
	cout << "Width and Height" << endl;
	cin >> width >> height;
	if (width <= height)															// 두 수 중 작은 수를 기준으로 작은 수까지 나눠서 두 수 모두 나머지가 0인 값 중 가장 큰 수를
	{																				// number에 넣어주면 되기 때문에 계속 반복하면 최대 공약수가 나온다.
		for (int i = 1; i <= width; i++)
		{
			if ((width % i == 0) && (height % i == 0))
				number = i;
		}
	}
	else
	{
		for (int i = 1; i <= height; i++)
		{
			if ((width % i == 0) && (height % i == 0))
				number = i;
		}
	}

	cout << "The square is " << (width * height) - (width + height - number) << ".";	// 온전한 사각형의 개수는 전체 사각형에서 나눠진 사각형의 개수를 빼주면 되고, 나눠진 사각형은
																						// 가로 + 세로 - 최대 공약수 개 만큼 나오기 때문에 다음과 같은 결과를 출력해주면 된다.
	return 0;
}