
#include "ft_printf.h"

int	get_nbrlen(long n)
{
	int		len;
	long	nbr;

	nbr = n;
	len = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(long n)
{
	char	c;

	if (n < 0)
		n = n * -1;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		c = '0' + n % 10;
		write(1, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}
