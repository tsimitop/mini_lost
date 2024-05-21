#include "minishell.h"

bool	builtin_case(t_token *iterate)
{
	if (iterate && iterate->token_type == WORD && \
	ft_is_builtin(get_first_word(iterate->content)) == true)
	{
		// printf("TRUE\n");
		return (true);
	}
// printf("iterate->content = %s\n", iterate->content);
	// printf("FALSE\n");
	return (false);
}

bool	empty_cmd_case(t_token *iterate, t_command *cmd_node)
{
	if (iterate && (iterate->token_type == WORD || iterate->token_type == D_QUOTE \
	|| iterate->token_type == S_QUOTE) && (cmd_node->cmd == NULL || \
	cmd_node->cmd[0] == '\0') && iterate->token_type != PIPE)
		return (true);
	return (false);
}

bool	full_cmd_case(t_token *iterate, t_command *cmd_node)
{
	if (iterate && (iterate->token_type == WORD \
	|| iterate->token_type == D_QUOTE || iterate->token_type == S_QUOTE) \
	&& cmd_node->cmd != NULL && cmd_node->cmd[0] != '\0' && \
	iterate->token_type != PIPE)
		return (true);
	return (false);
}