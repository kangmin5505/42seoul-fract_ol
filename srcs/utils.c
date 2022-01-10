/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:33:03 by kangkim           #+#    #+#             */
/*   Updated: 2022/01/10 17:37:12 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				idx;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	idx = 0;
	while (ptr1[idx] && ptr2[idx])
	{
		if (ptr1[idx] != ptr2[idx])
			return ((int)(ptr1[idx] - ptr2[idx]));
		idx++;
	}
	if (ptr1[idx] != ptr2[idx])
		return ((int)(ptr1[idx] - ptr2[idx]));
	return (0);
}
