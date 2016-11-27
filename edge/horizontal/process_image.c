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
int b[size[0]+2][size[1]+2];
int result[size[0]][size[1]];
float normalized_result[size[0]][size[1]];
int i,j,sum=0,max=0,min=0,temp;


 for ( i = 0; i < size[0]+2; i++ ) {

      for ( j = 0; j < size[1]+2; j++ ) {
if(i==0 || j==0 || i==size[0]+1 || j==size[1]+1)
{
b[i][j]=0;
}
else
{
b[i][j]=image[i-1][j-1];
}

}
}



 for ( i = 1; i < size[0]+1; i++ ) {

      for ( j = 1; j < size[1]+1; j++ ) {
int topleft=b[i-1][j-1]*-1;
int topcenter=b[i-1][j]*-1;
int topright=b[i-1][j+1]*-1;
int centerleft=b[i][j-1]*0;
int center=b[i][j]*0;
int centerright=b[i][j+1]*0;
int bottomleft=b[i+1][j-1]*1;
int bottomcenter=b[i+1][j]*1;
int bottomright=b[i+1][j+1]*1;
result[i-1][j-1]=topleft+topcenter+topright+centerleft+center+centerright+bottomleft+bottomcenter+bottomright;
	

}
}
max=result[0][0];
min=result[0][0];
 for ( i = 0; i < size[0]; i++ ) {

      for ( j = 0; j < size[1]; j++ ) {
if (max<result[i][j])
max=result[i][j];
if (min>result[i][j])
min=result[i][j];
}
}

temp=max-min;

 for ( i = 0; i < size[0]; i++ ) {

      for ( j = 0; j < size[1]; j++ ) {
normalized_result[i][j]=((float)result[i][j]-(float)min)/(float)temp;
}
}

//printf("%d \n",temp);
//printf("%d \n",min);

for
 ( i = 0; i < size[0]; i++ ) {

      for ( j = 0; j < size[1]; j++ ) {

normalized_result[i][j]=(int)((normalized_result[i][j]*256.0)-1.0);
}
}


for
 ( i = 0; i < size[0]; i++ ) {

      for ( j = 0; j < size[1]; j++ ) {
proc_img[i][j]=(int)normalized_result[i][j];
}
}







for
 ( i = 0; i < size[0]; i++ ) {

      for ( j = 0; j < size[1]; j++ ) {
printf("%d \n",proc_img[i][j]);
}
}

}

