/*
Run the following lines (one after another) on a Linux terminal to play Bad Apple on the terminal.
$ gcc bad_apple.c -o play_vid
$ (play bad_apple.wav -q &) && (clear &) && (./play_vid 6562 180 45 30.1009174312 frames.txt &)
$ clear
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define RESET "\033[0m" // to reset the text formatting (the colour)

int main(int argc, char *argv[]) {
	// the command-line arguments should be [number of frames to play, width of the images, height of the images, fps to play at, path to the file where the pixel values of the frames are stored (with the extension)]
	int frames = atoi(argv[1]), width = atoi(argv[2]), height = atoi(argv[3]);
	double fps = atoi(argv[4]);
	char file_name = argv[5];
	char clr[] = "\033[38;0;255;255;255m"; // initialising a variable to store the current colour

	FILE *file_ptr = fopen(file_name, "r"); // open the file with the pixel values of all the frames

	// variables to track the time elasped (to set the video speed to the same speed as the song)
	struct timeval start, end;
	double elapsed_time;
	gettimeofday(&start, NULL);
	printf("\n");
	for (int frame = 1; frame <= frames; frame++) {
		// print the frame
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				fscanf(file_ptr, "%s", clr); // get the pixel value
				printf("%s\u2588", clr); // set the fourground colour, and print the Unicode character "█" (Full Block)
			}
			printf("\n"); // go to the next line after printing the row
		}

		// get back to the first row
		for (int row = 0; row < height; row++) {
			printf("\033[F");
		}

		// wait to print the next frame
		do {
			usleep(100);
			gettimeofday(&end, NULL);
			elapsed_time = end.tv_sec - start.tv_sec + 1e-6 * (end.tv_usec - start.tv_usec); // in seconds
		} while (elapsed_time < frame / fps);

		// fflush(stdout);
	}

	fclose(file_ptr); // close the file

	// get to the bottom row
	for (int row = 0; row < height; row++) {
		printf("\n");
	}
	printf(RESET); // reset the text formatting

	return 0;
}
