#include "push_swap.h"


void	handle_overflow(int *a, char *b)
{
	free(a);
	free(b);
	message();
	exit(1);
}

int	*parse_input(int ac, char **av, int *k)
{
	size_t	sum;
	int		i;
	char	*all_of_them_here;
	int		*arr;

	sum = 0;
	i = 1;
	while (i < ac)
	{
		sum += ft_strlen(av[i]) + 1;
		replace_by_space(av[i]);
		check(av[i]);
		i++;
	}
	all_of_them_here = join(ac, av, sum);
	da7k(all_of_them_here, k);
	arr = malloc(sizeof(int) * (*k));
	if (!arr)
	{
		free(all_of_them_here);
		write(2, "Memory allocation failed\n", 24);
		exit(1);
	}
	parse_numbers(all_of_them_here, arr);
	free(all_of_them_here);
	return (arr);
}

void	parse_numbers(char *input, int *arr)
{
	int	i,a, c , sign;
	i = 0, a = 0;
	while (input[i])
	{
		sign = 1;
		while (input[i] == ' ')
			i++;
		if (input[i] == '+' || input[i] == '-')
		{
			if (input[i] == '-')
				sign = -1;
			i++;
		}
		c = extract_number(input, &i, arr);
		c *= sign;
		arr[a++] = c;
	}
}


int	extract_number(char *input, int *i, int *arr)
{
	int	c;

	c = 0;
	while (input[*i] >= '0' && input[*i] <= '9')
	{
		if (c > INT_MAX / 10 || (c == INT_MAX / 10 && (input[*i]
					- '0') > INT_MAX % 10))
			handle_overflow(arr, input);
		c = c * 10 + (input[*i] - '0');
		(*i)++;
	}
	return (c);
}
void	is_here_dup(int *a, int k)
{
	int i = 0, j;
	while (i < k - 1)
	{
		j = i + 1;
		while (j < k)
		{
			if (a[i] == a[j])
			{
				free(a);
				write(2, "Error", 5);
				exit(1);
			}
			j++;
		}
		i++;
	}
	if (is_sorted(a, k))
	{
		free(a);
		exit(0);
	}
}
