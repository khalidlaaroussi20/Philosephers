/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:05:42 by klaarous          #+#    #+#             */
/*   Updated: 2021/11/12 15:27:24 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdigit(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*convertnegative(int n)
{
	int		digitsize;
	int		i;
	char	*convertedstr;

	digitsize = countdigit(n);
	convertedstr = malloc(digitsize + 2);
	if (!convertedstr)
		return (NULL);
	i = digitsize;
	convertedstr[i + 1] = '\0';
	while (i > 0)
	{
		convertedstr[i--] = -(n % 10) + '0';
		n /= 10;
	}
	convertedstr[0] = '-';
	return (convertedstr);
}

static char	*convertpositive(int n)
{
	int		digitsize;
	int		i;
	char	*convertedstr;

	digitsize = countdigit(n);
	if (digitsize == 0)
		digitsize++;
	convertedstr = malloc(digitsize + 1);
	if (!convertedstr)
		return (NULL);
	convertedstr[digitsize] = '\0';
	i = digitsize - 1;
	while (i >= 0)
	{
		convertedstr[i--] = n % 10 + '0';
		n /= 10;
	}
	return (convertedstr);
}

char	*ft_itoa(int n)
{
	if (n < 0)
		return (convertnegative(n));
	return (convertpositive(n));
}
