/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:39:49 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/11/16 02:41:27 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// int	main(void)
// {
// 	printf("\nft_tolower.c\n");
// 	printf("native: %d\n", tolower(97));
// 	printf("my: %d\n\n", ft_tolower(97));
// 	printf("native: %d\n", tolower(67));
// 	printf("my: %d\n\n", ft_tolower(67));
// 	printf("native: %d\n", tolower(0));
// 	printf("my: %d\n\n", ft_tolower(0));
// 	printf("native: %d\n", tolower(2147483647));
// 	printf("my: %d\n\n", ft_tolower(2147483647));
// 	printf("native: %d\n", tolower(-48));
// 	printf("my: %d\n\n", ft_tolower(-48));
// 	printf("native: %d\n", tolower(48));
// 	printf("my: %d\n\n", ft_tolower(48));
// 	return (0);
// }
