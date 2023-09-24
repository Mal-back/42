#include <unistd.h>

void fill_arr(int *puzzle)
{
    int i;

    i = 0;
    while (i < 10)
    {
        puzzle[i] = 0;
        i++;
    }
}

void putnbr(int n)
{
    char c;

    if (n > 9)
        putnbr(n / 10);
    c = n % 10 + 48;
    write(1, &c, 1);
}

void print_solve(int *puzzle)
{
    int i;

    i = 0;
    while (i < 10)
    {
        putnbr(puzzle[i]);
        i++;
    }
    write(1, "\n", 1);
}

int verif(int *puzzle, int location)
{
    int i;
    int j;

    i = location - 1;
    j = 1;
    while (i >= 0)
    {
    if (puzzle[i] == puzzle[location])
            return (0);
    else if (puzzle[i] == puzzle[location] - j || puzzle[i] == puzzle[location] + j)
        return (0);
    i--;
    j++;
    }
    return (1);
}

int rec(int *puzzle, int looked, int location, int *count)
{
    int i;

    i = 10;
    puzzle[location] = looked;
    if (puzzle[0] > 9)
        return (*count);
    while (i > puzzle[location])
    {
        if (verif(puzzle, location))
        {
            if (location != 9)
                rec(puzzle, puzzle[location + 1], location + 1, count);
            else 
            {
                print_solve(puzzle);
                *count += 1;
                puzzle[location]++;
            }
        }
        else
            puzzle[location]++;
    }
    puzzle[location] = 0;
    puzzle[location - 1]++;
    return (*count);
}

int main(void)
{
    int puzzle[10];
    int count;

    count = 0;
    fill_arr(puzzle);
    count = rec(puzzle, puzzle[0], 0, &count);
    putnbr(count);
    return (0);
}
