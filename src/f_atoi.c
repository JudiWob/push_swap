#include "header.h"

int f_atoi(const char *s, int *data)
{
	int i;
	int sign;

	sign = 1;
	*data = 0;
	i = 0;
	while (s[i])
	{
		if(s[i] == '-')
		{
			sign = -1;
			i++;
		}	
		if(s[i] < '0' || s[i] > '9')
		{
			printf("false character\n");
			return (0);
		}	
		*data = ((*data) * 10) + (s[i] - 48);
		i++;
	}
	*data = *data * sign;
	return (1);
}

//int main()
//{
//	f_atoi("223");
//}