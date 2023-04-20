#include <stdio.h>
#include "lib_ppm.h"

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

				//FILEIRA VERMELHA
				if(pixel.r <= 74) {
					
				}
				else if (pixel.r <=134){

				}
				else if (pixel.r <=179) {

				}
				else {

				}
				//FILEIRA VERDE
				if(pixel.g <= 74) {
					
				}
				else if (pixel.g <=134){

				}
				else if (pixel.g <=179) {

				}
				else {

				}
				//FILEIRA AZUL
				if(pixel.b <= 74) {
					
				}
				else if (pixel.b <=134){

				}
				else if (pixel.b <=179) {

				}
				else {

				}
				
			}
		}


		write_ppm("result.ppm", newImage);

		free_ppm(image);
		free_ppm(newImage);
	}
	return 0;
}
