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
	stack_t* stack = NULL;
	create(&stack);

	while (*str != '\0')
	{
		if (is_open_brace(*str))
		{
			push(stack, (void*)str);
		}
		else if (is_close_brace(*str))
		{
			if (top(stack) == NULL || !is_pair(*(char*)top(stack), *str))
			{
				return false;
			}
			else
			{
				pop(stack);
			}
		}
		++str;
	}

	destroy(stack);

	return true;
}
