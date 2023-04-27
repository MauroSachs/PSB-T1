#include <stdio.h>
#include <stdlib.h>
#include "lib_ppm.c"

unsigned char aplicaSubpixel(unsigned char color, int x, int y);

int main()
{
	struct image_s data;
	struct image_s *image = &data;
	struct image_s newData;
	struct image_s *newImage = &newData;
	int i, j, r, s;

	r = read_ppm("lena.ppm", image);
	s = new_ppm(newImage, image->width * 3, image->height * 3);

	if (r == 0 && s == 0)
	{
		printf("width: %d, height: %d\n", newImage->width, newImage->height);

		for (j = 0; j < image->height; j++)
		{
			for (i = 0; i < image->width; i++)
			{
				struct pixel_s pixel = image->pix[j * image->width + i];

				int pixelRow = j * 3;
				int pixelColumn = i * 3;

				// FILEIRA VERMELHA
				if (pixel.r <= 74)
				{
					newImage->pix[pixelRow * newImage->width + pixelColumn].r = 0;
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn].r = 0;
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn].r = 0;
				}
				else if (pixel.r <= 134)
				{
					newImage->pix[pixelRow * newImage->width + pixelColumn].r = 0;
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn].r = 255;
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn].r = 0;
				}
				else if (pixel.r <= 179)
				{
					newImage->pix[pixelRow * newImage->width + pixelColumn].r = 255;
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn].r = 0;
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn].r = 255;
				}
				else
				{
					newImage->pix[pixelRow * newImage->width + pixelColumn].r = 255;	
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn].r = 255;	
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn].r = 255;	
				}
				// FILEIRA VERDE
				if (pixel.g <= 74)
				{
					newImage->pix[pixelRow * newImage->width + pixelColumn + 1].g = 0;
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn + 1].g = 0;
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn + 1].g = 0;
				}
				else if (pixel.g <= 134)
				{
					newImage->pix[pixelRow * newImage->width + pixelColumn + 1].g = 0;
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn + 1].g = 255;
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn + 1].g = 0;
				}
				else if (pixel.g <= 179)
				{
					newImage->pix[pixelRow * newImage->width + pixelColumn + 1].g = 255;
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn + 1].g = 0;
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn + 1].g = 255;
				}
				else
				{
					newImage->pix[pixelRow * newImage->width + pixelColumn + 1].g = 255;
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn + 1].g = 255;
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn + 1].g = 255;
				}
				// FILEIRA AZUL
				if (pixel.b <= 74)
				{
					newImage->pix[pixelRow * newImage->width + pixelColumn + 2].b = 0;
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn + 2].b = 0;
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn + 2].b = 0;
				}
				else if (pixel.b <= 134)
				{
					newImage->pix[pixelRow * newImage->width + pixelColumn + 2].b = 0;
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn + 2].b = 255;
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn + 2].b = 0;
				}
				else if (pixel.b <= 179)
				{
				newImage->pix[pixelRow * newImage->width + pixelColumn + 2].b = 255;
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn + 2].b = 0;
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn + 2].b = 255;
				}
				else
				{
					newImage->pix[pixelRow * newImage->width + pixelColumn + 2].b = 255;
					newImage->pix[(pixelRow + 1) * newImage->width + pixelColumn + 2].b = 255;
					newImage->pix[(pixelRow + 2) * newImage->width + pixelColumn + 2].b = 255;
				}
			}
		}

		write_ppm("./output/resultado.ppm", newImage);

		free_ppm(image);
		free_ppm(newImage);
	}

	return 0;
}
