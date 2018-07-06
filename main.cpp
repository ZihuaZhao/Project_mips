#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<map>
#include<stdlib.h>
#include"line_keeper.hpp"
#include"parser.hpp"
#include"scanner.hpp"
#include"constant.hpp"
#include"execution.hpp"

int main(){
    char* vir_mem = (char*)malloc(4*1024*1024);
	char* static_seg = vir_mem;
	char* heap_seg = vir_mem;
	char* stack_seg = vir_mem + 4 * 1024 * 1024;
	map<string, int> funcbase;
	map<string, int> database;
	vector<line_keeper> linebase;
	int mainpos = 0;
	int* reg = new int[34];
	parser p("array_test1-mahaojun.s", vir_mem, static_seg, heap_seg, stack_seg, 
		linebase, funcbase, database , reg , mainpos);
	int x = 1;
    while(p.pre_deal()){}
	execution exe(vir_mem, static_seg, stack_seg, heap_seg, database,
		funcbase, linebase, mainpos, reg);
	exe.execute();
	delete reg;
    free(vir_mem);
	system("PAUSE");
    return 0;
}