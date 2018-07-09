#pragma once
#include<string>
#include<map>
#include<vector>
#include<cmath>
#include<cstring>
#include"line_keeper.hpp"

using namespace std;

class execution {
private:
	map<string, int> *database;
	map<string, int> *funcbase;
	vector<line_keeper> *line_base;
	char* vir_mem;
	char* static_seg;
	char* stack_seg;
	char* heap_seg;
	int* mainpos;
	int* reg;


public:
	execution(char* v_m , char* static_s , char* stack_s , char* heap_s , map<string, int> *d_b,
		map<string, int> *f_b , vector<line_keeper> *l_b , int *m , int* r) {
		vir_mem = v_m;
		static_seg = static_s;
		stack_seg = stack_s;
		heap_seg = heap_s;
		database = d_b;
		funcbase = f_b;
		line_base = l_b;
		reg = r;
		mainpos = m;
	}

	void func_to_out(func str) {
		if (str == _align) cout << "_align" << endl;
		if (str == _ascii) cout << "_ascii" << endl;
		if (str == _asciiz) cout << "_asciiz" << endl;
		if (str == _byte) cout << "_byte" << endl;
		if (str == _half) cout << "_half" << endl;
		if (str == _word) cout << "_word" << endl;
		if (str == _space) cout << "_space" << endl;
		if (str == _data) cout << "_data" << endl;
		if (str == _text) cout << "_text" << endl;
		if (str == add) cout << "add" << endl;
		if (str == addu) cout << "addu" << endl;
		if (str == addiu) cout << "addiu" << endl;
		if (str == sub) cout << "sub" << endl;
		if (str == subu) cout << "subu" << endl;
		if (str == mul) cout << "mul" << endl;
		if (str == mulu) cout << "mulu" << endl;
		if (str == divv) cout << "divv" << endl;
		if (str == divu) cout << "divu" << endl;
		if (str == xoor) cout << "xoor" << endl;
		if (str == xoru) cout << "xoru" << endl;
		if (str == neg) cout << "neg" << endl;
		if (str == negu) cout << "negu" << endl;
		if (str == rem) cout << "rem" << endl;
		if (str == remu) cout << "remu" << endl;
		if (str == li) cout << "li" << endl;
		if (str == seq) cout << "seq" << endl;
		if (str == sge) cout << "sge" << endl;
		if (str == sle) cout << "sle" << endl;
		if (str == slt) cout << "slt" << endl;
		if (str == sne) cout << "sne" << endl;
		if (str == b) cout << "b" << endl;
		if (str == beq) cout << "beq" << endl;
		if (str == bge) cout << "bge" << endl;
		if (str == ble) cout << "ble" << endl;
		if (str == bgt) cout << "bgt" << endl;
		if (str == blt) cout << "blt" << endl;
		if (str == beqz) cout << "beqz" << endl;
		if (str == bnez) cout << "bnez" << endl;
		if (str == blez) cout << "blez" << endl;
		if (str == bgez) cout << "bgez" << endl;
		if (str == bgtz) cout << "bgtz" << endl;
		if (str == bltz) cout << "bltz" << endl;
		if (str == j) cout << "j" << endl;
		if (str == jr) cout << "jr" << endl;
		if (str == jal) cout << "jal" << endl;
		if (str == jalr) cout << "jalr" << endl;
		if (str == la) cout << "la" << endl;
		if (str == lb) cout << "lb" << endl;
		if (str == lh) cout << "lh" << endl;
		if (str == lw) cout << "lw" << endl;
		if (str == sb) cout << "sb" << endl;
		if (str == sh) cout << "sh" << endl;
		if (str == sw) cout << "sw" << endl;
		if (str == mov) cout << "move" << endl;
		if (str == mfhi) cout << "mfhi" << endl;
		if (str == mflo) cout << "mflo" << endl;
		if (str == nop) cout << "nop" << endl;
		if (str == syscall) cout << "syscall" << endl;
		if (str == mainp) cout << "main" << endl;
		if (str == label) cout << "label" << endl;
	}

	~execution() {}

	void execute() {
		int n = *mainpos;
		while (n < line_base->size()) {
			line_keeper line = line_base->operator[](n);
			//cout << n << " ";
			//func_to_out(line.command);
			if (line.command == add) {
				if (line.Src2_type) {
					reg[line.Rdest] = reg[line.Rsrc1] + line.Src2_dig;
				}
				else {
					reg[line.Rdest] = reg[line.Rsrc1] + reg[line.Src2_reg];
				}
				n++;
				continue;
			}
			if (line.command == addu) {
				if (line.Src2_type) {
					reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] + (unsigned int)line.Src2_dig;
				}
				else {
					reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] + (unsigned int)reg[line.Src2_reg];
				}
				n++;
				continue;
			}
			if (line.command == addiu) {
				reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] + (unsigned int)line.Imm;
				n++;
				continue;
			}
			if (line.command == sub) {
				if (line.Src2_type) {
					reg[line.Rdest] = reg[line.Rsrc1] - line.Src2_dig;
				}
				else {
					reg[line.Rdest] = reg[line.Rsrc1] - reg[line.Src2_reg];
				}
				n++;
				continue;
			}
			if (line.command == subu) {
				if (line.Src2_type) {
					reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] - (unsigned int)line.Src2_dig;
				}
				else {
					reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] - (unsigned int)reg[line.Src2_reg];
				}
				n++;
				continue;
			}
			if (line.command == mul) {
				if (line.arg_num == 3) {
					if (line.Src2_type) {
						reg[line.Rdest] = reg[line.Rsrc1] * line.Src2_dig;
					}
					else {
						reg[line.Rdest] = reg[line.Rsrc1] * reg[line.Src2_reg];
					}
				}
				else {
					if (line.Src2_type) {
						int a = reg[line.Rdest] * line.Src2_dig & (8589934591);
						int b = reg[line.Rdest] * line.Src2_dig >> 32;
						reg[32] = b;
						reg[33] = a;
					}
					else {
						int a = reg[line.Rdest] * reg[line.Src2_reg] & (8589934591);
						int b = reg[line.Rdest] * reg[line.Src2_reg] >> 32;
						reg[32] = b;
						reg[33] = a;
					}
				}
				n++;
				continue;
			}
			if (line.command == mulu) {
				if (line.arg_num == 3) {
					if (line.Src2_type) {
						reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] * (unsigned int)line.Src2_dig;
					}
					else {
						reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] * (unsigned int)reg[line.Src2_reg];
					}
				}
				else {
					if (line.Src2_type) {
						int a = (unsigned int)reg[line.Rdest] * (unsigned int)line.Src2_dig & (8589934591);
						int b = (unsigned int)reg[line.Rdest] * (unsigned int)line.Src2_dig >> 32;
						reg[32] = b;
						reg[33] = a;
					}
					else {
						int a = (unsigned int)reg[line.Rdest] * (unsigned int)reg[line.Src2_reg] & (8589934591);
						int b = (unsigned int)reg[line.Rdest] * (unsigned int)reg[line.Src2_reg] >> 32;
						reg[32] = b;
						reg[33] = a;
					}
				}
				n++;
				continue;
			}
			if (line.command == divv) {
				if (line.arg_num == 3) {
					if (line.Src2_type) {
						reg[line.Rdest] = reg[line.Rsrc1] / line.Src2_dig;
					}
					else {
						reg[line.Rdest] = reg[line.Rsrc1] / reg[line.Src2_reg];
					}
				}
				else {
					if (line.Src2_type) {
						int a = reg[line.Rsrc1] / line.Src2_dig;
						int b = reg[line.Rsrc1] % line.Src2_dig;
						reg[32] = b;
						reg[33] = a;
					}
					else {
						int a = reg[line.Rsrc1] / reg[line.Src2_reg];
						int b = reg[line.Rsrc1] % reg[line.Src2_reg];
						reg[32] = b;
						reg[33] = a;
					}
				}
				n++;
				continue;
			}
			if (line.command == divu) {
				if (line.arg_num == 3) {
					if (line.Src2_type) {
						reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] / (unsigned int)line.Src2_dig;
					}
					else {
						reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] / (unsigned int)reg[line.Src2_reg];
					}
				}
				else {
					if (line.Src2_type) {
						int a = (unsigned int)reg[line.Rsrc1] / (unsigned int)line.Src2_dig;
						int b = (unsigned int)reg[line.Rsrc1] % (unsigned int)line.Src2_dig;
						reg[32] = b;
						reg[33] = a;
					}
					else {
						int a = (unsigned int)reg[line.Rsrc1] / (unsigned int)reg[line.Src2_reg];
						int b = (unsigned int)reg[line.Rsrc1] % (unsigned int)reg[line.Src2_reg];
						reg[32] = b;
						reg[33] = a;
					}
				}
				n++;
				continue;
			}
			if (line.command == xoor) {
				if (line.Src2_type) {
					reg[line.Rdest] = reg[line.Rsrc1] ^ line.Src2_dig;
				}
				else {
					reg[line.Rdest] = reg[line.Rsrc1] ^ reg[line.Src2_reg];
				}
				n++;
				continue;
			}
			if (line.command == xoru) {
				if (line.Src2_type) {
					reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] ^ (unsigned int)line.Src2_dig;
				}
				else {
					reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] ^ (unsigned int)reg[line.Src2_reg];
				}
				n++;
				continue;
			}
			if (line.command == neg) {
				reg[line.Rdest] = -reg[line.Rsrc];
				n++;
				continue;
			}
			if (line.command == negu) {
				reg[line.Rdest] = ~(unsigned int)reg[line.Rsrc];
				n++;
				continue;
			}
			if (line.command == rem) {
				if (line.Src2_type) {
					reg[line.Rdest] = reg[line.Rsrc1] % line.Src2_dig;
				}
				else {
					reg[line.Rdest] = reg[line.Rsrc1] % reg[line.Src2_reg];
				}
				n++;
				continue;
			}
			if (line.command == remu) {
				if (line.Src2_type) {
					reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] % (unsigned int)line.Src2_dig;
 				}
				else {
					reg[line.Rdest] = (unsigned int)reg[line.Rsrc1] % (unsigned int)reg[line.Src2_reg];
				}
				n++;
				continue;
			}
			if (line.command == li) {
				reg[line.Rdest] = line.Imm;
				n++;
				continue;
			}
			if (line.command == seq) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] == line.Src2_dig) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				else {
					if (reg[line.Rsrc1] == reg[line.Src2_reg]) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				n++;
				continue;
			}
			if (line.command == sge) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] >= line.Src2_dig) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				else {
					if (reg[line.Rsrc1] >= reg[line.Src2_reg]) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				n++;
				continue;
			}
			if (line.command == sgt) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] > line.Src2_dig) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				else {
					if (reg[line.Rsrc1] > reg[line.Src2_reg]) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				n++;
				continue;
			}
			if (line.command == sle) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] <= line.Src2_dig) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				else {
					if (reg[line.Rsrc1] <= reg[line.Src2_reg]) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				n++;
				continue;
			}
			if (line.command == slt) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] < line.Src2_dig) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				else {
					if (reg[line.Rsrc1] < reg[line.Src2_reg]) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				n++;
				continue;
			}
			if (line.command == sne) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] != line.Src2_dig) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				else {
					if (reg[line.Rsrc1] != reg[line.Src2_reg]) {
						reg[line.Rdest] = 1;
					}
					else {
						reg[line.Rdest] = 0;
					}
				}
				n++;
				continue;
			}
			if (line.command == b || line.command == j) {
				n = funcbase->operator[](line.label_name);
				continue;
			}
			if (line.command == beq) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] == line.Src2_dig) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
				else {
					if (reg[line.Rsrc1] == reg[line.Src2_reg]) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
			}
			if (line.command == bne) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] != line.Src2_dig) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
				else {
					if (reg[line.Rsrc1] != reg[line.Src2_reg]) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
			}
			if (line.command == bge) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] >= line.Src2_dig) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
				else {
					if (reg[line.Rsrc1] >= reg[line.Src2_reg]) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
			}
			if (line.command == ble) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] <= line.Src2_dig) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
				else {
					if (reg[line.Rsrc1] <= reg[line.Src2_reg]) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
			}
			if (line.command == bgt) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] > line.Src2_dig) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
				else {
					if (reg[line.Rsrc1] > reg[line.Src2_reg]) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
			}
			if (line.command == blt) {
				if (line.Src2_type) {
					if (reg[line.Rsrc1] < line.Src2_dig) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
				else {
					if (reg[line.Rsrc1] < reg[line.Src2_reg]) {
						n = funcbase->operator[](line.label_name);
						continue;
					}
					else {
						n++;
						continue;
					}
				}
			}
			if (line.command == beqz) {
				if (reg[line.Rsrc] == 0) {
					n = funcbase->operator[](line.label_name);
					continue;
				}
				else {
					n++;
					continue;
				}
			}
			if (line.command == bnez) {
				if (reg[line.Rsrc] != 0) {
					n = funcbase->operator[](line.label_name);
					continue;
				}
				else {
					n++;
					continue;
				}
			}
			if (line.command == blez) {
				if (reg[line.Rsrc] <= 0) {
					n = funcbase->operator[](line.label_name);
					continue;
				}
				else {
					n++;
					continue;
				}
			}
			if (line.command == bgez) {
				if (reg[line.Rsrc] >= 0) {
					n = funcbase->operator[](line.label_name);
					continue;
				}
				else {
					n++;
					continue;
				}
			}
			if (line.command == bgtz) {
				if (reg[line.Rsrc] > 0) {
					n = funcbase->operator[](line.label_name);
					continue;
				}
				else {
					n++;
					continue;
				}
			}
			if (line.command == bltz) {
				if (reg[line.Rsrc] < 0) {
					n = funcbase->operator[](line.label_name);
					continue;
				}
				else {
					n++;
					continue;
				}
			}
			if (line.command == jr) {
				n = reg[line.Rsrc];
				continue;
			}
			if (line.command == jal) {
				reg[31] = n + 1;
				n = funcbase->operator[](line.label_name);
				continue;
			}
			if (line.command == jalr) {
				reg[31] = n + 1;
				n = reg[line.Rsrc];
				continue;
			}
			if (line.command == la) {
				reg[line.Rdest] = funcbase->operator[](line.label_name);
				n++;
				continue;
			}
			if (line.command == lb) {
				if (!line.ad_type) {
					int pos = reg[line.ad_reg] + line.ad_dig;
					memcpy(&reg[line.Rdest], vir_mem + pos, 1);
					n++;
					continue;
				}
				else {
					int pos = database->operator[](line.label_name);
					memcpy(&reg[line.Rdest], vir_mem + pos, 1);
					n++;
					continue;
				}
			}
			if (line.command == lh) {
				if (!line.ad_type) {
					int pos = reg[line.ad_reg] + line.ad_dig;
					memcpy(&reg[line.Rdest], vir_mem + pos, 2);
					n++;
					continue;
				}
				else {
					int pos = database->operator[](line.label_name);
					memcpy(&reg[line.Rdest], vir_mem + pos, 2);
					n++;
					continue;
				}
			}
			if (line.command == lw) {
				if (!line.ad_type) {
					int pos = reg[line.ad_reg] + line.ad_dig;
					memcpy(&reg[line.Rdest], vir_mem + pos, 4);
					n++;
					continue;
				}
				else {
					int pos = database->operator[](line.label_name);
					memcpy(&reg[line.Rdest], vir_mem + pos, 4);
					n++;
					continue;
				}
			}
			if (line.command == sb) {
				if (line.ad_type) {
					int pos = database->operator[](line.label_name);
					memcpy(vir_mem + pos, &reg[line.Rsrc], 1);
					n++;
					continue;
				}
				else {
					int pos = reg[line.ad_reg] + line.ad_dig;
					memcpy(vir_mem + pos, &reg[line.Rsrc], 1);
					n++;
					continue;
				}
			}
			if (line.command == sh) {
				if (line.ad_type) {
					int pos = database->operator[](line.label_name);
					memcpy(vir_mem + pos, &reg[line.Rsrc], 2);
					n++;
					continue;
				}
				else {
					int pos = reg[line.ad_reg] + line.ad_dig;
					memcpy(vir_mem + pos, &reg[line.Rsrc], 2);
					n++;
					continue;
				}
			}
			if (line.command == sw) {
				if (line.ad_type) {
					int pos = database->operator[](line.label_name);
					memcpy(vir_mem + pos, &reg[line.Rsrc], 4);
					n++;
					continue;
				}
				else {
					int pos = reg[line.ad_reg] + line.ad_dig;
					//cout << reg[line.ad_reg] << line.ad_dig << endl;;
					memcpy(vir_mem + pos, &reg[line.Rsrc], 4);
					n++;
					continue;
				}
			}
			if (line.command == mov) {
				reg[line.Rdest] = reg[line.Rsrc];
				n++;
				continue;
			}
			if (line.command == mfhi) {
				reg[line.Rdest] = reg[32];
				n++;
				continue;
			}
			if (line.command == mflo) {
				reg[line.Rdest] = reg[33];
				n++;
				continue;
			}
			if (line.command == nop) {
				n++;
				continue;
			}
			if (line.command == syscall) {
				if (reg[2] == 1) {
					cout << reg[4];
					n++;
					continue;
				}
				if (reg[2] == 4) {
					//cout << "shit" << endl;
					cout << vir_mem + reg[4];
					n++;
					continue;
				}
				if (reg[2] == 5) {
					cin >> reg[2];
					n++;
					continue;
				}
				if (reg[2] == 8) {
					string str;
					cin >> str;
					char* pos = vir_mem + reg[4];
					int x;
					if (str.size() <= (reg[5] + 1)) x = str.size();
					else x = reg[5] + 1;
					memcpy(pos, &str, x);
					n++;
					continue;
				}
				if (reg[2] == 9) {
					int x = reg[4];
					reg[2] = heap_seg - vir_mem;
					heap_seg += x;
					while ((heap_seg - vir_mem) % 4 != 0) {
						heap_seg += 1;
					}
					n++;
					continue;
				}
				if (reg[2] == 10) {
					system("PAUSE");
					exit(0);
					n++;
					continue;
				}
				if (reg[2] == 17) {
					system("PAUSE");
					exit(reg[4]);
					n++;
					continue;
				}
			}
		}
	}
};