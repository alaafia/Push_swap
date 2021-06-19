/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:02:27 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/19 14:49:21 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putnbr(int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar('-');
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar((char)(nbr % 10 + 48));
}
