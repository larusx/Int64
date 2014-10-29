#ifndef _INT64_H
#define _INT64_H
//结构体定义
typedef struct Int64 {
	int low;
	int hi;
}Int64;

//主要使用的四个函数
////////////////////////////////////////////////
Int64 Int64_plus (Int64 left, Int64 right);

Int64 Int64_minus (Int64 left, Int64 right);

Int64 Int64_multi (Int64 left, Int64 right);

Int64 Int64_div (Int64 left, Int64 right);
////////////////////////////////////////////////

//内部调用的函数，不用看
////////////////////
int sign (Int64 num);
Int64 neg (Int64 num);
int N_less (Int64 *left, Int64 *right);
void N_div_2 (Int64 *num);
////////////////////
#endif

