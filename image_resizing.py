import cv2, sys

# the command-line arguments should be [executed file name, number of frames to resize, width of the resized image, height of the resized image, output file path (with the extension)]
frames = int(sys.argv[1])
new_shape = (int(sys.argv[2]), int(sys.argv[3]))
op_file_path = sys.argv[4]

output_file = open(op_file_path, 'w') # open the output file

for i in range(1, frames + 1):
	im = cv2.imread(f"./image_sequence/bad_apple_{i}.png") # open the image
	im.resize(new_shape) # resize the image

	for pixel in im:
		"""
		Write the colour of the pixel (one pixel per line).
		"\033" is an ANSI escape code.
		"38" is used to set the foreground colour.
		"2" is to specify that the colour format is going to be RGB.
		This is followed by the three pixel values, in the order RGB.
		The syntax requires an "[", an "m" and seperation by semicolons.
		"""
		output_file.write(f"\033[38;2;{pixel[0]};{pixel[1]};{pixel[2]}m\n")

	# print the frame number for every 100 frames
	if i % 100 == 0:
		print(i, '/', frames)

output_file.close() # close the output file

print("End of program.")
