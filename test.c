/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:47:47 by ygunay            #+#    #+#             */
/*   Updated: 2022/10/18 10:17:48 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;



// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
// 	img.img = mlx_new_image(mlx, 500, 500);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
//     mlx_pixel_put(mlx, mlx_win, 5, 5, 0x0025500);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

#include "mlx.h"

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Draw Pixel");

    mlx_pixel_put(mlx, win, 5, 5, 0x0025500);

    mlx_loop(mlx);
}