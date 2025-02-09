#include "push_swap.h"

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
			write(1, "Error", 5);
			exit(1);
		}
		i++;
	}
	while (*str == 32)
		str++;
	if (*str == '\0')
	{
		write(1, "Error", 5);
		exit(1);
	}
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

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	if (s[0] == '\0')
	{
		write(1, "Error", 5);
		exit(1);
	}
	while (*ptr)
		ptr++;
	return ((size_t)(ptr - s));
}

void	handle_overflow(int *a, char *b)
{
	free(a);
	free(b);
	write(1, "Error", 5);
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

int	is_sorted(int *a, int k)
{
	for (int i = 0; i < k - 1; i++)
	{
		if (a[i] > a[i + 1])
			return (0);
	}
	return (1);
}
int	main(int ac, char **av)
{
	int	k;
	int	*ar;
	stack_t	*stacka;
	stack_t	*stackb;

	k = 0;
	if (ac < 2)
		return (0);
	if (av[1] == NULL)
	{
		write(2, "Error", 5);
		exit(1);
	}
	ar = parse_input(ac, av, &k);
	is_here_dup(ar, k);
	stackb = initialize_stack();
	stacka = fill_stack(ar, k);
	int size = stack_size(stacka);
    if (size == 2) 
		sort_2(stacka);
    else if (size == 3) 
		sort_3(stacka);
    else if (size <= 5) 
		sort_5(stacka, stackb);
    else
		printf("baqi\n");
	free_stack(stacka);
	free_stack(stackb);
	free(ar);
	return (0);
}
