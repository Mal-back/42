#include <unistd.h>
/* While whe don't have initialized all the numbers, defined by n, we will initialized all the digits of the comb by multiplying by i * n_size. i will increment 
 * over each llop and n_size , who will worth 1000 for n= 4 as example, will be divided by ten . So for n=4 the first comb will be 123, with a if in while to print
 * the zero if needed.*/
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
/* first loop will calculate who mqny digit are to their "max", which is 9 - theur place in the comb. Then reset value which correspond to the value of the 
 * last digits that we don't need to reset + 1, is calculated. While the second loops run, digits are reset to the good value. The reset_value is incremented in every
 * iteration and the digit_to_reset is divided by 10, in order to move one digit to the right in the comb.*/
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

int secure_input(int argc, char **argv)
{
    int i = 0;
    if (argc != 2)
        return (0);
    while(argv[1][i])
        i++;
    if (i != 1)
        return (0);
    if (argv[1][0] < 49 || argv[1][0] > 57 )
        return (0);
    return (argv[1][0] - 48);
}
/* While it remains comb to print, iterate. if last digits is -1, means it's the first iteration and first comb to print must be defined.
 * if last digit is equal to 0, it means it's necessary to reset at list the last digit of the comb.
 * Special case if there is only to digit to print, cuz the last one , 89, won't be print.*/
int main(int argc, char **argv)
{
       int n = secure_input(argc, argv);
       if (n == 0)
           return (1);
       int n_size = 1;
       int i = 0;
       int number_to_print = -1;
       int limit;

       while (i < n - 1)
       {
        n_size *= 10;
        i++;
       }
       limit = 10 - n;
       while (number_to_print / n_size != limit)
       {
        if (number_to_print == -1)
            number_to_print = init(n, number_to_print, n_size);
        if (number_to_print % 10 == 0)
            number_to_print = reload(number_to_print);
        if (number_to_print < n_size && number_to_print != 0)
            write(1, "0", 1);
        ft_putnbr(number_to_print);
        if (number_to_print / n_size != limit)
            write(1, ", ", 2);
        number_to_print++;
       }
       if (n == 1)
        ft_putnbr(number_to_print);
       if (n == 2)
           write (1, "89", 2);
       return (0);
}
