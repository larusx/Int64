#include <iostream>
#include <cstdlib>
extern "C"{
	#include "Int64.h"
}
using namespace std;

Int64 set(long long int a)
{
	Int64 ret;
    int* p = (int*)(&a);
    ret.low = *p++;
    ret.hi = *p;
	return ret;
}

long long int get (Int64 x)
{
    union
    {
        long long int a;
        int p[2];
    };
    p[0] = x.low;
    p[1] = x.hi;
    return a;
}

void test (long long int a, long long int b)
{
	Int64 m, n;
	m = set(a);
	n = set(b);

	cout << a << " vs " << b << endl << endl;
	if (a+b != get(Int64_plus(m, n)))
		cout << a+b << ":" << get(Int64_plus(m, n)) << endl << "Error!" << endl << endl;
	else
		cout << a+b << endl << "OK" << endl << endl;
	if (a-b != get(Int64_minus(m, n)))
		cout << a-b << ":" << get(Int64_plus(m, n)) << endl << "Error!" << endl << endl;
	else
		cout << a-b << endl << "OK" << endl << endl;
	if (a*b != get(Int64_multi(m, n)))
		cout << a*b << ":" << get(Int64_plus(m, n)) << endl << "Error!" << endl << endl;
	else
		cout << a*b << endl << "OK" << endl << endl;
	if (a/b != get(Int64_div(m, n)))
		cout << a/b << ":" << get(Int64_plus(m, n)) << endl << "Error!" << endl << endl;
	else
		cout << a/b << endl << "OK" << endl << endl;
}

int main()
{
	test (1, -1);
	test (0, 1);
	test (35, 30);
	test (60, 30);
	test (1000, 34);
	test (-234872, 8742);
	test (0x70000000000, 0x80000001);
	test (0x398748297342, 0x7FFFFFFF);
	test (0x70000000000, 0x98374234);
	test (0x34627834687, 0x83648924);
	test (0xFF80000000000000, 0x8000000000);
	test (-4, -1);
	test (0xFFF2394729834342, 0xFF34257438453824);
	test (2985952495825, 22525398235235);
}