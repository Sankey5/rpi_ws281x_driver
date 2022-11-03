#include "pixel_movement.h"
#include "patterns.h"
#include "ws2811.h"

void matrix_raise(void)
{
    int x, y;

    for (y = 0; y < (height - 1); y++)
    {
        for (x = 0; x < width; x++)
        {
            // This is for the 8x8 Pimoroni Unicorn-HAT where the LEDS in subsequent
            // rows are arranged in opposite directions
            matrix[y * width + x] = matrix[(y + 1)*width + width - x - 1];
        }
    }
}

void matrix_bottom(void)
{
    int i;

    for (i = 0; i < (int)(ARRAY_SIZE(dotspos)); i++)
    {
        dotspos[i]++;
        if (dotspos[i] > (width - 1))
        {
            dotspos[i] = 0;
        }

        if (ledstring.channel[0].strip_type == SK6812_STRIP_RGBW) {
            matrix[dotspos[i] + (height - 1) * width] = dotcolors_rgbw[i];
        } else {
            matrix[dotspos[i] + (height - 1) * width] = dotcolors[i%8];
        }
    }
}

/**
 * @brief 
 * 
 * @param matrixWidth 1-based value for how wide a matrix is (# of columns)
 * @param matrixSize 1-based value for total length (number of pixels) in the LED matrix
 */
void matrix_oscillate(ws2811_led_t *matrix, int matrixWidth,int matrixSize) {
  // Get the height of the matrix
  int height = matrixSize / matrixWidth;
  static int level = matrixSize / matrixWidth;

  // Reset level it it 
  if (level + 1 > matrixWidth)
    level = -height + 1;

  // Loop through the a row of the matrix
  for (int i = 0; i < matrixWidth; i++) {

    // Every other value is going to be on opposing sides
    // For odd values
    if(i % 2 != 0) {
      //TODO: how do we account for always going down
      int currPixel = (abs(level - 1)) * matrixWidth + i;
      int nextPixel = up(currPixel, matrixWidth, matrixSize);

      // If moving up is a valid move, do it
      if(nextPixel) {
        matrix[currPixel] = 0;
        matrix[nextPixel] = dotcolors[0];
      }
      // Otherwise, go down
      else {
        nextPixel = down(currPixel, matrixWidth, matrixSize);
        matrix[currPixel] = 0;
        matrix[nextPixel] = dotcolors[0];
      }

      
    }
    // For even values
    else {

    }
  }

  level++;
}

void matrix_oscillate(void) {
  static int level = 18;

  if (level + 1 > (int)(ARRAY_SIZE(dotspos)))
    level = -height + 1;

  int bottom_level = height - abs(level) - 1;

  printf("Level: %d, bottom: %d\n", level, bottom_level);

  for (int i = 0; i < height; i++) {
    if (i % 2 == 0) {
      //matrix[y * width + x] = matrix[(y + 1)*width + width - x - 1];
      if (level % 2 == 0) {
        // Turn current row's value black
        matrix[(abs(level - 1)) * width + i] = 0;
        matrix[abs(level) * width + width - i - 1] = dotcolors[0];
      }
      else {
        matrix[(abs(level - 1)) * width + width - i - 1] = 0;
        matrix[abs(level) * width + i ] = dotcolors[0];
      }
    }
    else {
      if (level % 2 != 0) {
        // Turn current row's value black
        matrix[(abs(bottom_level) + (level < 0 ? -1 : 1)) * width + i] = 0;
        matrix[abs(bottom_level) * width + width - i - 1] = dotcolors[0];
      }
      else {
        matrix[(abs(bottom_level) + (level <= 0 ? -1 : 1)) * width + width - i - 1] = 0;
        matrix[abs(bottom_level) * width + i ] = dotcolors[0];
      }
    }
  }

  level++;
}

void matrix_clear(void)
{
    int x, y;

    for (y = 0; y < (height ); y++)
    {
        for (x = 0; x < width; x++)
        {
            matrix[y * width + x] = 0;
        }
    }
}