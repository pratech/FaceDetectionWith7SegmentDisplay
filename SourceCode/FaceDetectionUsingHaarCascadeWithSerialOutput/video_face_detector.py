# USAGE
# python video_face_detector.py

# import the necessary packages
from imutils.video import VideoStream
import argparse
import imutils
import time
import cv2
import serial
import time

# construct the argument parser and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-c", "--cascade", type=str,
	default="haarcascade_frontalface_default.xml",
	help="path to haar cascade face detector")
args = vars(ap.parse_args())
#arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.01)
def write_read(x):
 
    str_1_encoded = bytes(x,'UTF-8')
    #arduino.write(str_1_encoded)
    #time.sleep(2)
# load the haar cascade face detector from
print("[INFO] loading face detector...")
detector = cv2.CascadeClassifier(args["cascade"])

# initialize the video stream and allow the camera sensor to warm up
print("[INFO] starting video stream...")
vs = VideoStream(src=0).start()
#time.sleep(0.1)

# loop over the frames from the video stream
while True:
	# grab the frame from the video stream, resize it, and convert it
	# to grayscale
	frame = vs.read()
	frame = imutils.resize(frame, width=500)
	gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

	# perform face detection
	rects = detector.detectMultiScale(gray, scaleFactor=1.05,
		minNeighbors=5, minSize=(30, 30),
		flags=cv2.CASCADE_SCALE_IMAGE)
	count=0
	# loop over the bounding boxes
	for (x, y, w, h) in rects:
		# draw the face bounding box on the image
		cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
		count=count+1
	
	# show the output frame
	cv2.putText(frame, str(count), (200, 200), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 255))
	cv2.imshow("Frame", frame)
	
	write_read( str(count))
	key = cv2.waitKey(1) & 0xFF
	
	# if the `q` key was pressed, break from the loop
	if key == ord("q"):
		break

# do a bit of cleanup
cv2.destroyAllWindows()
vs.stop()