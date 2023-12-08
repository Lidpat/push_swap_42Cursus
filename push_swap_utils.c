/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:52:48 by lpalacio          #+#    #+#             */
/*   Updated: 2023/12/08 13:36:02 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//free malloc 2D   //variadric?
//

void	error_and_exit(int n)
{
	ft_putendl_fd("Error", 2);
	exit (n);
}


/* Check if string has valid length and characters to be an integer */
int	is_valid_str_for_int(char *str)
{
	int i;
	
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	if ((ft_strlen(str) - i) > 10)
		error_and_exit(1);;
	while (str[i])
	{
		if(!ft_isdigit(str[i]))  //Castear? BORRAR
			error_and_exit(1);
		i++;
	}
	return (1);
}

void	ft_putnbr_endl(void *num)
{
	ft_putnbr_fd(*(int *)(num), 1);
	write(1, "\n", 1);
	return ;
}