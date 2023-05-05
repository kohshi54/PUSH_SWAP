#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <unistd.h>


# include "LIBFT/libft.h"
# include "LIBFT/ft_printf.h"


typedef struct stack
{
   int num;
   struct stack *next;
   struct stack *prev;
}   t_stack;


// t_stack *swap(t_stack *list);
void	swap(t_stack **list);

// void	push(t_stack *list_a, t_stack *list_b);
void	push(t_stack **list_a, t_stack **list_b);

// t_stack *rotate(t_stack *list);
void	rotate(t_stack **list);

// t_stack *reverse_rotate(t_stack *list);
void	reverse_rotate(t_stack **list);


# endif

