#include "header.h"

int f_atoi(const char *s)
{
	int i;
	int num;
	int sign;

	sign = 1;
	num = 0;
	i = 0;

	while (s[i])
	{
		if(s[i] == '-')
		{
			sign = -1;
			i++;
		}	
		if(s[i] < '0' || s[i] > '9')
			return (-1);
		num = (num * 10) + (s[i] - 48);
		i++;
	}

	return (sign * num);
}

//int main()
//{
//	f_atoi("223");
//}