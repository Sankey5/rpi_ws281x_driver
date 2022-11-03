void rainbow(int start, int end) {
	static int pos = 0;
	pos == 64 ? pos = 0 : pos++;

	matrix[start] = dotcolors[pos/8];

	// move everything up one place
	strand_raise(start, end);
}

void fire(int start, int end) {
	int colorPicker = rand() % 1000 + 1;

	if (colorPicker <= 750) {
		matrix[start] = dotcolors[0];
	}
	else {
		matrix[start] = dotcolors[1];
	}

	//update all positions
	strand_raise(start, end);
}