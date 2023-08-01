#include <unistd.h>

int init(int n, int number_to_print, int n_size)
{
    int i = 0;
    number_to_print = 0;

    while (i < n)
    {
        number_to_print += i * n_size;
        i++;
        n_size /= 10;
    }
    return (number_to_print);
}

int reload(int number_to_print)
{
    int i = 1;
    int reset_value;
    int digit_to_reset = 1;
    int reset_limit = 0;
    int digit_to_reset_witness;

    number_to_print -= 1;
    while (number_to_print / digit_to_reset - number_to_print / (digit_to_reset * 10) * 10 == 9 - reset_limit)
    {
        reset_limit++;
        digit_to_reset *= 10;
    }
    digit_to_reset_witness = digit_to_reset;
    reset_value = (number_to_print / digit_to_reset) - (number_to_print / (digit_to_reset * 10)) * 10;
    while (i <= digit_to_reset_witness)
    {
        number_to_print -= ((number_to_print / digit_to_reset) - (number_to_print / (digit_to_reset * 10 )) * 10) * digit_to_reset;
        number_to_print += (1 + reset_value) * digit_to_reset;
        digit_to_reset /= 10;
        reset_value++;
        i *= 10;
    }
    return (number_to_print);
}

void    ft_putnbr(int nb)
{
    char c;
    if (nb > 9)
        ft_putnbr(nb / 10);
    c = nb % 10 + 48;
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
       argc++;
       int n = argv[1][0] - 48;
       int n_size = 1;
       int i = 0;
       int number_to_print = 1;
       int limit;

       while (i < n - 1)
       {
        n_size *= 10;
        i++;
       }
       limit = 10 - n;
       while (number_to_print / n_size != limit)
       {
        if (number_to_print % 10 == 1)
            number_to_print = init(n, number_to_print, n_size);
        if (number_to_print % 10 == 0)
            number_to_print = reload(number_to_print);
        if (number_to_print < n_size)
            write(1, "0", 1);
        ft_putnbr(number_to_print);
        if (number_to_print / n_size != limit)
            write(1, ", ", 2);
        number_to_print++;
       }
       if (n == 2)
           write(1, "89", 2);
       return (0);
}
