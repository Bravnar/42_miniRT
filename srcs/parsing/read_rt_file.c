# include "main.h"

typedef struct s_parse
{
	char 			*line;
	char 			**line_split;
	struct s_parse	*next;
}	t_parse;

t_parse	*new_parse_node(char *line)
{
	t_parse	*node;

	node = ft_calloc(1, sizeof(t_parse));
	if (!node)
		return (NULL);
	node->line = ft_strdup(line);
	// if line is empty or \n ?
	node->line_split = ft_megasplit(node->line, WHITESPACE);
	node->next = NULL;
}

void	add_node(t_parse **parsed, t_parse *new_node)
{
	t_parse	*tmp;

	if (!*parsed)
		*parsed = new_node;
	else
	{
		tmp = *parsed;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

void	free_nodes(t_parse *list)
{
	t_parse *tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->line);
		ft_free_arr(tmp->line_split);
		free(tmp);
	}
	tmp = NULL;
}

void	read_file(char *file_name, t_map *data)
{
	t_list	*parse;
	char	*read;

	read = ft_strdup("");
}