#include <stdio.h>
#include <malloc.h>

void add_fish_pp(int** pp);
int* add_fish_p(int* p);

int main()
{
	int* p = nullptr;
	add_fish_pp(&p);
	p = add_fish_p(p);

	return 0;
}

void add_fish_pp(int** p)
{
	*p = (int*)malloc(sizeof(int));
}

int* add_fish_p(int* p)
{
	p = (int*)malloc(sizeof(int));
	return p;
}