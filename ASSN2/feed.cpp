#include "feed.h"

int feed::my_posting(std::string ID)			//���� ����Ʈ���� Ȯ�� �ϴ� �Լ�
{
	if (post_people == ID)
		return 1;
}

int feed::check_friends(std::string ID)			//ģ���� ����Ʈ���� Ȯ�� �ϴ� �Լ�
{
	if (post_people == ID)
		return 1;
}

void feed::posting(std::string post, std::string ID)		//����Ʈ�� �߰����ִ� �Լ�
{
	post_info = post;
	post_people = ID;
	like_num = 0;
	comment_num = 0;
	for (int i = 0; i < 50; i++)
	{
		post_comment[i] = "";
		post_comment_people[i] = "";
		like_people[i] = "";
	}
}

void feed::check_like(std::string ID)						//���ƿ並 ���� ������� �Ǻ��ϰ�, ���ƿ並 ������ ��쿡�� �̹� �����ٴ½�ȣ�� �ȴ��� ��� ���� ���θ�����ش�.
{
	for (int i = 0; i < like_num; i++)
	{
		if (like_people[i] == ID)
		{
			std::cout << "You already like it" << std::endl;
			return;
		}
	}
	like_people[like_num] = ID;
	like_num++;
}

int feed::check_like_it(std::string ID)						//���ƿ並 ���� ������� �Ǻ����ִ� �Լ��̴�.
{
	for (int i = 0; i < like_num; i++)
	{
		if (like_people[i] == ID)
		{
			return 1;
		}
	}
	return 0;
}

void feed::show()											//����Ʈ�� show ���ش�.
{
	std::cout << "@" << post_people << " (Like: " << like_num << ")" << std::endl;
	std::cout << " - " << post_info << std::endl;
}

void feed::comment_show()									//����Ʈ���ش��ϴ� comment���� show ���ش�.
{
	for (int i = 0; i < comment_num; i++)
	{
		std::cout << "@" << post_comment_people[i] << " - " << post_comment[i] << std::endl;
	}
}

void feed::post_commenting(std::string ID, std::string comment)		//post�� ����� �� �� �ְ� ���ִ� �Լ��̴�.
{
	if (comment == "")
	{
		return;
	}
	else
	{
		for (int i = comment_num; i > 0; i--)
		{
			post_comment[i] = post_comment[i - 1];
			post_comment_people[i] = post_comment_people[i - 1];
		}
		post_comment[0] = comment;
		post_comment_people[0] = ID;
		comment_num++;
	}
}

void feed::deleting_like(std::string ID)							//���ƿ並 �����ش�. delete my account���� �ʿ��ϴ�.
{
	if (like_num == 0)
	{
		return;
	}
	else
	{
		for (int i = 0; i < like_num; i++)
		{
			if (like_people[i] == ID)
			{
				for (int j = i; j < like_num; j++)
				{
					like_people[j] = like_people[j + 1];
				}
				like_num--;
				like_people[like_num] = "";
				return;
			}
		}
	}
}

void feed::deleting_comment(std::string ID)							//comment�� �����ش�. �� ���� delete my account���� �ʿ��ϴ�.
{
	for (int i = 0; i < comment_num; i++)
	{
		if (post_comment_people[i] == ID)
		{
			for (int j = i; j < comment_num - 1; j++)
			{
				post_comment_people[j] = post_comment_people[j + 1];
				post_comment[j] = post_comment[j + 1];
			}
			comment_num--;
			post_comment_people[comment_num] = "";
			post_comment[comment_num] = "";
			i--;
		}
	}
}

void feed::deleting_my_post()										//post�� �����ش�. �� ���� delete my account���� �ʿ��ϴ�.
{
	std::string post_people = "";
	std::string post_info = "";
	for (int i = 0; i < like_num; i++)
	{
		like_people[i] = "";
	}
	for (int i = 0; i < comment_num; i++)
	{
		post_comment[i];
		post_comment_people[i];
	}

	like_num = 0;
	comment_num = 0;
}

feed::feed()														//feed�� �ʱ�ȭ���ش�.
{
	like_num = 0;
	comment_num = 0;
}