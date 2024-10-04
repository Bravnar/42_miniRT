/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:26:19 by hmorand           #+#    #+#             */
/*   Updated: 2024/06/25 16:26:19 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

char	**strarr_pop(char **arr, int index)
{
	int		size;
	int		i;
	char	**new_arr;

	size = strarr_len(arr);
	if (index >= size)
		return (arr);
	new_arr = malloc(sizeof(char *) * (size));
	if (!new_arr)
	{
		ft_free_arr(arr);
		return (NULL);
	}
	i = -1;
	while (++i < size)
	{
		if (i < index)
			new_arr[i] = ft_strdup(arr[i]);
		else if (i > index)
			new_arr[i - 1] = ft_strdup(arr[i]);
	}
	ft_free_arr(arr);
	new_arr[i - 1] = NULL;
	return (new_arr);
}

/* int main(void)
{
	char **arr = (char **)galloc(sizeof(char *) * 5);
	arr[0] = ft_strdup("Hello");
	arr[1] = ft_strdup("World");
	arr[2] = ft_strdup("Copilot");
	arr[3] = ft_strdup("GitHub");
	arr[4] = ft_strdup("Assistant");

	ft_printf("Original array:\n");
	for (int i = 0; i < 5; i++)
	{
		ft_printf("%s\n", arr[i]);
	}

	ft_printf("\n");

	// Test normal case
	int index = 2;
	char **new_arr = strarr_pop(arr, index);
	ft_printf("Array after removing element at index %d:\n", index);
	for (int i = 0; i < 4; i++)
	{
		ft_printf("%s\n", new_arr[i]);
	}

	ft_printf("\n");

	// Test edge case
	index = 0;
	new_arr = strarr_pop(arr, index);
	ft_printf("Array after removing element at index %d:\n", index);
	for (int i = 0; i < 3; i++)
	{
		ft_printf("%s\n", new_arr[i]);
	}

	ft_printf("\n");

	// Test error case
	index = 5;
	new_arr = strarr_pop(arr, index);
	if (new_arr == NULL)
	{
		ft_printf("Error: Index out of range\n");
	}

	free_strarr(arr);
	free_strarr(new_arr);

	return (0);
} */
