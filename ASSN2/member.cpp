#include "member.h"
#include <iostream>
member::member()
{
	friends_num = 0;					//멤버 초기화
}

void member::del_my_log()				//내 로그 정보를 없애준다. 즉 delete my account에서 활용된다.
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

void member::add_friends(std::string tempt)				// 친구 추가 기능이다. ID의 순서로 친구들을 친구목록에 저장한다.
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

void member::del_friends(std::string tempt)			//친구 목록에 있는 사람을 친구를 지워준다. 또한 지운 사람의 빈 공간을 모두 채워준다.
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

void member::my_friends()						// 내 친구들을 보여주는 함수이다.
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

int member::check_friends(std::string tempt)		//내 친구인지 확인하는 함수이다. 맞으면 0 아니면 1을 출력한다.
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

void member::pass_log_info(std::string& present_ID, std::string& present_name, std::string& present_Birthday)		// 멤버 함수의 private에 있는 정보를 passing 해준다.
{
	present_ID = ID;
	present_name = name;
	present_Birthday = birthday;
}

int member::check_client(std::string tempt)				// client에 등록이 되어있는지 확인해주고, 맞으면 1 아니면 0을 반환한다.
{
	if (ID == tempt)
		return 1;
	else
		return 0;

}

void member::fill_info(std::string tempt_ID, std::string tempt_Name, std::string tempt_Birth, std::string tempt_password)		// 최초 회원가입시 회원 정보를 저정하는 역할을 한다.
{
	ID = tempt_ID;
	name = tempt_Name;
	birthday = tempt_Birth;
	password = tempt_password;
}

int member::log_in(std::string tempt_ID, std::string tempt_password)			//log_in정보가 맞는지 확인을 한다. ID와 패스워드 모두 맞으면 1을 반환, 아이디는 있지만 password가 틀린경우 2를 반환한다.
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

std::string member::passing_friends_info(int index)				//친구들의 이름을 반환시켜주는 함수이다. 이는 친구의 포스트를 보기 위해서 필요한 함수이다.
{
	return friends[index];
}