#include<stdio.h>
#include<stdlib.h>



  unsigned char       imageIDLength;          // �ĺ� �ʵ��� ����    // 0�̸� �ĺ� �ʵ尡 ���Ե��� ���� ���̴�.         
  unsigned char       colorMapType;         // ���� ���� ���� : �׻� 0��        
  unsigned char       imageTypeCode;       //  2  �̸� ������� ���� RGB
                                                           //  3  �̸� ������� ���� �׷��� ������       
  short     int       colorMapOrigin ;       // ���� ���� ���� ��ġ( ����-����) ; �׻� 0��   
  short     int       colorMapLength;      // ���� ���� ���� ( ���� - ����) : �׻� 0��     
  unsigned  char      colorMapEntrySize;   // ���� ���� �׸� ũ��( ���� - ����) : �׻� 0��       
  short     int       imageXOrigin;          // �̹��� ���� �ϴ� x ��ǥ (���� - ����) : �׻� 0��      
  short     int       imageYOrigin;         // �̹����� ���� �ϴ� x��ǥ (����-����) : �׻� 0��      
  short     int       imageWidth;            //  �̹����� �ȼ� ���� �ʺ�( ���� - ����)            
  short     int       imageHeight;          //   �̹����� �ȼ� ���� ����( ���� - ����)           
  unsigned  char      bitCount;              // ���� ��Ʈ �� : 16, 24, 32             
  unsigned  char      imageDescriptor;    // 24��Ʈ : 0x00   ;  32��Ʈ : 0x08
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
