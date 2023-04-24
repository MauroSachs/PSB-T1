#include <stdio.h>
#include <stdlib.h>
#include "lib_ppm.h"

unsigned char apply_subpixel_pattern(unsigned char color, int x, int y);

//testando

int main()
{
	struct image_s data;
	struct image_s *image = &data;
	struct image_s newData;
	struct image_s *newImage = &newData;
	int i, j, r, s;

	r = read_ppm("lena.ppm", image);
	s = new_ppm(newImage, image->width *3, image->height*3);

	if (r == 0 && s == 0)
	{
		printf("width: %d, height: %d\n", image->width, image->height);
		
		for (j = 0; j < image->height; j++)
		{
			for (i = 0; i < image->width; i++)
			{
				struct pixel_s pixel = image->pix[j * image->width + i];

				for (int y = 0; y < 3; y++) {
                    for (int x = 0; x < 3; x++) {
                        struct pixel_s *new_pixel = &newImage->pix[(j * 3 + y) * newImage->width + (i * 3 + x)];

                        // Red channel
                        new_pixel->r = apply_subpixel_pattern(pixel.r, y, x);

                        // Green channel
                        new_pixel->g = apply_subpixel_pattern(pixel.g, y, x);

                        // Blue channel
                        new_pixel->b = apply_subpixel_pattern(pixel.b, y, x);
                    }
                }
				
			}
		}


		write_ppm("result.ppm", newImage);

		free_ppm(image);
		free_ppm(newImage);
	}
	return 0;
	}
   unsigned char apply_subpixel_pattern(unsigned char color, int x, int y) {
	if (color <= 74) {
		return 0;
	} else if (color <= 134) {
		return (x == 1 && y == 1) ? color : 0;
	} else if (color <= 179) {
		return (x != 1 || y != 1) ? color : 0;
	} else {
		return color;
	}
}
