
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>



/*9. Print the exponent of a prime number p from the decomposition in prime factors of a
given number N = 1*2*...*n (n is a non-null natural number).*/



void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i = i + 1;
	}
}

void	ft_putnbr(int n)
{
	int		nbr_print;

	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar('0' + n);
	else
	{
		nbr_print = n % 10;
		ft_putnbr(n / 10);
		ft_putchar('0' + nbr_print);
	}
}






int exponent_of_prime(int x, int y)
{
	int d;
	int k;
	int z;
	int cpx;
	int count;

	count = 0;
	z = 1;
	while(z <= x)
	{
		cpx = z;
		d = 2;
		k = 0;
		while(cpx != 1)
		{
			while(cpx % d == 0)
			{
				k++;
				cpx = cpx / d;
			}
			if(k)
			{
				if(d == y)
					count += k;
			}
			d++;
			k = 0;
		}
		z++;
	}
	return (count);
}

int main()
{
	int z;
	int a;
	int exponent;

	exponent = 0;
	z = 0;
	ft_putstr("Give a prime number: ");
	scanf("%d", &a);
	ft_putstr("n: ");
	scanf("%d", &z);
	exponent = exponent_of_prime(z, a);
	printf("%s%d%s%d%s%d\n", "The exponent of ", a, " in ", z, " is: ", exponent);
	return (0);
}
