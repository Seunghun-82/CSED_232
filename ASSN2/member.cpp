#include "member.h"
#include <iostream>
member::member()
{
	friends_num = 0;					//��� �ʱ�ȭ
}

void member::del_my_log()				//�� �α� ������ �����ش�. �� delete my account���� Ȱ��ȴ�.
{
	ID = "";
	name = "";
	birthday = "";
	password = "";
	for (int i = 0; i < friends_num; i++)
	{
		friends[i] = "";
	}
	friends_num = 0;
}

void member::add_friends(std::string tempt)				// ģ�� �߰� ����̴�. ID�� ������ ģ������ ģ����Ͽ� �����Ѵ�.
{
	int index = 0;
	for (int i = 0; i < friends_num; i++)
	{
		if (friends[i] > tempt)
		{
			index = i;
			break;
		}
		if (i == friends_num - 1)
		{
			index = friends_num;
		}
	}
	for (int i = friends_num; i > index; i--)
	{
		friends[i] = friends[i - 1];
	}
	friends[index] = tempt;
	friends_num++;
}

void member::del_friends(std::string tempt)			//ģ�� ��Ͽ� �ִ� ����� ģ���� �����ش�. ���� ���� ����� �� ������ ��� ä���ش�.
{
	int del_number = 0;
	if (friends_num == 0)
	{
		return;
	}
	else
	{
		for (int i = 0; i < friends_num; i++)
		{
			if (friends[i] == tempt)
			{
				del_number = i;
				break;
			}
		}
		for (int i = del_number; i < friends_num - 1; i++)
		{
			friends[i] = friends[i + 1];
		}
		friends[friends_num - 1] = "";
		friends_num--;
	}
}

void member::my_friends()						// �� ģ������ �����ִ� �Լ��̴�.
{
	if (friends_num == 0)
	{
		std::cout << "You don't hav any friend.." << std::endl;
	}
	else
	{
		for (int i = 0; i < friends_num; i++)
		{
			std::cout << friends[i] << std::endl;
		}
	}
}

int member::check_friends(std::string tempt)		//�� ģ������ Ȯ���ϴ� �Լ��̴�. ������ 0 �ƴϸ� 1�� ����Ѵ�.
{
	for (int i = 0; i < friends_num; i++)
	{
		if (friends[i] == tempt)
		{
			return 0;
		}
	}

		return 1;
}

void member::pass_log_info(std::string& present_ID, std::string& present_name, std::string& present_Birthday)		// ��� �Լ��� private�� �ִ� ������ passing ���ش�.
{
	present_ID = ID;
	present_name = name;
	present_Birthday = birthday;
}

int member::check_client(std::string tempt)				// client�� ����� �Ǿ��ִ��� Ȯ�����ְ�, ������ 1 �ƴϸ� 0�� ��ȯ�Ѵ�.
{
	if (ID == tempt)
		return 1;
	else
		return 0;

}

void member::fill_info(std::string tempt_ID, std::string tempt_Name, std::string tempt_Birth, std::string tempt_password)		// ���� ȸ�����Խ� ȸ�� ������ �����ϴ� ������ �Ѵ�.
{
	ID = tempt_ID;
	name = tempt_Name;
	birthday = tempt_Birth;
	password = tempt_password;
}

int member::log_in(std::string tempt_ID, std::string tempt_password)			//log_in������ �´��� Ȯ���� �Ѵ�. ID�� �н����� ��� ������ 1�� ��ȯ, ���̵�� ������ password�� Ʋ����� 2�� ��ȯ�Ѵ�.
{
	if (ID == tempt_ID && password == tempt_password)
	{
		return 1;
	}
	else if (ID == tempt_ID && password != tempt_password)
	{
		return 2;
	}
}

std::string member::passing_friends_info(int index)				//ģ������ �̸��� ��ȯ�����ִ� �Լ��̴�. �̴� ģ���� ����Ʈ�� ���� ���ؼ� �ʿ��� �Լ��̴�.
{
	return friends[index];
}