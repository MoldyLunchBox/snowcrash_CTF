int main(int argc, char **argv)

{
	int i = 0;
	char  c;

	while (argv[1][i] != 0)
	{
		c = argv[1][i];
		printf("%c", (argv[1][i] - i));
		i++;

	}
	printf("\n");
	return(0);
}
