#include "monty.h"

/**
  * modS - sub the two top numbers of a stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */

void modS(stack_t **st_stack, unsigned int linu)
{
	stack_t *save;
	int i;

	if (*st_stack != NULL && (*st_stack)->next != NULL)
	{
		if ((*st_stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", linu);
			exit(EXIT_FAILURE);
		}

		i = ((*st_stack)->next->n) % ((*st_stack)->n);
		save = (*st_stack)->next;
		free(*st_stack);
		save->n = i;
		save->prev = NULL;
		*st_stack = save;
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", linu);
		exit(EXIT_FAILURE);
	}
}
