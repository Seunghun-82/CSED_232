#include <iostream>

// ���� �� ���α׷��� ������ �ٸ� ����� �������� ���� ���� �ϼ��Ͽ����ϴ�. 
//I completed this programming task without the improper help of others.

int main ()
{
	using namespace std;

	int width, height, number = 0;													// width, height ���� ����, number�� �ִ� ������� ã�� ���� �����̴�.
	cout << "Width and Height" << endl;
	cin >> width >> height;
	if (width <= height)															// �� �� �� ���� ���� �������� ���� ������ ������ �� �� ��� �������� 0�� �� �� ���� ū ����
	{																				// number�� �־��ָ� �Ǳ� ������ ��� �ݺ��ϸ� �ִ� ������� ���´�.
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

	cout << "The square is " << (width * height) - (width + height - number) << ".";	// ������ �簢���� ������ ��ü �簢������ ������ �簢���� ������ ���ָ� �ǰ�, ������ �簢����
																						// ���� + ���� - �ִ� ����� �� ��ŭ ������ ������ ������ ���� ����� ������ָ� �ȴ�.
	return 0;
}