#include "factors.h"

/**
 * factorize - func factorize a number and print its prime factors
 * @num: the number to factorize
 */
void factorize(long long int num)
{
    long long int i;

    printf("%lld=", num);

    for (i = 2; i <= num;)
    {
        if (num % i == 0)
        {
            printf("%lld", i);
            num /= i;
            if (num > 1)
                printf("*");
        }
        else
        {
            i++;
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    FILE *fptr;
    size_t count;
    ssize_t line;
    char *buff = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: factor <filename>\n");
        exit(EXIT_FAILURE);
    }
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((line = getline(&buff, &count, fptr)) != -1)
    {
        long long int num = atoll(buff);
        factorize(num);
    }

    if (buff)
        free(buff);

    fclose(fptr);

    return 0;
}
