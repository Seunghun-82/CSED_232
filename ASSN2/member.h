#pragma once
#include <iostream>

class member
{
private:
	int friends_num;						//친구가 몇명인지 저장한다.
	std::string ID;							//client의 ID를 저장한다.
	std::string name;						//client의 이름을 저장한다.
	std::string birthday;					//client의 생일 정보를 저장한다.
	std::string password;					//password를 저장한다.
	std::string friends[50];				//친구의 이름을 저장한다.

public:
	void add_friends(std::string tempt);
	void del_friends(std::string tempt);
	void my_friends();
	int check_friends(std::string tempt);
	int check_client(std::string tempt);
	void pass_log_info(std::string& present_ID, std::string& present_name, std::string& present_Birthday);
	void fill_info(std::string tempt_ID, std::string tempt_Name, std::string tempt_Birth, std::string tempt_password);
	int log_in(std::string tempt_ID, std::string tempt_password);
	std::string passing_friends_info(int index);
	void del_my_log();
	member();
};