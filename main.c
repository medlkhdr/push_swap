#include "push_swap.h"

void	replace_by_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 9 && str[i] <= 13)
		{
			str[i] = 32;
		}
		i++;
	}
}

void	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] != 32 && !(str[i] >= '0' && str[i] <= '9'))
		{
			write(1, "ERROR\n", 6);
			exit(1);
		}
		i++;
	}
	i  = 0 ;
	while(str[i] == 32)
		i++;
	if(str[i] == '\0')
	{
		write(1, "ERROR" ,5);
		exit(1);
	}
}

char	*join(int ac, char **av, size_t size)
{
	int		i = 1, j;
    int k;
	char	*str;

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

int	da7k(char *string, int *i)
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
	const char	*ptr;

	if(s[0] == '\0')
	{
		write(1 ,"ERROR\n" , 6);
		exit(1);
	}


	ptr = s;
	while (*ptr)
	{
		ptr++;
	}
	return ((size_t)(ptr - s));
}

int	*parse_input(int ac, char **av, int *k)
{
	size_t	sum;
	int		i;
	char	*all_of_them_here;
	int		*arr;
	int		a;
	int		c;
	int		sign;

	sum = 0;
	i = 1;
	while (i < ac)
	{
		sum += ft_strlen((const char *)av[i]) + 1;
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
	i = 0;
	a = 0;
	c = 0;
	while (all_of_them_here[i])
	{
		sign = 1;
		while (all_of_them_here[i] == 32)
			i++;
		c = 0;
		if (all_of_them_here[i] == '+' || all_of_them_here[i] == '-')
		{
			if (all_of_them_here[i] == '-')
				sign = -1;
			i++;
		}
		while (all_of_them_here[i] >= '0' && all_of_them_here[i] <= '9')
		{
			c = c * 10 + (all_of_them_here[i] - '0');
			i++;
		}
        c = c * sign;
	    if (c > 2147483647|| c < -2147483648)
		{
			free(all_of_them_here);
			free(arr);
			write(1, "ERROR\n", 6);
			exit(1);
		}
		arr[a++] = c ;
	}
	free(all_of_them_here);
	return (arr);
}

void	is_here_dup(int *a, int k)
{
	int	i;
	int	j;

	i = 0;
	while (i < k - 1)
	{
		j = i + 1;
		while (j < k)
		{
			if (a[i] == a[j])
			{
				free(a);
				write(2, "ERROR\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void merge(int *arr, int left, int mid, int right)
{
    int i = 0, j = 0, k = left;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (!L || !R)
    {
        write(2, "Memory allocation failed\n", 24);
        exit(1);
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0, j = 0;

    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void sort_it(int *ar, int k)
{
    merge_sort(ar, 0, k - 1);
}

void	afficher(int *a, int k)
{
	for (int i = 0; i < k; i++)
	{
		printf("%d : %d", i, a[i]);
		printf("\n----\n");
	}
}

int	main(int ac, char **av)
{
	int	k;
	int	*ar;

	if (ac < 2)
		return (0);
	if (av[1][0] == '\0')
	{
		write(2, "ERROR:\n", 7);
		exit(1);
	};
	k = 0;
	ar = parse_input(ac, av, &k);
	is_here_dup(ar, k);
    printf("not sorted\n");
    afficher(ar,  k);
	sort_it(ar, k);
    printf("sorted\n");
	afficher(ar, k);
	free(ar);
	return (0);
}
