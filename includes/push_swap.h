/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gangouil <gangouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:59:58 by gangouil          #+#    #+#             */
/*   Updated: 2024/02/29 13:41:25 by gangouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}				t_stack;

t_stack	*ft_lstnew(int content, t_stack *next);
t_stack	*ft_lstlast(t_stack *stack);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
void	ft_lstclear(t_stack *stack);
int		ft_lstsize(t_stack *stack);
void	sa(t_stack *a, int display);
void	sb(t_stack *b, int display);
void	ss(t_stack *a, t_stack *b, int display);
void	pa(t_stack **a, t_stack **b, int display);
void	pb(t_stack **a, t_stack **b, int display);
void	ra(t_stack **a, int display);
void	rb(t_stack **b, int display);
void	rr(t_stack **a, t_stack **b, int display);
void	rra(t_stack **a, int display);
void	rrb(t_stack **b, int display);
void	rrr(t_stack **a, t_stack **b, int display);
int		parsing(char *args, t_stack **stack);
int		index_stack(t_stack *stack);
void	a_to_b(t_stack **a, t_stack **b, int chunk, int max);
void	small_stack(t_stack *a, t_stack *b);
char	*get_next_line(int fd);
void	two_stack(t_stack **a);
void	three_stack(t_stack **a);
void	four_stack(t_stack **a, t_stack **b);
void	five_stack(t_stack **a, t_stack **b);
int		is_max_top(t_stack *b, int max, int check);
int		ft_strlen(const char *s);
char	*get_args(int argc, char **argv);
int		is_sorted(t_stack *stack);
int		ft_printf(const char *str, ...);

#endif
