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
	s = new_ppm(newImage, image->width *3, image->height*3);

	if (r == 0 && s == 0)
	{
		printf("width: %d, height: %d\n", image->width, image->height);
		
		for (j = 0; j < image->height; j++)
		{
			for (i = 0; i < image->width; i++)
			{
				struct pixel_s pixel = image->pix[j * image->width + i];

				// percorre o padrão de subpixels para cada canal de cor (RGB)
				for (int y = 0; y < 3; y++) {
                    for (int x = 0; x < 3; x++) {
                        // criação de um padrão de subpixels para cada pixel de 3x3
                        struct pixel_s *new_pixel = &newImage->pix[(j * 3 + y) * newImage->width + (i * 3 + x)];

                        // Aplica o padrão de subpixel ao canal de cor vermelha
                        new_pixel->r = aplicaSubpixel(pixel.r, y, x);

                        // Aplica o padrão de subpixel ao canal de cor verde
                        new_pixel->g = aplicaSubpixel(pixel.g, y, x);

                        // Aplica o padrão de subpixel ao canal de cor azul
                        new_pixel->b = aplicaSubpixel(pixel.b, y, x);
                    }
                }
			}
		}

		write_ppm("resultado.ppm", newImage);

		free_ppm(image);
		free_ppm(newImage);
	}

	return 0;
}

// Implementação do padrão de subpixel
unsigned char aplicaSubpixel(unsigned char color, int x, int y) {
	// recebe a cor preta (0, 0, 0)
	if (color <= 74) {
		return 0;
	// recebe a cor vermelha (255, 0, 0)
	} else if (color <= 134) {
		return (x == 1 && y == 1) ? color : 0;
	// recebe a cor verde (0, 255, 0)
	} else if (color <= 179) {
	// recebe a cor azul (0, 0, 255)
		return (x != 1 || y != 1) ? color : 0;
	// recebe a cor original
	} else {
		return color;
	}
}