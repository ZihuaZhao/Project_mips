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
	int line_num, arg_num;//属于第几行、有几个参数
	func command;
	int Rdest = 255, Rsrc, Rsrc1 = 255, Rsrc2, Src2_reg;
	int Src2_dig, Imm, ad_reg , ad_dig;
	bool Src2_type;//如果是dig返回true，否则返回false；
	bool ad_type;//如果是label返回true，否则返回false；
	string label_name;
};

#endif