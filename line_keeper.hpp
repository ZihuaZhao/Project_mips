#ifndef LINE_KEEPER
#define LINE_KEEPER


#include<string>
#include<cstring>
#include<vector>
#include<map>
#include"constant.hpp"

using namespace std;

class line_keeper {
public:
	int line_num, arg_num;//���ڵڼ��С��м�������
	func command;
	int Rdest = 255, Rsrc, Rsrc1 = 255, Rsrc2, Src2_reg;
	int Src2_dig, Imm, ad_reg , ad_dig;
	bool Src2_type;//�����dig����true�����򷵻�false��
	bool ad_type;//�����label����true�����򷵻�false��
	string label_name;
};

#endif