

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