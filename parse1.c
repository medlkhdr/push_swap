#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	if (s[0] == '\0')
	{
        message();
		exit(1);
	}
	while (*ptr)
		ptr++;
	return ((size_t)(ptr - s));
}

int	is_sorted(int *a, int k)
{
	for (int i = 0; i < k - 1; i++)
	{
		if (a[i] > a[i + 1])
			return (0);
	}
	return (1);
}

char	*join(int ac, char **av, size_t size)
{
	char	*str;
	int		i,j,k;

	i = 1 ;
	i = 1, j = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
	{
		write(2, "Memory allocation failed\n", 24);
		exit(1);
	}
	while (i < ac)
	{
		k = 0;
		while (av[i][k])
			str[j++] = av[i][k++];
		if (i < ac - 1)
			str[j++] = 32;
		i++;
	}
	str[j] = '\0';
	return (str);
}

void	da7k(char *string, int *i)
{
	int	j;

	j = 0;
	while (string[j])
	{
		while (string[j] == 32)
			j++;
		if (string[j] >= '0' && string[j] <= '9')
		{
			(*i)++;
			while (string[j] >= '0' && string[j] <= '9')
				j++;
		}
		else
			j++;
	}
}
