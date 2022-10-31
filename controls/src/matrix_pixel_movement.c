/**
 * @file pixel_movement.c
 * @author Brian Sankey (you@domain.com)
 * @brief Library to provide easy controls to move along a snaking matrix
 * @version 0.1
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
pixelPosition = 0-based
matrixWidth = 1-based
matrixSize = 1-based
*/

#include "pixel_movement.h"

int up(int pixelPosition, int matrixWidth, int matrixSize){
    pixelPosition += ((2*matrixWidth - 1) - 2*(i % matrixWidth));

    return pixelPosition > matrixSize - 1 ? -1 : pixelPosition;
}

int right(int pixelPosition, int matrixWidth, int matrixSize){
    int row = getRow(pixelPosition, matrixWidth);

    // If we are on an even row and we are touching the right side
    if(row % 2 == 0 && (pixelPosition + 1) % matrixWidth == 0) {
        pixelPosition = -1;
    }
    // If we on an odd row and we are touching the right side
    else if(row % 2 == 1 && (pixelPosition + 1) % matrixWidth == 1) {
        pixelPosition = -1;
    }
    else if(row % 2 == 0) {
        pixelPosition++;
    }
    else {
        pixelPosition--;
    }
    
    // If the pixel is out of the array, return -1 or return the new position of the pixel
    return pixelPosition > matrixSize - 1 ? -1 : pixelPosition;
}

int down(int pixelPosition, int matrixWidth){
    pixelPosition -= 2*(i % matrixWidth);

    return pixelPosition < 0 ? -1 : pixelPosition;
}

int left(int pixelPosition, int matrixWidth){
    int row = getRow(pixelPosition, matrixWidth);

    // If we are on an odd row and we are touching the left side
    if(row % 2 == 1 && (pixelPosition + 1) % matrixWidth == 0) {
        pixelPosition = -1;
    }
    // If we are on an even row and we are touching the left side
    else if(row % 2 == 0 && (pixelPosition + 1) % matrixWidth == 1) {
        pixelPosition = -1;
    }
    else if(row % 2 == 0) {
        pixelPosition--;
    }
    else {
        pixelPosition++;
    }
    
    // If the pixel is out of the array, return -1 or return the new position of the pixel
    return pixelPosition < 0 ? -1 : pixelPosition;
}

int getRow(int pixelPosition, int matrixWidth) {
    return (pixelPosition + 1) / matrixWidth;
}