#include"push_swap.h"


void	replace_by_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 9 && str[i] <= 13)
			str[i] = 32;
		i++;
	}
}

void	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && !(str[i - 1] >= '0' && str[i
				- 1] <= '9'))
			i++;
		if (str[i] != 32 && !(str[i] >= '0' && str[i] <= '9'))
		{
            message();
			exit(1);
		}
		i++;
	}
	while (*str == 32)
		str++;
	if (*str == '\0')
	{
        message();
		exit(1);
	}
}
