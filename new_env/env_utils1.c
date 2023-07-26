/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:56 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/14 17:12:41 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

int	is_env_var(char *potential_var, t_list *env)
{
	int	i;
	char	*env_str;

	while (env)
	{
		i = 0;
		env_str = (char *)env->content;
		while (potential_var[i] && env_str[i] && (potential_var[i] == env_str[i]))
			i++;
		if ((potential_var[i] == 0 || ft_isspace(potential_var[i])) && (env_str[i] == '=' || env_str[i] == '\0'))
			return (1);
		env = env->next; 
	}
	return (0);
}

char	*get_var_name(char *str)
{
	int	i;
	char	*var;

	i = 0;
	if (str[i] == '$')
		i++;
	while (str[i] && !is_token_delimiter(str[i]) && str[i] != '$' && str[i] != '=' \
		!is_quote(str[i]) && str[i] != '/')
		i++;
	var = ft_substr(str, 0, i);
	if (!var)
		quit_program(EXIT_FAILURE);
	return (var);
}

int	ft_strnstr_iterator(char *haystack, char *needle, size_t len)
{
	size_t	little_len;
	int		i;

	i = 0;
	little_len = ft_strlen(needle);
	if (little_len == 0 || len == 0)
		return (-1);
	while (haystack[i] && (int)(little_len <= len - i))
	{
		if (!ft_strncmp(&haystack[i], (char *)needle, little_len))
			return (i);
		i++;
	}
	return (-1);
}

char	*replace_midstring(char *original, char *old_substr, char *new_substr, int replace_i)
{
	char	*final;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(original) - ft_strlen(old_substr) + ft_strlen(new_substr);
	final = ft_calloc(len + 1, sizeof(char));
	if (final == 0)
		quit_program(EXIT_FAILURE);
	while (*original)
	{
		if (i == replace_i)
		{
			while (new_substr && *new_substr)
				final[i++] = *(new_substr++);
			original += ft_strlen(old_substr);
			replace_i = -2;
		}
		if (*original)
			final[i++] = *(original++);
	}
	final[i] = '\0';
	return (final);
}

void	tilde_join(char **str, char **home_path)
{
	char	*tmp;

	tmp = ft_strjoin(*home_path, &str[0][1]);
	if (!tmp)
		quit_program(EXIT_FAILURE);
	free(*home_path);
	*home_path = 0;
	free(*str);
	*str = 0;
	*str = tmp;
}