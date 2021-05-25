#include "include/cub3D.h"

static void	render_bmp(t_bmp *bmp)
{
	int	i;
	int	j;

	ft_bzero(bmp->zero, 3);
	i = g_info.yR - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < g_info.xR)
		{
			bmp->color = g_info.g_img.addr[i * g_info.xR + j];
			write(bmp->fd, &bmp->color, 3);
			j++;
		}
		if (bmp->padding > 0)
			write(bmp->fd, &bmp->zero, bmp->padding);
		i--;
	}
}

static void	header(t_bmp *bmp)
{
	ft_bzero(bmp->header, 54);
	bmp->size = 54 + 3 * (g_info.xR + bmp->padding) * g_info.yR;
	bmp->header[0] = 'B';
	bmp->header[1] = 'M';
	bmp->header[2] = (bmp->size);
	bmp->header[3] = (bmp->size >> 8);
	bmp->header[4] = (bmp->size >> 16);
	bmp->header[5] = (bmp->size >> 24);
	bmp->header[10] = 54;
	bmp->header[14] = 40;
	bmp->header[18] = (g_info.xR);
	bmp->header[19] = (g_info.xR >> 8);
	bmp->header[20] = (g_info.xR >> 16);
	bmp->header[21] = (g_info.xR >> 24);
	bmp->header[22] = (g_info.yR);
	bmp->header[23] = (g_info.yR >> 8);
	bmp->header[24] = (g_info.yR >> 16);
	bmp->header[25] = (g_info.yR >> 24);
	bmp->header[26] = 1;
	bmp->header[28] = 24;
	write(bmp->fd, &bmp->header, 54);
}

void	bmp(void)
{
	t_bmp	*bmp;

	bmp = (t_bmp *)malloc(sizeof(t_bmp));
	if (!bmp)
		ft_puterror("Error 1\n", NULL);
	ft_bzero(bmp, sizeof(t_bmp));
	bmp->padding = g_info.xR % 4;
	bmp->fd = open("cub3d.bmp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (bmp->fd < 0)
	{
		ft_putstr_fd("Problem in function open(bmp.c)\n", 1);
		ft_puterror("Error 2\n", NULL);
	}
	header(bmp);
	render_bmp(bmp);
	close(bmp->fd);
	free(bmp);
	ft_putstr_fd("Your cub3d.bmp is ready\n", 1);
	exit(1);
}
