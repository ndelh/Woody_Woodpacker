/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_longest_padding.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:50:57 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/25 13:38:13 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

void	skip_first_non_blank(char **cursor, char *end)
{
	while (*cursor != end && **cursor)
		++(*cursor);
}

void	count_loop(char **cursor, char *end, char *begin, t_lpad *lpad)
{
	int	current_len;
	char	*reminder;

	current_len = 0;
	reminder = *cursor;
	while (*cursor != end && !(**cursor))
	{
		++(*cursor);
		++current_len;
	}
	if (current_len > lpad->len)
	{
		lpad->len = current_len;
		lpad->offset = reminder-begin;
	}


}

void	find_bigest(t_lpad *lpad, char *cursor, char *end, char *begin)
{
	while (cursor != end && end - cursor > lpad->len)
	{
		if (!(*cursor))
			count_loop(&cursor, end, begin, lpad);
		else
			++cursor;
	}
}

void	retrieve_lpad(t_lpad *lpad, t_intel *intel)
{
	char	*cursor;
	char	*end;
	char	*begin;

	cursor = (char *)(intel->ogn_begin);
	begin = cursor;
	end = cursor + intel->ogn_size;
	skip_first_non_blank(&cursor, end);
	find_bigest(lpad, cursor, end, begin);
}
