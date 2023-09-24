#include <unistd.h>
#include <stdio.h>


/*Convert the given number in hexa, put output a fix number of digits. So if you give 255 in 4 digits, 
 * the output would be 00ff, so you can padd you're output.'*/
void    ft_putnbr_hexa(unsigned long long p, int i, int limit)
{
    char *hexa;

    hexa = "0123456789abcdef";
    if (i < limit)
        ft_putnbr_hexa(p / 16, i + 1, limit);
    write(1, &hexa[p % 16], 1);
}

/*output a string and replace non-printable char by ".", also if you reach the end of what you wanna print,
 * specified by 'n', won't continue, but will stop a 16 char if n is not reached.'*/
void    ft_putstr(char *str, unsigned int i, unsigned int n)
{
    unsigned int    j;

    j = 0;
    write(1, " " , 1);
    while (i < n && j < 16)
    {
        if (str[j] < 32 || str[j] > 126)
            write(1, ".", 1);
        else
            write(1, &str[j], 1);
        i++;
        j++;
    }
    write(1, "\n", 1);
}
/*While n is not reach, will open a new line every 16 char, starting by the memory adress of
 * the first byte of the line followed by ':'. He will then output every char hexa value by 
 * groups of two, separated by spaces. If n is reach in the second loop, he will continue print
 * spaces in order tho maintain a proper padding*/
void    *ft_print_memory(void *addr, unsigned int size)
{
    unsigned long long  to_print_hexa;
    unsigned long long  i;
    unsigned long long  j;

    i = 0;
    to_print_hexa = (unsigned long long) addr;
    while (i < size)
    {
        ft_putnbr_hexa(to_print_hexa + i, 0, 15);
        write(1, ":", 1);
        j = 0;
        while (j < 16)
        {
            if (j % 2 == 0)
                write(1, " ", 1);
            if (i < size)
                ft_putnbr_hexa(to_print_hexa + i, 0, 1);
            else
                write(1, "  ", 2);
            j++;
            i++;
        }

        ft_putstr(&((char *)addr)[i - j], i - j, size);
    }
    return (addr);
}

int main(void)
{
    char *c = "cest pas grave c\nest ri\tgolo loliloliolioli";
    char *ptr = c;
    unsigned int size = 0;

    ft_print_memory(ptr, size);
    return (0);
}
