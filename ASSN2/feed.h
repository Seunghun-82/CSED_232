#pragma once
#include <iostream>

class feed
{
private:
	int like_num;								//좋아요 개수를 저장한다.
	int comment_num;							//댓글의 개수를 저장한다.
	std::string post_people;					//포스팅한 사람의 ID를 저장한다.
	std::string post_info;						//포스팅한 내용을 저장한다.
	std::string post_comment[50];				//댓글을 저장한다.
	std::string post_comment_people[50];		//각 index에 맞게 댓글을 저장한 사람의 목록을 저장한다.
	std::string like_people[50];				//좋아요를 누른 사람의 이름을 저장한다.
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