#pragma once
#include <iostream>

class feed
{
private:
	int like_num;								//���ƿ� ������ �����Ѵ�.
	int comment_num;							//����� ������ �����Ѵ�.
	std::string post_people;					//�������� ����� ID�� �����Ѵ�.
	std::string post_info;						//�������� ������ �����Ѵ�.
	std::string post_comment[50];				//����� �����Ѵ�.
	std::string post_comment_people[50];		//�� index�� �°� ����� ������ ����� ����� �����Ѵ�.
	std::string like_people[50];				//���ƿ並 ���� ����� �̸��� �����Ѵ�.
public:
	int my_posting(std::string ID);
	int check_friends(std::string ID);
	void posting(std::string post, std::string ID);
	void show();
	void check_like(std::string ID);
	void post_commenting(std::string ID, std::string comment);
	void comment_show();
	void deleting_comment(std::string ID);
	void deleting_like(std::string ID);
	int check_like_it(std::string ID);
	void deleting_my_post();
	feed();
};