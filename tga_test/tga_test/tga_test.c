#include<stdio.h>
#include<stdlib.h>



  unsigned char       imageIDLength;          // 식별 필드의 길이    // 0이면 식별 필드가 포함되지 않은 것이다.         
  unsigned char       colorMapType;         // 색상 맵의 종류 : 항상 0임        
  unsigned char       imageTypeCode;       //  2  이면 압축되지 않은 RGB
                                                           //  3  이면 압축되지 않은 그레이 스케일       
  short     int       colorMapOrigin ;       // 색상 맵의 시작 위치( 하위-상위) ; 항상 0임   
  short     int       colorMapLength;      // 색상 맵의 길이 ( 하위 - 상위) : 항상 0임     
  unsigned  char      colorMapEntrySize;   // 색상 맵의 항목 크기( 하위 - 상위) : 항상 0임       
  short     int       imageXOrigin;          // 이미지 우측 하단 x 좌표 (하위 - 상위) : 항상 0임      
  short     int       imageYOrigin;         // 이미지의 좌측 하단 x좌표 (하위-상위) : 항상 0임      
  short     int       imageWidth;            //  이미지의 픽셀 단위 너비( 하위 - 상위)            
  short     int       imageHeight;          //   이미지의 픽셀 단위 높이( 하위 - 상위)           
  unsigned  char      bitCount;              // 색상 비트 수 : 16, 24, 32             
  unsigned  char      imageDescriptor;    // 24비트 : 0x00   ;  32비트 : 0x08
  unsigned  char*	  image_data;

  

void main()
{
	int i = 0;
	int j = 0;
	unsigned char pixelR,pixelG,pixelB;
	
	FILE *fp  = fopen("test_tga.tga","wb");
	tgaTARGAFILEHEADER(100,100,24);
	
	fprintf(fp, "%c",imageIDLength);
	fprintf(fp, "%c",colorMapType);
	fprintf(fp, "%c",imageTypeCode);
	fprintf(fp, "%c%c",colorMapOrigin%256,colorMapOrigin/256); //colorMapOrigin/256 => colorMapOrigin>>8
	fprintf(fp, "%c%c",colorMapLength%256,colorMapLength/256);
	fprintf(fp, "%c", colorMapEntrySize);
	fprintf(fp, "%c%c", imageXOrigin%256, imageXOrigin/256);
	fprintf(fp, "%c%c", imageYOrigin%256, imageYOrigin/256);
	fprintf(fp, "%c%c", imageWidth%256, imageWidth/256);
	fprintf(fp, "%c%c", imageHeight%256, imageHeight/256);
	fprintf(fp, "%c", bitCount);
	fprintf(fp, "%c", imageDescriptor);

	//fprintf(fp,"%c%c%c%c%c%c%c%c%c%c%c%c", imageIDLength, colorMapType, imageTypeCode, colorMapOrigin, colorMapLength, 
			//									colorMapEntrySize,imageXOrigin, imageYOrigin,imageWidth, imageHeight, bitCount, imageDescriptor);
	//fwrite(image_data, sizeof(image_data),1,fp);
	
	/*for (i=0; i<imageWidth*imageHeight*3; i++)    
	{        
		fprintf(fp," %02x",image_data[i]);    
	}*/

	//fprintf(fp, "%s", tgaTARGAFILEHEADER(100,100,24));

	printf("%c%c%c%c%c%c%c%c%c%c%c%c", imageIDLength, colorMapType, imageTypeCode, colorMapOrigin, colorMapLength, 
													colorMapEntrySize,imageXOrigin, imageYOrigin,imageWidth, imageHeight, bitCount, imageDescriptor);

	/*for (i=0; i<imageWidth*imageHeight*3; i++)    
	{        
		printf(" %02x",image_data[i]);    
	}*/
	for (i=0; i<imageHeight; i++)    
	{ 
		for(j=0; j<imageWidth; j++)
		{
			if(i<imageHeight/2)
			{
				pixelR = 0;
				pixelG = 0;
				pixelB = 255;
			}
			else
			{
				pixelR = 255;
				pixelG = 0;
				pixelB = 0;
			}
			fprintf(fp,"%c%c%c",pixelB, pixelG, pixelR);
		}
	}
	
	fclose(fp);
	free(image_data);
		/*
	FILE* fp  = fopen("test_tga.txt","wb");
	fprintf(fp, " %d %f", 22, 22); 
	fclose(fp);
	*/

}


int tgaTARGAFILEHEADER(short int Width, short int Height, unsigned char bitcount)
{
	int i;
	int j;
	imageIDLength = 0;
	colorMapType = 0;
	imageTypeCode = 2;
	colorMapOrigin = 0;
	colorMapLength = 0;
	colorMapEntrySize = 0;
	imageXOrigin = 0;
	imageYOrigin = 0;
	imageWidth = Width;
	imageHeight = Height;
	bitCount = bitcount;
	imageDescriptor = 32;
	image_data = (unsigned char*)malloc(Width*Height*3*sizeof(unsigned char));
	
	return 0;
}
