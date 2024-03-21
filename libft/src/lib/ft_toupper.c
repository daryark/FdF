/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:27:01 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/11/17 14:28:31 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// int	main(void)
// {
// 	printf("\nft_toupper.c\n");
// 	printf("native: %d\n", toupper(97));
// 	printf("my: %d\n\n", ft_toupper(97));
// 	printf("native: %d\n", toupper(67));
// 	printf("my: %d\n\n", ft_toupper(67));
// 	printf("native: %d\n", toupper(0));
// 	printf("my: %d\n\n", ft_toupper(0));
// 	printf("native: %d\n", toupper(2147483647));
// 	printf("my: %d\n\n", ft_toupper(2147483647));
// 	printf("native: %d\n", toupper(-48));
// 	printf("my: %d\n\n", ft_toupper(-48));
// 	printf("native: %d\n", toupper(48));
// 	printf("my: %d\n\n", ft_toupper(48));
// 	return (0);
// }
