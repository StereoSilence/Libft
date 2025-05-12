int	ft_strlen(char *s)
{
	int	res;

	res = 0;
	while (s[res] != 0)
		res++;
	return (res);
}
