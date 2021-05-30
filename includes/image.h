//#define STB_IMAGE_IMPLEMENTATION
//#define STB_IMAGE_WRITE_IMPLEMENTATION

//#include<stb_image.h>
//#include<stb_image_write.h>
#include<iostream>
#include<stdint.h>

enum ImageTypes{PNG, JPG, BMP, TGA};

struct Image{
	uint8_t *data = NULL;
	size_t size = 0;
	int w = 0;
	int h = 0;
	int channels;
	Image(const char *filename);
	Image(int w, int h, int channels);
	Image(const Image &img);
	~Image();
	
	// Image IO
	bool read(const char *filename);
	bool write(const char *filename);
	ImageTypes getImageType(const char *filename);
	
	// Grayscale Images
	Image &grayscaleAvg();
	Image &grayscaleLum();
	
	// grayscale To RGB
	Image& grayscaleToRGB();

	// Color Masks.
	Image& colorMask(float r, float g, float b);
	
	// Steagnography
	Image& encodeMessage(const char *message);
	Image& decodeMessage(char* buffer, size_t *messageLength);

	// difference map
	int byteBound(int value);
	Image& diffMap(Image& img);
	Image& diffMapScale(Image& img, uint8_t scale);
};

