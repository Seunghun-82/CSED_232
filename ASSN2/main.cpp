#include "feed.h"
#include "member.h"
#include <fstream>
#include <cstdio>
#include <iostream>
#include <string>

int main()
{
	int menu_1, menu_2, menu_3, menu_4; //menu_1, 2, 3, 4�� ���� Menu ǥ�ð� ������ â���� ���� �޾Ƶ��̱� ���� �����Դϴ�.
	int open = 0;						//open�� Load command�� ������ ��� ���� ����¿��� stdin , out���� ������ ���� �����Դϴ�.
	int print_open = 1;					//stdin�� �� ���� ���� ����� ���ֱ� ���� �����Դϴ�.
	int client_num = 0;					//�� ���� ���� ��Ÿ���� �����Դϴ�.
	int post_num = 0;					//�� post�� ������ ��Ÿ���� �����Դϴ�.
	int present_level = 0;				//ù ��° �޴� �õ����� load command�� ���� �ʴ� ��� print_file�� ������⸦ �� �� ������ϱ� ������ ���ܳ� �����Դϴ�. menu_1�� �� ��° ������ �Ǿ������� �Ǵ����ִ� �����Դϴ�.
	std::string ID, Name, Birthday, Password;			//ID, Name, Birthday, Password�� �޾ƿ��� �����Դϴ�.
	std::ifstream file;									//load command�� ���� ����
	std::fstream print_file;							//file ����� ���ִ� ����

	std::streambuf* stream_buffer_cin = std::cin.rdbuf();		// �̰� �ҷ��ָ� standard in���� �ٲ��ִ� ����
	std::streambuf* stream_buffer_file = file.rdbuf();			// �̰� �ҷ��ָ� file �Է����� �ٲ��ִ� ����
	print_file.open("command.txt", std::ios::app);
	member client[50];
	feed post[100];
	while (1)
	{
		std::cout << "=======================" << std::endl;			//Main �޴� �Դϴ�.
		std::cout << "Menu - Main" << std::endl;
		std::cout << "1. Sign up" << std::endl;
		std::cout << "2. Sign in" << std::endl;
		std::cout << "3. Load command" << std::endl;
		std::cout << "4. Program exit" << std::endl;
		std::cout << "=======================" << std::endl;
		std::cout << "Select Menu: ";
		menu_1 = 0;
		if (open == 1)													//open�� 1�� ��� load command�� �������� ��Ȳ�Դϴ�.
		{
			if (std::cin.eof())											//cin.eof�� ��� standard in���� �ٲ��ָ�, �Էµ� ���� ����ϰ� ���ݴϴ�.
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
		std::cin.clear();												//���۸� ����ֱ� ���ؼ� ����߽��ϴ�.
		std::cin.ignore(100, '\n');
		if (print_open == 1)
		{
			if (present_level == 0 && menu_1 != 3)
			{
				print_file << std::endl;
			}

			if (menu_1 == 4)
			{
				print_file << menu_1;									//���̽��� ������ ������ �� �������ٿ��� ������⸦ �ϸ� �ȵǱ� �����Դϴ�.
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
		if (menu_1 == 1)									//ȸ�� ����
		{
			int error = 0;									//error ������ ���� ID�� ����ϴ� ����� �ִ� ��� ȸ�������� ��Ű�� �ʱ� ���ؼ�
															//���Ǵ� �����Դϴ�.
			if (open == 1)									//���� open, print_open�� ���� case�� ��� ���� ���� �����Դϴ�.
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
		else if (menu_1 == 2)				//�α��� ȭ��
		{
			int valid = -1;					//valid�� �ִ� ������ �� ȸ���� �� ��° ȸ������ �˱� ���ؼ� �ʿ��� �����Դϴ�.
											//�Ŀ� ������ ��� client�� ���� ������ �ϱ� ���ؼ� �ʿ��� �����Դϴ�.
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
					valid = i;					//���� ���̵��� user�� �ִ��� �����մϴ�.
					break;
				}
				else
				{
					valid = -1;					//�ƴ� �� ������ ����մϴ�.
				}
			}
			if (valid == -1)
			{
				std::cout << "Unregistered account!" << std::endl;
			}
			else
			{
				if (client[valid].log_in(ID, Password) == 1)		//���⼭ ��й�ȣ�� ���̵� ��ġ�ϴ��� Ȯ���մϴ�.
				{
					client[valid].pass_log_info(ID, Name, Birthday); //������ ������ ID, Name, Birthday�� �����մϴ�.
					while (1)										//���⼭���� my page
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
							while (1)												//���⼭���� Friend �۾� ����
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
									int friends_valid = 0;								//friends valid�� ������ �̸��� ģ���� client ������ �ִ��� Ȯ���� ���� ����
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
										if (i == valid)												//���� ģ���� �߰��ϴ� case�� ������ϹǷ� 0�� �״�� ��������
										{

										}
										else
										{
											if (client[i].check_client(friends_name))				//client �� ������ �̸��� ���� ģ���� �ִ��� Ȯ��
											{
												friends_valid = 1;
												break;
											}
										}
									}
									if (friends_valid == 1)
									{
										if (client[valid].check_friends(friends_name) == 1)			//ģ������߿� �� �̸��� ���� ģ���� �ִ��� Ȯ���ؼ� ������ �̹� ģ�� �߰��� �Ǿ��ִٴ� ��Ʈ�� ����Ѵ�.
										{
											client[valid].add_friends(friends_name);				//ģ����Ͽ� �� �̸��� ���� ģ�� �߰�
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
										if (i == valid)												//�ڱ� �ڽ��� ������ ���� �����Ƿ�
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
										if (client[valid].check_friends(friends_name) == 0)				//ģ�� ��Ͽ� �ִ� �������� delete �����ϹǷ�
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
									client[valid].my_friends();										//ģ�� ����� �����ִ� �Լ�
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
									int* ary = new int[post_num];			//ģ�� ��Ͽ� �ִ� ģ������ client index�� �ҷ����� ����
									int post_index = 0;
									int num_posting_sel;
									for (int i = 0; i < post_num; i++)
									{
										for (int j = 0; j < client_num; j++)
											if (post[i].check_friends(client[valid].passing_friends_info(j)) == 1)		// client ģ������ �迭 ����� index�� ������
											{
												ary[post_index] = i;
												post_index++;
												break;
											}
									}
									if (post_index == 0)			//index�� ������ 0�̸� ģ������ �ø� ������ ���°��̹Ƿ� �Ʒ��� ���� ���
									{
										std::cout << "There's no feed that your friends post" << std::endl;
										std::cout << "=======================" << std::endl;
									}
									else
									{
										while (1)				//post�� ��� ������
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
											num_posting_sel = -2;										// -1�� �ڷ� ���ư��� ��ɾ�⶧���� -2�� �ʱ�ȭ�� �صξ����ϴ�. �� my posting�� �Ȱ��� ������ ��ħ
											std::cin >> num_posting_sel;
											std::cin.clear();
											std::cin.ignore(100, '\n');
											if (print_open == 1)
											{
												print_file << num_posting_sel << std::endl;
											}
											if (num_posting_sel < post_index && ( num_posting_sel >= 0)) // post_index���� �۰ų� 0���� ũ�ų� ���� ���� �Է��ؾߵǹǷ�
											{
												std::cout << "=======================" << std::endl;
												std::string post_comment_content;
												std::string like_or_no;
												int tempt_comment_num;
												post[ary[num_posting_sel]].show();
												std::cout << "Reply: " << std::endl;
												post[ary[num_posting_sel]].comment_show();
												std::cout << "=======================" << std::endl;
												if (post[ary[num_posting_sel]].check_like_it(ID) == 0) //���ƿ䰡 ���� ����̸� ���ƿ並 �����ڽ��ϱ�? ����� �߸� �ȵǹǷ�
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
														post[ary[num_posting_sel]].check_like(ID);				//���ƿ� ������ �߰�����
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
												post[ary[num_posting_sel]].post_commenting(ID, post_comment_content); //��� �߰� ���
												std::cout << "=======================" << std::endl;
											}
							
											else if (num_posting_sel == -1)									//-1�Ͻ� break
											{
												std::cout << "=======================" << std::endl;
												break;
											}
											else
																	// post_index���� �۰ų� 0���� ũ�ų� ���� ���� �Է��ؾߵǹǷ� �� ���� ���� ���ؼ� ����ó���� �Ѵ�.
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
																								//�ƹ��͵� ���� �� �ƹ��͵� ������� �ʴ´�
									}
									else
									{
										for (int i = post_num; i > 0; i--)
										{
											post[i] = post[i - 1];								//post�� �߰��Ǹ� post���� �� �ϳ��� �̷��ְ�, ���� �ֱ� post�� ���� ������ �Ѵ�.
										}
										post[0].posting(posting, ID);
										post_num++;
									}
									std::cout << "=======================" << std::endl;
								}
								else if (menu_4 == 3)
								{
									int* ary = new int[post_num];				//�� ���� post�� ���� index�� �޾ƿ��� ����
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
												post[ary[i]].show();						//����Ʈ�� ������
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
											if (num_posting_sel < post_index && (num_posting_sel >= 0 )) // valid�� ������ �˻� 0 ~ post_index -1 ������ valid �ϹǷ�
											{
												std::cout << "=======================" << std::endl;
												std::string post_comment_content;
												std::string like_or_no;
												int tempt_comment_num;
												post[ary[num_posting_sel]].show();
												std::cout << "Reply: " << std::endl;
												post[ary[num_posting_sel]].comment_show();
												std::cout << "=======================" << std::endl;
												if (post[ary[num_posting_sel]].check_like_it(ID) == 0)		//���� ��ó�� ���ƿ並 ���� ����̸� ���ƿ並 �����ڽ��ϱ�? ��� ��Ʈ�� �������� �ʱ� ����
												{															//���� all feed �� ������ ���¸� ����
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
											{																//�ƴ� ��� �̹Ƿ�
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
						else if (menu_2 == 4)		//delete my account �Լ�
						{
							for (int i = 0; i < post_num; i++)
							{
								if (post[i].my_posting(ID) == 1)			//�ϴ� ���� �� post���� ��� �����.
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

							for (int i = 0; i < post_num; i++)				//�� �� ��� �� ���� �� ���� ������ �����.
							{
								post[i].deleting_comment(ID);
								post[i].deleting_like(ID);
							}

							for (int i = 0; i < client_num; i++)			//ģ���� ���� ������ �Ǿ������� ��� client�� ���ؼ� �����ش�.
							{
								if (client[i].check_client(ID) == 0)
								{
									client[i].del_friends(ID);
								}
							}

							for (int i = 0; i < post_num; i++)				//���� ���ƿ並 ���� ��� ���� ���ƿ並 ���� post�� �ۿ��� �� ���ƿ� ������ �ٿ�����ϹǷ�
							{
								post[i].deleting_like(ID);
							}

							int tempt = 0;

							for (int i = 0; i < client_num; i++)			//���� ��ġ�� �迭�� ���� ���� �����, ������ client���� ���� ������ ����ش�.
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
							client[client_num].del_my_log();				//������ ��� ������ ���������Ƿ�, �ǵ��� ������ �������ش�.
							break;
						}
						else
						{
							std::cout << "That's not valid value" << std::endl;
							std::cout << "=======================" << std::endl;
						}
					}
				}
				else if (client[valid].log_in(ID, Password) == 2)	//��й�ȣ�� ���̵� ��ġ���� �ʴ� ��� passwor�� Ȯ���϶�� �޽����� ���ɴϴ�.
				{
					std::cout << "Check your Password!" << std::endl;
				}
			}

		}
		else if (menu_1 == 3)					//Ŀ�ǵ�.txt ������ �ҷ���
		{
			print_file.close();
			file.open("command.txt", std::ios::in);
			if (!file.is_open())										//������ ������ �ʴ� ��� ������ ����س�
			{
				std::cout << "Could not open the file" << std::endl;
			}
			else
			{															//������ ���� ��� open�� 1�� �ؼ� file���� ���� �о����, print_open�� �̿��ؼ� ���� ����� ���� �ʰ� �����.
				open = 1;
				print_open = 0;
				std::cin.rdbuf(stream_buffer_file);						//���Ͽ��� ���� �о������ ����� �Լ��̴�.
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