#include<iostream>
#include<cctype>
#include<string>
#include<map>
#include<vector>
#include"scanner.hpp"
#include"parser.hpp"
#include"line_keeper.hpp"
#include"constant.hpp"
#include"execution.hpp"

using namespace std;
char vir_mem[4 * 1024 * 1024];

int main() {
	memset(&vir_mem[0], 0, 4 * 1024 * 1024);
	int static_seg = 0;
	int heap_seg = 0;
	int stack_seg = 4 * 1024 * 1024 - 1;
	map<string, int> funcbase;
	map<string, int> database;
	vector<line_keeper> linebase;
	int mainpos;
	int reg[34];
	memset(reg, 0, 34*sizeof(int));
	reg[29] = 4 * 1024 * 1024 - 1;
	parser p("heapsort-5100379110-daibo.s");
	int x = 1;
	while (p.pre_deal(&database, &funcbase, &linebase,
		reg, mainpos, vir_mem, static_seg, heap_seg, stack_seg ,x)) {
		x++;
		if (x == 628) {
			int sjckn = 0;
		}
	}
	/*for (int i = 0; i < linebase.size(); ++i) {
		linebase[i].out000();
	}*/
	execution e;
	e.execute(&database, &funcbase, &linebase,
		reg, mainpos, vir_mem, static_seg, heap_seg, stack_seg);
	return 0;
}