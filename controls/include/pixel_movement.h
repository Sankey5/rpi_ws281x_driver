#ifndef __PIXEL_MOVEMENT_H__
#define __PIXEL_MOVEMENT_H__

int up      (int pixelPosition, int matrixWidth, int matrixSize);
int right   (int pixelPosition, int matrixWidth, int matrixSize);
int down    (int pixelPosition, int matrixWidth);
int left    (int pixelPosition, int matrixWidth);
int getRow  (int pixelPosition, int matrixWidth);

#endif