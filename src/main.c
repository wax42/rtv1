


#include "include/rtv1.h"

# include <math.h>
# define WIN_X 800
# define WIN_Y 800
# define ALPHA 30


void rayon(int origin, int direc)
{

}


int intersection_sphere(int r, int sphere)
{
}


int main(void)
{
	int i;
	int j;
	int x;
	int y;
	int z;

	x = j - WIN_X / 2;
	y = i - WIN_Y/ 2;
	z = -  WIN_X / (2  * tan(ALPHA / 2));
	i = -1;
	while (++i < WIN_Y)
	{
		j = -1;
		while (++j < WIN_X)
		{
			rayon();

			if (intersection())
				mlx_pixel_put_to_image(blanc);
			else
				mlx_pixel_put_to_image(noir);
		}

	}

}

