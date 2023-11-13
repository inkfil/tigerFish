#include<image.h>

int main(int argc, char **argv){

//	Image test0("images/test.jpg");
//	test0.write("images/new.png");
//
//	Image test1("images/test.jpg");
//	Image copy = test1;
//	copy.write("images/copy.png");
//
//	Image blank(500, 500, 3);
//	blank.write("images/blank.jpg");
//
//	Image gavg("images/test.jpg");
//	gavg.grayscaleAvg();
//	gavg.write("images/gavg.png");
//
//	Image glum("images/test.jpg");
//	glum.grayscaleLum();
//	glum.write("images/glum.png");
//
//	Image maskedBlue("images/test.jpg");
//	maskedBlue.colorMask(0, 0, 1);
//	maskedBlue.write("images/maskedBlue.png");
//
//	Image maskedGreen("images/test.jpg");
//	maskedGreen.colorMask(0, 1, 0);
//	maskedGreen.write("images/maskedGreen.png");
//
//	Image maskedRed("images/test.jpg");
//	maskedRed.colorMask(1, 0 ,0);
//	maskedRed.write("images/maskedRed.png");
//
//	Image test3("images/test1.jpg");
//	Image test4("images/test2.jpg");
//	test3.diffMap(test4);
//	test3.write("images/diffMap.png");
//
//	Image test5("images/test1.jpg");
//	Image test6("images/test2.jpg");
//	test5.diffMapScale(test6, 2);
//	test5.write("images/diffMapScale.png");
	
//	Image diffmap("images/gavg.png");
//	Image diffmapscale("images/glum.png");
//	diffmap.diffMapScale(diffmapscale, 4);
//	diffmap.write("images/diffofdiffmaps.png");

	Image gray("../images/gavg.png");
	gray.grayscaleToRGB();
	gray.write("../images/grayToRGB.png");

	return 0;
}
