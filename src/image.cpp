#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STEG_HEADER_SIZE sizeof(char)*8

#include<stb_image.h>
#include<stb_image_write.h>
#include<image.h>

Image::Image(const char *filename){
	if(read(filename)){
		size = w*h*channels;
		std::cout<<"read file: "<<filename<<std::endl;
		std::cout<<"width: "<<w<<std::endl;
		std::cout<<"height: "<<h<<std::endl;
		std::cout<<"channels: "<<channels<<std::endl;
		std::cout<<"size: "<<size<<std::endl;
	}
	else{
		std::cerr<<"error, cant read the file: "<<filename<<std::endl;
	}
}

Image::Image(int w, int h, int channels):w(w), h(h), channels(channels){
	size = w*h*channels;
	data = new uint8_t[size];
}

Image::Image(const Image &img):Image(img.w, img.h, img.channels){
	memcpy(data, img.data, img.size);
}

Image::~Image(){
	stbi_image_free(data);
}

bool Image::read(const char *filename){
	data = stbi_load(filename, &w, &h, &channels, 0);
	return data!=NULL;
}

bool Image::write(const char *filename){
	ImageTypes imgtype = getImageType(filename);
	int success;
	switch(imgtype){
		case PNG:
			success = stbi_write_png(filename, w, h, channels, data, w*channels);
			break;
		case BMP:
			success = stbi_write_bmp(filename, w, h, channels, data);
			break;
		case JPG:
			success = stbi_write_jpg(filename, w, h, channels, data, 100);
			break;
		case TGA:
			success = stbi_write_tga(filename, w, h, channels, data);
			break;
	}
	return success != 0;
}

ImageTypes Image::getImageType(const char *filename){
	const char *ext = strrchr(filename, '.');
	if(ext!=nullptr){
		if(strcmp(ext, ".png")==0){
			return PNG;
		}
		else if(strcmp(ext, ".jpg")==0){
			return JPG;
		}
		else if(strcmp(ext, ".bmp")==0){
			return BMP;
		}
		else if(strcmp(ext, ".tga")==0){
			return TGA;
		}
	}
	return PNG;
}

Image& Image::grayscaleAvg(){
	// Average Pixel Value = R+G+B/3.0;
	if(channels<3){
		std::cerr<<"Image Channels are less than 3, image might already be grayscale."<<std::endl;
	}
	else{
		for(int i=0; i<size; i+=channels){
			int gray = (data[i]+data[i+1]+data[i+2])/3;
			memset(data+i, gray, 3);
		}
	}
	return *this;
}

Image& Image::grayscaleLum(){
	// Weighted Linear Average.
	if(channels<3){
		std::cerr<<"Image channels are less than 3, image might already be grayscale."<<std::endl;
	}
	else{
		for(int i=0; i<size; i+=channels){
			int gray = 0.2126*data[i]+0.7152*data[i+1]+0.0722*data[i+2];
			memset(data+i, gray, 3);
		}
	}
	return *this;
}

// grayscale To RGB
Image& Image::grayscaleToRGB(){
	if(channels<2){
		std::cerr<<"Image channels are more than 2, image might already be RGB.";
	}
	else{
		for(int i=0; i<size; i+=channels){
			data[i]*=0.30;
			data[i+1]*=0.59;
			data[i+2]*=0.11;
		}
	}
	return *this;
}

Image& Image::colorMask(float r, float g, float b){
	if(channels<3){
		std::cerr<<"\e[31m[error]Image channels are less than 3."<<std::endl;
	}
	else{
		for(int i=0; i<size; i+=channels){
			data[i] *= r;
			data[i+1] *= g;
			data[i+2] *= b;
		}
	}
	return *this;
}

//Image& Image::encodeMessage(const char* message){
//	uint32_t len = strlen(message)*sizeof(char);
//	for(uint8_t i=0; i<STEG_HEADER_SIZE; i++){
//		
//	}
//}

//Image& Image::decodeMessage(char *buffer, size_t *messageLength){}

int Image::byteBound(int value){
	return (value<0)?0:(value>255?255:value);
}

Image& Image::diffMap(Image &img){
	int cmp_width = fmin(w, img.w);
	int cmp_height = fmin(h, img.h);
	int cmp_channels = fmin(channels, img.channels);
	for(int i=0; i<cmp_height; i++){
		for(int j=0; j<cmp_width; j++){
			for(int k=0; k<cmp_channels; k++){
				data[(i*w+j)*channels+k] = byteBound(abs(data[(i*w+j)*channels+k] - img.data[(i*img.w+j)*img.channels+k]));
			}
		}
	}
	return *this;
}

Image& Image::diffMapScale(Image &img, uint8_t scale = 0){
	int cmp_width = fmin(w, img.w);
	int cmp_height = fmin(h, img.h);
	int cmp_channels = fmin(channels, img.channels);
	uint8_t largest = 0;
	for(int i=0; i<cmp_height; i++){
		for(int j=0; j<cmp_width; j++){
			for(int k=0; k<cmp_channels; k++){
				data[(i*w+j)*channels+k] = byteBound(abs(data[(i*w+j)*channels+k] - img.data[(i*img.w+j)*img.channels+k]));
				largest = fmax(largest, data[(i*w+j)*channels+k]);
			}
		}
	}
	scale = 255/fmax(1, fmax(scale, largest));
	for(int i=0; i<size; i++){
		data[i]*=scale;
	}
	return *this;
}
