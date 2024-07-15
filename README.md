# Bad Apple on Linux Terminal
Yet another way to play Bad Apple.

## Installation and Setup
1. Download the repository.

2. Download the [audio file and the frames](https://drive.google.com/file/d/1rLPlZHCaornrV7hCjfVy41MrpWPN9Ju0/view?usp=drive_link).

3. The `image_sequence` directory, `bad_apple.c`, `bad_apple.wav` and `image_resizing.py` must be in the same location.

2. Make sure that the [requirements](requirements.md) are met.

## Usage
1. Open a Linux terminal.

2. Enter the directory in which the audio, C and Python files are.

3. Run `$ python3 image_resizing.py 6562 180 45 frames.txt`. The command-line arguments are the number of frames to resize, width of each resized image, height of each resized image and the path to the output file. There are $6562$ frames provided, and this resizes all of them. It is crutial that the width and the height are in the ratio $4:1$ for aesthetic purposes.

4. Then run `$ gcc bad_apple.c -o play_vid` to compile the C program.

5. Make sure that you have zoomed out a sufficient amount.

6. Finally run `$ (play bad_apple.wav -q &) && (clear &) && (./play_vid 6562 180 45 30.1009174312 frames.txt &)` to parallely play the audio file and run the executable file. The command-line arguments are the number of frames to play, width, height, the FPS (number of frames to play per second) and the path to the file in which the pixel values are stored. Make sure that the number of frames specified are at most the number of frames resized. The FPS was found by dividing the total number of frames ($6562$) by $218$ (which is a few seconds less than the length of the audio file).

7. To stop the playback in between, open System Monitor, and end the processes named "play" (to stop the audio playback) and "play_vid" (to stop the displaying).

8. Run `$ clear` to clear the terminal.
