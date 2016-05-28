#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

// ビットマップの読み込み
void readBMPHeader(FILE* file, int* height, int* width)
{
  BITMAPFILEHEADER header;
  BITMAPINFOHEADER infHeader;

  // ファイルヘッダの読み込み
  fread(&header, sizeof(BITMAPFILEHEADER),1,file);
  fread(&infHeader, sizeof(BITMAPINFOHEADER),1,file);

  *height = *(int*)infHeader.biHeight;
  *width = *(int*)infHeader.biWidth;
}

// char 型の配列に変換
void toCharArray(long long num, unsigned char* data, size_t size)
{
  size_t i;
  for(i=0; i<size; i++){
    data[i] = (unsigned char)(0xFF & num);
    num = num >> 8;
  }
}

// ビットマップヘッダの書き込み
void writeBMPHeader(FILE* fp, int height, int width)
{
  BITMAPFILEHEADER header;
  BITMAPINFOHEADER infHeader;

  int headerSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
  int ImageSize = width * height * BIT_COUNT / 8;
  int fileSize = headerSize + ImageSize;

  int bm = 'B' | ('M' << 8);
  
  // BITMAPFILEHEADER
  toCharArray(bm, header.bfType, sizeof(header.bfType));
  toCharArray(fileSize, header.bfSize, sizeof(header.bfSize));
  toCharArray(0,header.bfReserved1,sizeof(header.bfReserved1));
  toCharArray(0,header.bfReserved2,sizeof(header.bfReserved2));
  toCharArray(headerSize, header.bfOffBits, sizeof(header.bfOffBits));

  // BITMAPINFOHEADER
  toCharArray(sizeof(BITMAPINFOHEADER), infHeader.biSize, sizeof(infHeader.biSize));
  toCharArray(width, infHeader.biWidth, sizeof(infHeader.biWidth));
  toCharArray(height, infHeader.biHeight, sizeof(infHeader.biHeight));
  toCharArray(1, infHeader.biPlanes, sizeof(infHeader.biPlanes));
  toCharArray(BIT_COUNT, infHeader.biBitCount, sizeof(infHeader.biBitCount));
  toCharArray(0, infHeader.biCompression, sizeof(infHeader.biCompression));
  toCharArray(ImageSize, infHeader.biSizeImage, sizeof(infHeader.biSizeImage));
  toCharArray(0,infHeader.biXPixPerMeter, sizeof(infHeader.biXPixPerMeter));
  toCharArray(0,infHeader.biYPixPerMeter, sizeof(infHeader.biYPixPerMeter));
  toCharArray(0,infHeader.biClrUsed, sizeof(infHeader.biClrUsed));
  toCharArray(0,infHeader.biClrImportant, sizeof(infHeader.biClrImportant));

  // ファイルヘッダの書き込み
  fwrite(&header, sizeof(BITMAPFILEHEADER),1,fp);
  fwrite(&infHeader, sizeof(BITMAPINFOHEADER),1,fp);
}
