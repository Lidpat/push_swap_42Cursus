/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:47:02 by lpalacio          #+#    #+#             */
/*   Updated: 2023/12/23 21:44:08 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bits_number(int	lst_size)
{
	if (lst_size <= 2)
		return (1);
	if (lst_size <= 4)
		return (2);
	if (lst_size <= 8)
		return (3);
	if (lst_size <= 16)
		return (4);
	if (lst_size <= 32)
		return (5);
	if (lst_size <= 64)
		return (6);		
	if (lst_size <= 128)
		return (7);
	if (lst_size <= 256)
		return (8);
	if (lst_size <= 512)
		return (9);
	if (lst_size <= 1024)
		return (10);
	return (16);
}

void	move_zero_right(t_list **lst_src, t_list **lst_dst, int bit)
{
	int		numb;
	int		bit_value;
	t_list	*aux;
	int stack_size;

	aux = *lst_src;
	stack_size = ft_lstsize(aux);
	while (stack_size--)
	{
		numb = ((int *)(aux->content))[position];
		bit_value = (numb >> bit) % 2;
		if (bit_value == 0)
		{
			push(lst_src, lst_dst);
			write (1, "pb\n", 3);
		}
		else //if (stack_size > 0)
		{	
			rotate(lst_src);
			write (1, "ra\n", 3);
		}
//		ft_putnbr_fd (numb, 1);
//		write (1, "\t", 1);
//		ft_putnbr_fd (bit_value, 1);
//		write (1, "\n", 1);
		//aux = aux->next;
		aux = *lst_src; 
	}
	
}

void	move_one_left(t_list **lst_src, t_list **lst_dst, int bit)
{
	int		numb;
	int		bit_value;
	t_list	*aux;
	int stack_size;

	aux = *lst_src;
	stack_size = ft_lstsize(aux);
	while (stack_size--)
	{
		numb = ((int *)(aux->content))[position];
		bit_value = (numb >> bit) % 2;
		if (bit_value == 1)
		{
			push(lst_src, lst_dst);
			write (1, "pa\n", 3);
		}
		else //if (stack_size > 0)
		{
			rotate(lst_src);
			write (1, "rb\n", 3);
		}
//		ft_putnbr_fd (numb, 1);
//		write (1, "\t", 1);
//		ft_putnbr_fd (bit_value, 1);
//		write (1, "\n", 1);
		//aux = aux->next;
		aux = *lst_src; 
	}
}

void	move_all_b(t_list **lst_src, t_list **lst_dst)
{
	int	stack_size;

	stack_size = ft_lstsize(*lst_src);
	while (stack_size--)
	{
		push(lst_src, lst_dst);
		write (1, "pa\n", 3);
	}
}

void	ps_sort_over100(t_list *stack_a, int stack_size)
{
	t_list	*stack_b;
	int		bit;
	int		bit_max;

	stack_b = NULL;
	bit = 0;
	bit_max = get_bits_number(stack_size);
	while(bit < bit_max)
	{
		if (bit == 0)
			move_zero_right(&stack_a, &stack_b, bit);
		else
		{
			move_one_left(&stack_b, &stack_a, bit);
			move_zero_right(&stack_a, &stack_b, bit);
		}
		bit++;
	}
	move_all_b(&stack_b, &stack_a);
}

int	push_swap (t_list *stack)
{
	int		stack_size;
	
	stack_size = ft_lstsize(stack);
	ps_sort_over100(stack, stack_size);

	return (0);
	
}

int main (int argc, char *argv[])
{
	t_list	*stack;
	int sort;

	stack = NULL;
	if (argc == 1)
		 return (-1);

	check_and_load(argv, &stack);
	check_duplicated_and_sort(stack);
	sort = is_sorted(stack);
	if (!sort)
		push_swap(stack);
	ft_lstclear(&stack, free);

		//move_mapping (*int[] instruction_list)   or print_instructions_list(*int )
	return (0);
}
