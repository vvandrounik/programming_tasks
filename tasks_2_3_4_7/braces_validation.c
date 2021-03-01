#include <stdlib.h>

#include "braces_validation.h"
#include "stack.h"

static bool is_open_brace(char value)
{
	return value == '('
		|| value == '{'
		|| value == '[';
}

static bool is_close_brace(char value)
{
	return value == ')'
		|| value == '}'
		|| value == ']';
}

static bool is_pair(char open, char close)
{
	if (open == '(' && close == ')')
		return true;
	else if (open == '{' && close == '}')
		return true;
	else if (open == '[' && close == ']')
		return true;

	return false;
}

bool is_valid(const char* str)
{
	stack_t* stack = stack_create();
	
	while (*str != '\0')
	{
		if (is_open_brace(*str))
		{
			stack_push(stack, (void*)str);
		}
		else if (is_close_brace(*str))
		{
			node_t* top = stack_top(stack);
			if (top == NULL || !is_pair(*(char*)(top->data), *str))
			{
				return false;
			}
			else
			{
				stack_pop(stack);
			}
		}
		++str;
	}

	stack_destroy(stack);

	return true;
}
