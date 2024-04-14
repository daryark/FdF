/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:14:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/14 13:58:33 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//if map is valid - return opened fd num
// else return -1, fd still open
int	check_map_format(char *file)
{
	int		len;
	int		i;
	char	*format;
	int		fd;

	fd = open(file, O_RDONLY);
	if (open_error(fd))
		return (1);
	format = ".fdf";
	i = ft_strlen(format);
	len = ft_strlen(file);
	while (--i >= 0)
	{
		len--;
		if (file[len] != format[i])
		{
			close(fd);
			return (1);
		}
	}
	close(fd);
	return (0);
}

//zoom  2
int	set_default_values(t_fdf *fdf)
{
	fdf->height = 0;
	fdf->width = 0;
	fdf->zoom = 50.0;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->slope = 0.0;
	fdf->map = NULL;
	fdf->corner = malloc(sizeof(t_corner));
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		clean_all(fdf);
		return (1);
	}
	fdf->window = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	fdf->img = malloc(sizeof(t_img));
	fdf->menu = malloc(sizeof(t_img));
	if (!fdf->img || !fdf->menu || !fdf->window)
	{
		clean_all(fdf);
		return (1);
	}
	return (0);
}

void	clean_all(t_fdf *fdf)
{
	if (fdf->map != NULL)
		free_map(fdf);
	if (fdf->corner != NULL)
		free (fdf->corner);
	if (fdf->img->img != NULL)
	{
		mlx_destroy_image(fdf->mlx, fdf->img->img);
		free(fdf->img);
	}
	if (fdf->menu->img != NULL)
	{
		mlx_destroy_image(fdf->mlx, fdf->menu->img);
		free(fdf->menu);
	}
	if (fdf->mlx != NULL && fdf->window != NULL)
		mlx_destroy_window(fdf->mlx, fdf->window);
	if (fdf->mlx)
	{
		(void)fdf->mlx; //check if i need this line
		free(fdf->mlx);
	}
}

void	free_lines( char **line_arr)
{
	int	i;

	i = -1;
	while (line_arr[++i])
		free(line_arr[i]);
	free(line_arr);
}

void	reset_corner(t_corner *p)
{
	p->x_low = INT_MAX;
	p->y_low = INT_MAX;
	p->x_high = INT_MIN;
	p->y_high = INT_MIN;
}

unsigned int	ft_set_color(char *str)
{
	int		nb;

	if (!str || !*str)
		return (0xffffff);
	nb = 0;
	if (*str == '0' && *(str + 1) == 'x')
		str += 2;
	while ((*str >= '0' && *str <= '9')
		|| (*str >= 'a' && *str <= 'f')
		|| (*str >= 'A' && *str <= 'F'))
	{
		if (*str >= '0' && *str <= '9')
			nb = (nb * 16) + (*str - '0');
		else if (*str >= 'a' && *str <= 'f')
			nb = (nb * 16) + (*str - 'a' + 10);
		else
			nb = (nb * 16) + (*str - 'A' + 10);
		str++;
	}
	return (nb);
}

int	open_error(int fd)
{
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}
