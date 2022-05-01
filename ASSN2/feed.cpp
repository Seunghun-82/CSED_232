#include "feed.h"

int feed::my_posting(std::string ID)			//나의 포스트인지 확인 하는 함수
{
	if (post_people == ID)
		return 1;
}

int feed::check_friends(std::string ID)			//친구의 포스트인지 확인 하는 함수
{
	if (post_people == ID)
		return 1;
}

void feed::posting(std::string post, std::string ID)		//포스트를 추가해주는 함수
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

void feed::check_like(std::string ID)						//좋아요를 누른 사람인지 판별하고, 좋아요를 눌렀는 경우에는 이미 눌렀다는신호와 안누른 경우 누른 경우로만들어준다.
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

int feed::check_like_it(std::string ID)						//좋아요를 누른 사람인지 판별해주는 함수이다.
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

void feed::show()											//포스트를 show 해준다.
{
	std::cout << "@" << post_people << " (Like: " << like_num << ")" << std::endl;
	std::cout << " - " << post_info << std::endl;
}

void feed::comment_show()									//포스트에해당하는 comment들을 show 해준다.
{
	for (int i = 0; i < comment_num; i++)
	{
		std::cout << "@" << post_comment_people[i] << " - " << post_comment[i] << std::endl;
	}
}

void feed::post_commenting(std::string ID, std::string comment)		//post의 댓글을 달 수 있게 해주는 함수이다.
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

void feed::deleting_like(std::string ID)							//좋아요를 없애준다. delete my account에서 필요하다.
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

void feed::deleting_comment(std::string ID)							//comment를 없애준다. 이 역시 delete my account에서 필요하다.
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

void feed::deleting_my_post()										//post를 지워준다. 이 역시 delete my account에서 필요하다.
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

feed::feed()														//feed를 초기화해준다.
{
	like_num = 0;
	comment_num = 0;
}