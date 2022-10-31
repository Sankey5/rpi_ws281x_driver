// TODO: need to change all functions to return array/struct and take in those array/structs as arguements

// Move all pixels to the next index in the array
void strand_raise(int start, int end) {
	for (int y = (end - 1); y >= start; y--) {
		matrix[y] = matrix[y - 1];
	}
}

// Execute a given pattern function
void matrix_strand(void (*pattern)(int, int), int start, int end) {
	pattern(start, end);
}

// Array of pattern functions
void (*pattern_functs[])(int, int) = {rainbow, fire};

// Pick a random pattern
void pick_pattern(int start, int end) {
	static int pattern_index = 0;
	int decider = rand() % 10 + 1;


	if (decider == 10) {
		pattern_index++;
		matrix_clear();
		strand_render();
	}
	
	if (pattern_index > sizeof(pattern_functs) / sizeof(pattern_functs[0])) {
		pattern_index = 0;
	}

	matrix_strand(pattern_functs[pattern_index], start, end);
}