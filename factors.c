#include "factors.h"
/**
 * factorize - The function factorize a number
 * @buff: pointer to the address of the number
 *
 * Author: Thaoban Abdrasheed
 * Return: int
 */
int factorize(char *buff)
{

	int num;
	int i;

	num = atoi(buff);


	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			printf("%d=%d*%d\n", num, num/i, i);
			break;
		}
	}

return (0);
}
/**
 * main - main function
 *
 *
 * Return: void
 */
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
		factorize(buff);
	}
return (0);
}
