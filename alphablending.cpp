#include <png++/png.hpp>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <png++/rgba_pixel.hpp>
 
int main(int nNumberofArgs, char *pszArgs[]) {
  
  png::image< png::rgb_pixel > image("image.png");
  png::image< png::rgb_pixel > image1("gnome.png");
  png::image< png::rgb_pixel > image2(image.get_width(),image.get_height());
  std::cout<<"inaltimea imagini: "<<image.get_height()<<"\n";
  std::cout<<"lungimea imagini: "<<image.get_width()<<"\n";
  for (size_t y = 0; y < image.get_height(); ++y) {
    for (size_t x = 0; x < image.get_width(); ++x) {
	image2[y][x].red = (1-0.5)*image.get_pixel(x,y).red+0.5*image1.get_pixel(x,y).red;
	image2[y][x].green = (1-0.5)*image.get_pixel(x,y).green+0.5*image1.get_pixel(x,y).green;
	image2[y][x].blue = /*0;*/(1-0.5)*image.get_pixel(x,y).blue+0.5*image1.get_pixel(x,y).blue;
	//image2[y][x].alpha = image1.get_pixel(x,y).red;
	}
  }
    
 image2.write("translucid.png");
}
