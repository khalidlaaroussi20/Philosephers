/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:24:15 by klaarous          #+#    #+#             */
/*   Updated: 2021/11/11 21:38:27 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

static void	write_number(int n, int fd)
{
	char			currentnb;
	long long int	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb == 0)
		return ;
	write_number(nb / 10, fd);
	currentnb = (nb % 10) + 48;
	write(fd, &currentnb, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n == 0)
			write(fd, "0", 1);
		else
			write_number(n, fd);
	}
}
