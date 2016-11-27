#include <stdio.h>
#include <math.h>
#include <X11/Xlib.h>

#define DIM 512

/******************************************************************/
/* This structure contains the coordinates of a box drawn with    */
/* the left mouse button on the image window.                     */
/* roi.x , roi.y  - left upper corner's coordinates               */
/* roi.width , roi.height - width and height of the box           */
/******************************************************************/
extern XRectangle roi;


/******************************************************************/
/* Main processing routine. This is called upon pressing the      */
/* Process button of the interface.                               */
/* image  - the original greyscale image                          */
/* size   - the actual size of the image                          */
/* proc_image - the image representation resulting from the       */
/*              processing. This will be displayed upon return    */
/*              from this function.                               */
/******************************************************************/
void process_image(image, size, proc_img)
unsigned char image[DIM][DIM];
int size[2];
unsigned char proc_img[DIM][DIM];
{
int result[size[0]][size[1]];
float normalized_result[size[0]][size[1]];
int i,j,sum=0,max=0,min=0,temp;
int width=roi.width;
int height=roi.height;
int startX=roi.x;
int startY=roi.y;

if (width%2==0)
	width=width-1;
if (height%2==0)
	height=height-1;
int template[width][height];
int b[size[0]+((width-1)/2)][size[1]+((height-1)/2)];
int template_sum=0;
int meantemplate=0,tempstdsum=0,tempstd;
int tempmatrix[width][height];
 for ( i = 0; i < width; i++ ) {

      for ( j = 0; j < height; j++ ) {
		  template[i][j]=image[startX+i][startY+j];
		template_sum=template_sum+template[i][j];
		 }
 }	  
meantemplate=((template_sum)/(width*height));
for ( i = 0; i < width; i++ ) {

      for ( j = 0; j < height; j++ ) {
		  tempstdsum=tempstdsum+(abs(template[i][j]-meantemplate)*abs(template[i][j]-meantemplate));
		
		 }
 }
tempstd=((tempstdsum)/(width*height));
 
 for ( i = 0; i < size[0]+((width-1)/2); i++ ) {

      for ( j = 0; j < size[1]+((height-1)/2); j++ ) {
if(i<((width-1)/2) || i > size[0] || j<((height-1)/2) || j > size[1])
{
b[i][j]=0;
}
else
{
b[i][j]=image[i-1][j-1];
}

}
}


int meantempmatrix,imagesum=0,imagestd,imagestdsum=0;
int sumconv=0,k,l;
 for ( i = ((width-1)/2); i < size[0]+((width-1)/2); i++ ) {

      for ( j = ((height-1)/2); j < size[1]+((height-1)/2); j++ ) {
		  {
 for ( k = -((width-1)/2); k < ((width-1)/2); k++ ) {

      for ( l = -((height-1)/2); l < ((height-1)/2); l++ ) {
		
		tempmatrix[((width-1)/2)+k][((height-1)/2)+l]=b[i+k][j+l];
	  imagesum=imagesum+b[i+k][j+l];
	  }	  
 }	  
 meantempmatrix=imagesum/(width*height);
 {
for (k = -((width-1)/2); k < ((width-1)/2); k++ ) {

      for (l = -((height-1)/2); l < ((height-1)/2); l++ ) {
		
		imagestdsum=imagestdsum+(abs(tempmatrix[((width-1)/2)+k][((height-1)/2)+l]-meantempmatrix)*abs(tempmatrix[((width-1)/2)+k][((height-1)/2)+l]-meantempmatrix));
	  }	  
 } 
 imagestd==imagestdsum/(width*height);
 
 { 
  for ( k = -((width-1)/2); k < ((width-1)/2); k++ ) {

      for ( l = -((height-1)/2); l < ((height-1)/2); l++ ) {
		
		sumconv=sumconv+((tempmatrix[((width-1)/2)+k][((height-1)/2)+l]-meantempmatrix)*(template[((width-1)/2)+k][((height-1)/2)+l]-meantemplate));
	  
	  }	  
 }	 

result[i-((width-1)/2)][j-((height-1)/2)]=sumconv/(tempstd*imagestd);
 }
 }	
}

}
}

for
 ( i = 0; i < size[0]; i++ ) {

      for ( j = 0; j < size[1]; j++ ) {
proc_img[i][j]=(int)result[i][j];
}
}







for
 ( i = 0; i < size[0]; i++ ) {

      for ( j = 0; j < size[1]; j++ ) {
printf("%d \n",proc_img[i][j]);
}
}

}
