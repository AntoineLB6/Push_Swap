/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:39:52 by aleite-b          #+#    #+#             */
/*   Updated: 2023/12/14 09:51:57 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_push_swap
{
	long				nb;
	struct s_push_swap	*next;
}	t_push_swap;

int			check_doublons(t_push_swap **nbrs, char *str);
int			lst_init(t_push_swap **lst, char *str);
t_push_swap	*lst_new(long nb);
t_push_swap	*ft_lstlast(t_push_swap *lst);
void		ft_lstadd_back(t_push_swap **lst, t_push_swap *elem);
int			ft_lstsize(t_push_swap *lst);
long		ft_atoi(const char *nbr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		free_lst(t_push_swap **lst);

int			get_strnbrs(t_push_swap **nbrs, char *argv);
int			get_argsnbrs(int argc, char **argv, t_push_swap **nbrs);
int			get_args(int argc, char **argv, t_push_swap **nbrs);

void		sa(t_push_swap **stack, int wr);
void		sb(t_push_swap **stack, int wr);
void		ss(t_push_swap **stack_a, t_push_swap **stack_b, int wr);
void		pa(t_push_swap **stack_a, t_push_swap **stack_b, int wr);
void		pb(t_push_swap **stack_a, t_push_swap **stack_b, int wr);
void		ra(t_push_swap **stack, int wr);
void		rb(t_push_swap **stack, int wr);
void		rr(t_push_swap **stack_a, t_push_swap **stack_b, int wr);
void		rra(t_push_swap **stack, int wr);
void		rrb(t_push_swap **stack, int wr);
void		rrr(t_push_swap **stack_a, t_push_swap **stack_b, int wr);

int			is_sorted(t_push_swap *lst);
long		get_min(t_push_swap **stack);
long		get_max(t_push_swap **stack);
int			get_index(t_push_swap **stack, long nb);
int			get_index_place_b(t_push_swap *stack, long nb);

void		sortb(t_push_swap **stack_a, t_push_swap **stack_b);
void		sort_three(t_push_swap **stack_a);
void		go_to_min(t_push_swap **stack, char pile);
void		sort_under_five(t_push_swap **stack_a, t_push_swap **stack_b);

int			rotate_calcul_b(t_push_swap **stack_a,
				t_push_swap **stack_b);
int			instr_to_rarb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			instr_to_rrarrb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			instr_to_rarrb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			instr_to_rrarb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);

int			do_rarb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			do_rrarrb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			do_rrarb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);
int			do_rarrb(t_push_swap **stack_a,
				t_push_swap **stack_b, long nb);

#endif