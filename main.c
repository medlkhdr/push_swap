#include "push_swap.h"

size_t replace_by_space(char *str)
{
    int i = 0;
    size_t count = 0;
    while (str[i])
    {
        if (str[i] >= 9 && str[i] <= 13)
        {
            str[i] = 32;
            count++;
        }
        i++;
    }
    return count;
}

void check(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '+' || str[i] == '-')
            i++;
        if (str[i] != 32 && !(str[i] >= '0' && str[i] <= '9'))
        {
            write(1 ,"ERROR\n" , 6);
            exit(1);
        }
        i++;
    }
}

char *join(int ac, char **av, size_t size)
{
    int i = 1;
    int j = 0;
    int k;
    char *str = malloc(sizeof(char) * (size + 1));
    if (!str) 
    {
        write(2, "Memory allocation failed\n", 24);
        exit(1);
    }
    
    while (i < ac)
    {
        k = 0;
        while (av[i][k])
        {
            str[j++] = av[i][k++];
        }
        str[j] = 32;
        j++;
        i++;
    }
    str[j] = '\0';
    return str;
}

int da7k(char *string, int *i)
{
    int j = 0;
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

int *parse_input(int ac, char **av, int *k)
{
    size_t sum = 0;
    int i = 1;
    while (i < ac)
    {
        sum += replace_by_space(av[i]);
        check(av[i]);
        i++;
    }
    char *all_of_them_here = join(ac, av, sum);
    da7k(all_of_them_here, k);
    
    int *arr = malloc(sizeof(int) * (*k));
    if (!arr)
    {
        free(all_of_them_here);
        write(2, "Memory allocation failed\n", 24);
        exit(1);
    }
    
    i = 0;
    int a = 0;
    int c = 0;
    int sign ;
    while (all_of_them_here[i])
    {
        sign =1 ;
        while (all_of_them_here[i] == 32)
            i++;
        c = 0;
        if(all_of_them_here[i] == '+' || all_of_them_here[i] == '-')
        {
            if(all_of_them_here[i] == '-')
                sign = -1;
            i++;
        }
        while (all_of_them_here[i] >= '0' && all_of_them_here[i] <= '9')
        {
            c = c * 10 + (all_of_them_here[i] - '0');
            i++;
        }
        arr[a++] = c*sign;
    }
    free(all_of_them_here);
    return arr;
}

void is_here_dup(int *a, int k)
{
    int i = 0;
    while (i < k - 1)
    {
        int j = i + 1;
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
// void sort_it(int *ar , int k)
// {
//             3awd lkrk rh baqi mlqitch sort li nkhdm biha 
// }

void afficher(int *a , int k )
{
    for(int i = 0 ; i < k ; i++)
    {
        printf("%d : %d" , i  , a[i]);
        printf("\n----\n");
    }
}
int main(int ac, char **av)
{
    if (ac < 2)
        return 0;
    
    if (av[1][0] == '\0')
    {
        write(2, "ERROR:\n", 7);
        exit(1);
    }
    
    int k = 0;
    int *ar = parse_input(ac, av, &k);
    is_here_dup(ar, k);
    //sort_it(ar, k);
    afficher(ar , k);
    free(ar);
    return 0;
}
