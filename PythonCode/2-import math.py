import cv2 as cv

image =  cv.imread('2.png')
(b_channel, g_channel, r_channel) = cv.split(image)
edge_image = cv.Canny(g_channel, 300, 300)
cv.imshow("edgeDetection", edge_image)
cv.waitKey(0) 
