/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:46:46 by hyamamot          #+#    #+#             */
/*   Updated: 2025/04/02 17:46:47 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	list_len(t_node **a)
{
	t_node	*tmp_node;
	int		len;

	if (!a || !((*a)->pnext))
		return (0);
	tmp_node = *a;
	len = 1;
	while (*a != tmp_node->pnext)
	{
		tmp_node = tmp_node->pnext;
		len++;
	}
	return (len);
}
