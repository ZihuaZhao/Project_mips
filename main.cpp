#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<map>
#include<stdlib.h>
#include"line_keeper.hpp"
#include"new_parser.hpp"
#include"scanner.hpp"
#include"constant.hpp"
#include"execution.hpp"

int main(){
    char* vir_mem = new char[4*1024*1024];
	memset(vir_mem, 0, 4 * 1024 * 1024 * sizeof(char));
	char* static_seg = vir_mem;
	char* heap_seg = vir_mem;
	char* stack_seg = vir_mem + 4 * 1024 * 1024 - 1;
	map<string, int> funcbase;
	map<string, int> database;
	vector<line_keeper> linebase;
	int mainpos = 0;
	int* reg = new int[34];
	memset(reg, 0, 34 * sizeof(int));
	reg[0] = 0;
	reg[29] = stack_seg - vir_mem;
	new_parser p("array_test1-mahaojun.s", &database ,&funcbase, &linebase , reg , &mainpos);
	int x = 0;
    while(p.pre_deal(vir_mem , static_seg , heap_seg , stack_seg)){
		x++;
		if (x == 3) {
			int xd = 0;
		}
	}

	execution exe(vir_mem, static_seg, stack_seg, heap_seg, &database,
		&funcbase, &linebase, &mainpos, reg);
	exe.execute();
	delete reg;
    free(vir_mem);
	system("PAUSE");
    return 0;
}