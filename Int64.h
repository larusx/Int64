#ifndef _INT64_H
#define _INT64_H
//�ṹ�嶨��
typedef struct Int64 {
	int low;
	int hi;
}Int64;

//��Ҫʹ�õ��ĸ�����
////////////////////////////////////////////////
Int64 Int64_plus (Int64 left, Int64 right);

Int64 Int64_minus (Int64 left, Int64 right);

Int64 Int64_multi (Int64 left, Int64 right);

Int64 Int64_div (Int64 left, Int64 right);
////////////////////////////////////////////////

//�ڲ����õĺ��������ÿ�
////////////////////
int sign (Int64 num);
Int64 neg (Int64 num);
int N_less (Int64 *left, Int64 *right);
void N_div_2 (Int64 *num);
////////////////////
#endif

