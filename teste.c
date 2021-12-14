#include <stdio.h>

int	is_space(char *string);

int main (void)
{
	char *teste  = "''CHAR''";

	is_space(teste);
	return 0;
}

int	is_space(char *string)
{
	int	index;
	int	status;

	index = 0;
	status = 0;
	while (string[index] != '\0')
	{
		if (string[index] == '\'')
		{
			status++;
		}
		index++;
	}
	printf("%d \n", status);
	if (status == 2 || status == 4)
		return (1);
	else
		return (0);
}
