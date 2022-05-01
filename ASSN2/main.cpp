#include "feed.h"
#include "member.h"
#include <fstream>
#include <cstdio>
#include <iostream>
#include <string>

int main()
{
	int menu_1, menu_2, menu_3, menu_4; //menu_1, 2, 3, 4는 각각 Menu 표시가 나오는 창들의 값을 받아들이기 위한 변수입니다.
	int open = 0;						//open은 Load command를 진행한 경우 파일 입출력에서 stdin , out으로 변경을 위한 변수입니다.
	int print_open = 1;					//stdin을 한 것을 파일 출력을 해주기 위한 변수입니다.
	int client_num = 0;					//총 고객의 수를 나타내는 변수입니다.
	int post_num = 0;					//총 post의 개수를 나타내는 변수입니다.
	int present_level = 0;				//첫 번째 메뉴 시도에서 load command를 하지 않는 경우 print_file에 띄워쓰기를 한 번 해줘야하기 때문에 생겨난 변수입니다. menu_1이 몇 번째 실행이 되었는지를 판단해주는 변수입니다.
	std::string ID, Name, Birthday, Password;			//ID, Name, Birthday, Password를 받아오는 변수입니다.
	std::ifstream file;									//load command를 위한 변수
	std::fstream print_file;							//file 출력을 해주는 변수

	std::streambuf* stream_buffer_cin = std::cin.rdbuf();		// 이걸 불러주면 standard in으로 바꿔주는 변수
	std::streambuf* stream_buffer_file = file.rdbuf();			// 이걸 불러주면 file 입력으로 바꿔주는 변수
	print_file.open("command.txt", std::ios::app);
	member client[50];
	feed post[100];
	while (1)
	{
		std::cout << "=======================" << std::endl;			//Main 메뉴 입니다.
		std::cout << "Menu - Main" << std::endl;
		std::cout << "1. Sign up" << std::endl;
		std::cout << "2. Sign in" << std::endl;
		std::cout << "3. Load command" << std::endl;
		std::cout << "4. Program exit" << std::endl;
		std::cout << "=======================" << std::endl;
		std::cout << "Select Menu: ";
		menu_1 = 0;
		if (open == 1)													//open이 1일 경우 load command가 진행중인 상황입니다.
		{
			if (std::cin.eof())											//cin.eof일 경우 standard in으로 바꿔주며, 입력된 값을 출력하게 해줍니다.
			{
				file.close();
				open = 0;
				std::cin.rdbuf(stream_buffer_cin);
				print_file.open("command.txt", std::ios::app);
				print_file << std::endl;
				print_open = 1;
			}
		}
		std::cin >> menu_1;												
		std::cin.clear();												//버퍼를 비워주기 위해서 사용했습니다.
		std::cin.ignore(100, '\n');
		if (print_open == 1)
		{
			if (present_level == 0 && menu_1 != 3)
			{
				print_file << std::endl;
			}

			if (menu_1 == 4)
			{
				print_file << menu_1;									//케이스를 나눠둔 이유는 맨 마지막줄에는 띄워쓰기를 하면 안되기 때문입니다.
			}
			else if (menu_1 == 3)
			{

			}
			else 
			{
				print_file << menu_1 << std::endl;						
			}
		}
		std::cout << "=======================" << std::endl;
		present_level++;
		if (menu_1 == 1)									//회원 가입
		{
			int error = 0;									//error 변수는 같은 ID를 사용하는 사람이 있는 경우 회원가입을 시키지 않기 위해서
															//사용되는 변수입니다.
			if (open == 1)									//이하 open, print_open에 대한 case는 모두 위와 같은 이유입니다.
			{
				if (std::cin.eof())
				{
					file.close();
					open = 0;
					std::cin.rdbuf(stream_buffer_cin);
					print_file.open("command.txt", std::ios::app);
					print_file << std::endl;
					print_open = 1;
				}
			}
			std::cout << "ID: ";
			std::getline(std::cin, ID);
			if (print_open == 1)
			{
				print_file << ID << std::endl;
			}
			if (open == 1)
			{
				if (std::cin.eof())
				{
					file.close();
					open = 0;
					std::cin.rdbuf(stream_buffer_cin);
					print_file.open("command.txt", std::ios::app);
					print_file << std::endl;
					print_open = 1;
				}
			}
			std::cout << "Name: ";
			std::getline(std::cin, Name);
			if (print_open == 1)
			{
				print_file << Name << std::endl;
			}
			if (open == 1)
			{
				if (std::cin.eof())
				{
					file.close();
					open = 0;
					std::cin.rdbuf(stream_buffer_cin);
					print_file.open("command.txt", std::ios::app);
					print_file << std::endl;
					print_open = 1;
				}
			}
			std::cout << "Birthday: ";
			std::getline(std::cin, Birthday);
			if (print_open == 1)
			{
				print_file << Birthday << std::endl;
			}
			if (open == 1)
			{
				if (std::cin.eof())
				{
					file.close();
					open = 0;
					std::cin.rdbuf(stream_buffer_cin);
					print_file.open("command.txt", std::ios::app);
					print_file << std::endl;
					print_open = 1;
				}
			}
			std::cout << "Password: ";
			std::getline(std::cin, Password);
			if (print_open == 1)
			{
				print_file << Password << std::endl;
			}
			if (ID == "")
			{
				"It's not valid ID";
			}
			else
			{
				for (int i = 0; i < client_num; i++)
				{
					error = (client[i].check_client(ID));
					if (error == 1)
					{
						break;
					}
				}
				if (error)
				{
					std::cout << "There is already member who has that ID" << std::endl;
				}
				else
				{
					client[client_num].fill_info(ID, Name, Birthday, Password);
					client_num++;
					std::cout << "Register Done!" << std::endl;
				}
			}
		}
		else if (menu_1 == 2)				//로그인 화면
		{
			int valid = -1;					//valid가 있는 이유는 그 회원이 몇 번째 회원인지 알기 위해서 필요한 변수입니다.
											//후에 나오는 모든 client에 대한 접근을 하기 위해서 필요한 변수입니다.
			std::cout << "ID: ";
			if (open == 1)
			{
				if (std::cin.eof())
				{
					file.close();
					open = 0;
					std::cin.rdbuf(stream_buffer_cin);
					print_file.open("command.txt", std::ios::app);
					print_file << std::endl;
					print_open = 1;
				}
			}
			std::getline(std::cin, ID);

			if (print_open == 1)
			{
				print_file << ID << std::endl;
			}

			std::cout << "Password: ";
			if (open == 1)
			{
				if (std::cin.eof())
				{
					file.close();
					open = 0;
					std::cin.rdbuf(stream_buffer_cin);
					print_file.open("command.txt", std::ios::app);
					print_file << std::endl;
					print_open = 1;
				}
			}
			std::getline(std::cin, Password);
			if (print_open == 1)
			{
				print_file << Password << std::endl;
			}
			std::cout << "=======================" << std::endl;
			for (int i = 0; i < client_num; i++)
			{
				if (client[i].check_client(ID))
				{
					valid = i;					//같은 아이디의 user가 있는지 조사합니다.
					break;
				}
				else
				{
					valid = -1;					//아닐 시 오류를 출력합니다.
				}
			}
			if (valid == -1)
			{
				std::cout << "Unregistered account!" << std::endl;
			}
			else
			{
				if (client[valid].log_in(ID, Password) == 1)		//여기서 비밀번호와 아이디가 일치하는지 확인합니다.
				{
					client[valid].pass_log_info(ID, Name, Birthday); //유저의 정보를 ID, Name, Birthday에 저장합니다.
					while (1)										//여기서부터 my page
					{
						std::cout << "Menu - My page" << std::endl;
						std::cout << "@" << ID << " - " << Name << " " << Birthday << std::endl;
						std::cout << "1. Friends" << std::endl;
						std::cout << "2. Feed" << std::endl;
						std::cout << "3. Sign out" << std::endl;
						std::cout << "4. Delete my account" << std::endl;
						std::cout << "=======================" << std::endl;
						std::cout << "Select Menu: ";
						if (open == 1)
						{
							if (std::cin.eof())
							{
								file.close();
								open = 0;
								std::cin.rdbuf(stream_buffer_cin);
								print_file.open("command.txt", std::ios::app);
								print_file << std::endl;
								print_open = 1;
							}
						}
						std::cin >> menu_2;
						std::cin.clear();
						std::cin.ignore(100, '\n');
						if (print_open == 1)
						{
							print_file << menu_2 << std::endl;
						}
						if (menu_2 == 1)
						{
							std::cout << "=======================" << std::endl;
							while (1)												//여기서부터 Friend 작업 공간
							{
								std::cout << "Menu - Friend" << std::endl;
								std::cout << "1. Add friends" << std::endl;
								std::cout << "2. Delete friends" << std::endl;
								std::cout << "3. My friends" << std::endl;
								std::cout << "4. Previous menu" << std::endl;
								std::cout << "=======================" << std::endl;
								std::cout << "Select Menu: ";
								if (open == 1)
								{
									if (std::cin.eof())
									{
										file.close();
										open = 0;
										std::cin.rdbuf(stream_buffer_cin);
										print_file.open("command.txt", std::ios::app);
										print_file << std::endl;
										print_open = 1;
									}
								}
								std::cin >> menu_3;
								std::cin.clear();
								std::cin.ignore(100, '\n');
								if (print_open == 1)
								{
									print_file << menu_3 << std::endl;
								}
								std::cout << "=======================" << std::endl;
								if (menu_3 == 1)
								{
									int friends_valid = 0;								//friends valid는 동일한 이름의 친구가 client 유저중 있는지 확인을 위한 변수
									std::string friends_name;
									std::cout << "Who want to add? : ";			
									if (open == 1)
									{
										if (std::cin.eof())
										{
											file.close();
											open = 0;
											std::cin.rdbuf(stream_buffer_cin);
											print_file.open("command.txt", std::ios::app);
											print_file << std::endl;
											print_open = 1;
										}
									}
									std::getline(std::cin, friends_name);
									if (print_open == 1)
									{
										print_file << friends_name << std::endl;
									}
									for (int i = 0; i < client_num; i++)
									{
										if (i == valid)												//나를 친구로 추가하는 case는 없어야하므로 0을 그대로 가져간다
										{

										}
										else
										{
											if (client[i].check_client(friends_name))				//client 중 동일한 이름을 가진 친구가 있는지 확인
											{
												friends_valid = 1;
												break;
											}
										}
									}
									if (friends_valid == 1)
									{
										if (client[valid].check_friends(friends_name) == 1)			//친구목록중에 그 이름을 가진 친구가 있는지 확인해서 있으면 이미 친구 추가가 되어있다는 멘트를 출력한다.
										{
											client[valid].add_friends(friends_name);				//친구목록에 그 이름을 가진 친구 추가
										}
										else
										{
											std::cout << "There is already that friends" << std::endl;
										}
									}
									else
									{
										std::cout << "There is no client with that ID" << std::endl;
									}
									std::cout << "=======================" << std::endl;
								}
								else if (menu_3 == 2)
								{
									int friends_valid = 0;
									std::string friends_name;
									std::cout << "Who want to delete? : ";
									if (open == 1)
									{
										if (std::cin.eof())
										{
											file.close();
											open = 0;
											std::cin.rdbuf(stream_buffer_cin);
											print_file.open("command.txt", std::ios::app);
											print_file << std::endl;
											print_open = 1;
										}
									}
									std::getline(std::cin, friends_name);
									if (print_open == 1)
									{
										print_file << friends_name << std::endl;
									}
									for (int i = 0; i < client_num; i++)
									{
										if (i == valid)												//자기 자신을 제외할 수는 없으므로
										{

										}
										else
										{
											if (client[i].check_client(friends_name))
											{
												friends_valid = 1;
												break;
											}
										}
									}
									if (friends_valid == 1)
									{
										if (client[valid].check_friends(friends_name) == 0)				//친구 목록에 있는 유저여야 delete 가능하므로
										{
											client[valid].del_friends(friends_name);
										}
										else
										{
											std::cout << "There is no friends with that ID" << std::endl;
										}
									}
									else
									{
										std::cout << "There is no client with that ID" << std::endl;
									}
									std::cout << "=======================" << std::endl;
								}
								else if (menu_3 == 3)
								{
									client[valid].my_friends();										//친구 목록을 보여주는 함수
									std::cout << "=======================" << std::endl;
								}
								else if (menu_3 == 4)
								{
									menu_3 = 0;
									break;
								}
								else
								{
									std::cout << "That's not valid value" << std::endl;
									std::cout << "=======================" << std::endl;
								}

							}
						}
						else if (menu_2 == 2)											//Feed menu
						{
							std::cout << "=======================" << std::endl;
							while (1)
							{
								std::cout << "Menu - Feed" << std::endl;
								std::cout << "1. All Feed" << std::endl;
								std::cout << "2. Post" << std::endl;
								std::cout << "3. My posting" << std::endl;
								std::cout << "4. Previous menu" << std::endl;
								std::cout << "=======================" << std::endl;
								std::cout << "Select Menu: ";
								if (open == 1)
								{
									if (std::cin.eof())
									{
										file.close();
										open = 0;
										std::cin.rdbuf(stream_buffer_cin);
										print_file.open("command.txt", std::ios::app);
										print_file << std::endl;
										print_open = 1;
									}
								}
								std::cin >> menu_4;
								std::cin.clear();
								std::cin.ignore(100, '\n');
								std::cout << "=======================" << std::endl;
								if (print_open == 1)
								{
									print_file << menu_4 << std::endl;
								}
								if (menu_4 == 1)
								{
									int* ary = new int[post_num];			//친구 목록에 있는 친구들의 client index를 불러오기 위함
									int post_index = 0;
									int num_posting_sel;
									for (int i = 0; i < post_num; i++)
									{
										for (int j = 0; j < client_num; j++)
											if (post[i].check_friends(client[valid].passing_friends_info(j)) == 1)		// client 친구들의 배열 목록의 index를 가져옴
											{
												ary[post_index] = i;
												post_index++;
												break;
											}
									}
									if (post_index == 0)			//index의 개수가 0이면 친구들이 올린 내용이 없는것이므로 아래와 같은 출력
									{
										std::cout << "There's no feed that your friends post" << std::endl;
										std::cout << "=======================" << std::endl;
									}
									else
									{
										while (1)				//post를 모두 보여줌
										{
											for (int i = 0; i < post_index; i++)
											{
												std::cout << i << ". ";
												post[ary[i]].show();
											}
											std::cout << "=======================" << std::endl;
											std::cout << "Select number: ";
											if (open == 1)
											{
												if (std::cin.eof())
												{
													file.close();
													open = 0;
													std::cin.rdbuf(stream_buffer_cin);
													print_file.open("command.txt", std::ios::app);
													print_file << std::endl;
													print_open = 1;
												}
											}
											num_posting_sel = -2;										// -1은 뒤로 돌아가는 명령어기때문에 -2로 초기화를 해두었습니다. 밑 my posting도 똑같은 과정을 거침
											std::cin >> num_posting_sel;
											std::cin.clear();
											std::cin.ignore(100, '\n');
											if (print_open == 1)
											{
												print_file << num_posting_sel << std::endl;
											}
											if (num_posting_sel < post_index && ( num_posting_sel >= 0)) // post_index보다 작거나 0보다 크거나 같은 수를 입력해야되므로
											{
												std::cout << "=======================" << std::endl;
												std::string post_comment_content;
												std::string like_or_no;
												int tempt_comment_num;
												post[ary[num_posting_sel]].show();
												std::cout << "Reply: " << std::endl;
												post[ary[num_posting_sel]].comment_show();
												std::cout << "=======================" << std::endl;
												if (post[ary[num_posting_sel]].check_like_it(ID) == 0) //좋아요가 눌린 사람이면 좋아요를 누르겠습니까? 기능이 뜨면 안되므로
												{
													std::cout << "Do you like it? (y/n): ";
													if (open == 1)
													{
														if (std::cin.eof())
														{
															file.close();
															open = 0;
															std::cin.rdbuf(stream_buffer_cin);
															print_file.open("command.txt", std::ios::app);
															print_file << std::endl;
															print_open = 1;
														}
													}
													std::getline(std::cin, like_or_no);
													if (print_open == 1)
													{
														print_file << like_or_no << std::endl;
													}
													if (like_or_no == "y")
													{
														post[ary[num_posting_sel]].check_like(ID);				//좋아요 개수를 추가해줌
													}
													else if (like_or_no == "n")
													{

													}
													else
													{
														std::cout << "It's not valid input" << std::endl;
													}
												}
												std::cout << "Write Comment: ";
												if (open == 1)
												{
													if (std::cin.eof())
													{
														file.close();
														open = 0;
														std::cin.rdbuf(stream_buffer_cin);
														print_file.open("command.txt", std::ios::app);
														print_file << std::endl;
														print_open = 1;
													}
												}
												std::getline(std::cin, post_comment_content);
												if (print_open == 1)
												{
													print_file << post_comment_content << std::endl;
												}
												post[ary[num_posting_sel]].post_commenting(ID, post_comment_content); //댓글 추가 기능
												std::cout << "=======================" << std::endl;
											}
							
											else if (num_posting_sel == -1)									//-1일시 break
											{
												std::cout << "=======================" << std::endl;
												break;
											}
											else
																	// post_index보다 작거나 0보다 크거나 같은 수를 입력해야되므로 그 외의 수에 대해선 예외처리를 한다.
											{
												std::cout << "=======================" << std::endl;
												std::cout << "It's not valid value" << std::endl;
												std::cout << "=======================" << std::endl;
											}
										}
									}
									delete[] ary;
								}
								else if (menu_4 == 2)
								{
									std::string posting;
									std::cout << "Post: ";
									if (open == 1)
									{
										if (std::cin.eof())
										{
											file.close();
											open = 0;
											std::cin.rdbuf(stream_buffer_cin);
											print_file.open("command.txt", std::ios::app);
											print_file << std::endl;
											print_open = 1;
										}
									}
									std::getline(std::cin, posting);
									if (print_open == 1)
									{
										print_file << posting << std::endl;
									}
									if (posting == "")
									{
																								//아무것도 없을 시 아무것도 출력하지 않는다
									}
									else
									{
										for (int i = post_num; i > 0; i--)
										{
											post[i] = post[i - 1];								//post가 추가되면 post들을 다 하나씩 미뤄주고, 제일 최근 post를 가장 앞으로 한다.
										}
										post[0].posting(posting, ID);
										post_num++;
									}
									std::cout << "=======================" << std::endl;
								}
								else if (menu_4 == 3)
								{
									int* ary = new int[post_num];				//내 글의 post에 대한 index를 받아오기 위함
									int post_index = 0;
									int num_posting_sel;
									for (int i = 0; i < post_num; i++)
									{
										if (post[i].my_posting(ID) == 1)
										{
											ary[post_index] = i;
											post_index++;
										}
									}
									if (post_index == 0)
									{
										std::cout << "There's no feed that you post" << std::endl;
										std::cout << "=======================" << std::endl;
									}
									else
									{
										while (1)
										{
											for (int i = 0; i < post_index; i++)
											{
												std::cout << i << ". ";
												post[ary[i]].show();						//포스트를 보여줌
											}
											std::cout << "=======================" << std::endl;
											std::cout << "Select number: ";
											if (open == 1)
											{
												if (std::cin.eof())
												{
													file.close();
													open = 0;
													std::cin.rdbuf(stream_buffer_cin);
													print_file.open("command.txt", std::ios::app);
													print_file << std::endl;
													print_open = 1;
												}
											}
											num_posting_sel = -2;
											std::cin >> num_posting_sel;
											std::cin.clear();
											std::cin.ignore(100, '\n');
											if (print_open == 1)
											{
												print_file << num_posting_sel << std::endl;
											}
											if (num_posting_sel < post_index && (num_posting_sel >= 0 )) // valid한 값인지 검사 0 ~ post_index -1 까지가 valid 하므로
											{
												std::cout << "=======================" << std::endl;
												std::string post_comment_content;
												std::string like_or_no;
												int tempt_comment_num;
												post[ary[num_posting_sel]].show();
												std::cout << "Reply: " << std::endl;
												post[ary[num_posting_sel]].comment_show();
												std::cout << "=======================" << std::endl;
												if (post[ary[num_posting_sel]].check_like_it(ID) == 0)		//위의 값처럼 좋아요를 누른 사람이면 좋아요를 누르겠습니까? 라는 멘트를 보여주지 않기 위함
												{															//위의 all feed 와 동일한 형태를 가짐
													std::cout << "Do you like it? (y/n): ";
													if (open == 1)
													{
														if (std::cin.eof())
														{
															file.close();
															open = 0;
															std::cin.rdbuf(stream_buffer_cin);
															print_file.open("command.txt", std::ios::app);
															print_file << std::endl;
															print_open = 1;
														}
													}
													std::getline(std::cin, like_or_no);
													if (print_open == 1)
													{
														print_file << like_or_no << std::endl;
													}
													if (like_or_no == "y")
													{
														post[ary[num_posting_sel]].check_like(ID);
													}
													else if (like_or_no == "n")
													{

													}
													else
													{
														std::cout << "It's not valid input" << std::endl;

													}
												}
												std::cout << "Write Comment: ";
												if (open == 1)
												{
													if (std::cin.eof())
													{
														file.close();
														open = 0;
														std::cin.rdbuf(stream_buffer_cin);
														print_file.open("command.txt", std::ios::app);
														print_file << std::endl;
														print_open = 1;
													}
												}
												std::getline(std::cin, post_comment_content);
												if (print_open == 1)
												{
													print_file << post_comment_content << std::endl;
												}
												post[ary[num_posting_sel]].post_commenting(ID, post_comment_content);
												std::cout << "=======================" << std::endl;
											}
											else if (num_posting_sel == -1)
											{
												std::cout << "=======================" << std::endl;
												break;
											}
											else
											{																//아닌 경우 이므로
												std::cout << "=======================" << std::endl;
												std::cout << "It's not valid value" << std::endl;
												std::cout << "=======================" << std::endl;

											}
										}
									}
									delete[] ary;
								}
								else if (menu_4 == 4)
								{
									menu_4 = 0;
									break;
								}
								else
								{
									std::cout << "That's not valid value" << std::endl;
								}
							}
						}
						else if (menu_2 == 3)
						{
							menu_2 = 0;
							break;
						}
						else if (menu_2 == 4)		//delete my account 함수
						{
							for (int i = 0; i < post_num; i++)
							{
								if (post[i].my_posting(ID) == 1)			//일단 내가 쓴 post들을 모두 지운다.
								{
									for (int j = i; j < post_num - 1; j++)
									{
										post[j] = post[j + 1];
									}
									post_num--;
									post[post_num].deleting_my_post();
									i--;
								}
							}

							for (int i = 0; i < post_num; i++)				//그 후 댓글 중 내가 단 것이 있으면 지운다.
							{
								post[i].deleting_comment(ID);
								post[i].deleting_like(ID);
							}

							for (int i = 0; i < client_num; i++)			//친구로 내가 설정이 되어있으면 모든 client에 대해서 지워준다.
							{
								if (client[i].check_client(ID) == 0)
								{
									client[i].del_friends(ID);
								}
							}

							for (int i = 0; i < post_num; i++)				//내가 좋아요를 누른 경우 내가 좋아요를 누른 post의 글에서 내 좋아요 개수를 줄여줘야하므로
							{
								post[i].deleting_like(ID);
							}

							int tempt = 0;

							for (int i = 0; i < client_num; i++)			//내가 위치한 배열의 값을 덮어 씌우고, 나머지 client들을 앞의 순서로 당겨준다.
							{
								if (client[i].check_client(ID) == 1)
								{
									tempt = i;
								}
							}
							for (int i = tempt; i < client_num - 1; i++)
							{
								client[i] = client[i + 1];
							}

							menu_2 = 0;
							client_num--;
							client[client_num].del_my_log();				//나머지 모든 값들을 복사했으므로, 맨뒤의 계정을 삭제해준다.
							break;
						}
						else
						{
							std::cout << "That's not valid value" << std::endl;
							std::cout << "=======================" << std::endl;
						}
					}
				}
				else if (client[valid].log_in(ID, Password) == 2)	//비밀번호와 아이디가 일치하지 않는 경우 passwor를 확인하라는 메시지가 나옵니다.
				{
					std::cout << "Check your Password!" << std::endl;
				}
			}

		}
		else if (menu_1 == 3)					//커맨드.txt 파일을 불러옴
		{
			print_file.close();
			file.open("command.txt", std::ios::in);
			if (!file.is_open())										//파일이 열리지 않는 경우 오류를 출력해냄
			{
				std::cout << "Could not open the file" << std::endl;
			}
			else
			{															//파일이 열린 경우 open을 1로 해서 file에서 값을 읽어오고, print_open을 이용해서 파일 출력을 하지 않게 만든다.
				open = 1;
				print_open = 0;
				std::cin.rdbuf(stream_buffer_file);						//파일에서 값을 읽어오도록 만드는 함수이다.
			}
		}
		else if (menu_1 == 4)
		{
			break;
		}
		else
		{
			std::cout << "That's not valid value" << std::endl;
		}
	}

	print_file.close();

	return 0;

}