#include "Int64.h"

int sign (Int64 num) 
{
	if (num.hi < 0)
		return -1;
	else if ((num.hi == 0) && (num.low == 0))
		return 0;
	else
		return 1;
}

Int64 neg (Int64 num) 
{
	if (num.low == 0)
		num.hi = -num.hi;
	else
	{
		num.low = ~num.low + 1;
		num.hi = ~num.hi;
	}
	return num;
}

Int64 Int64_plus (Int64 left, Int64 right)
{
	Int64 ret;
	ret.low = 0;
	ret.hi = left.hi;
	ret.low = left.low + right.low;
	if ((unsigned int)ret.low < (unsigned int)right.low)
		++ret.hi;
	ret.hi += right.hi;
	return ret;
}

Int64 Int64_minus (Int64 left, Int64 right)
{
	return Int64_plus(left, neg(right));
}

Int64 Int64_multi (Int64 left, Int64 right)
{
	int s = sign(right);
	Int64 bin;
	int i;
	if (s == 0)
	{
		left.hi = left.low = 0;
		return left;
	}
	else if (sign(left) == 0)
		return left;

	
	if (s < 0)
		right = neg(right);
	if (sign(left) < 0)
	{
		bin = neg(left);
		s = -s;
	}
	else
		bin = left;
	left.hi = left.low = 0;
	for (i = 0; i < 32; ++i, right.low >>= 1, bin = Int64_plus(bin, bin))
		if ((right.low & 1) != 0)
			left = Int64_plus(left, bin);
	for (i = 0; i < 32; ++i, right.hi >>= 1, bin = Int64_plus(bin, bin))
		if ((right.hi & 1) != 0)
			left = Int64_plus(left, bin);
	if (s < 0)
		left = neg(left);
	return left;
}

int N_less (Int64 *left, Int64 *right)
{
	if (left->hi < right->hi)
		return 1;
	else if ((left->hi == right->hi) 
		&& ((unsigned int)left->low < (unsigned int)right->low))
		return 1;
	else
		return 0;
}

void N_div_2 (Int64 *num)
{
	num->low = (unsigned int)num->low >> 1;
	if (num->hi & 1)
		num->low |= 0x80000000;
	num->hi = (unsigned int)num->hi >> 1;
}

Int64 Int64_div (Int64 left, Int64 right)
{
	int s = sign(right);
	Int64 bin;
	int t = 0;
	Int64 one;
	one.low = 1;one.hi = 0;
	if (s == 0)
		return right;
	else if (sign(left) == 0)
		return left;
	if (s < 0)
		right = neg(right);
	
	if (sign(left) < 0)
	{
		bin = neg(left);
		s = -s;
	}
	else
		bin = left;
	left.low = left.hi = 0;

	
	while (!N_less (&bin, &right))
	{
		++t;
		right = Int64_plus(right, right);
	}
	
	for (; t > 0; --t)
	{
		N_div_2(&right);
		left = Int64_plus(left, left);
		if (!N_less (&bin, &right))
		{
			bin = Int64_minus(bin, right);
			left = Int64_plus(left, one);
		}
	}
	if (s < 0)
		left = neg(left);
	return left;
}