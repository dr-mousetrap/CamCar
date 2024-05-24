import sys
import math
import cv2 as cv
import numpy as np
 
 
def main(argv):
 video = cv.VideoCapture('Vid1.mp4')

 
 # Loads an image
 ret,frame=video.read()
 if not ret:
        pass

 
 src = cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
 
 # Check if image is loaded fine
 if src is None:
    print ('Error opening image!')
    # print ('Usage: hough_lines.py [image_name -- default ' + default_file + '] \n')
    return -1
 
 print("a")
 
 dst = cv.Canny(src, 50, 150, None, 3)
 cv.imshow("test", dst)
 
 # Copy edges to the images that will display the results in BGR
 cdst = cv.cvtColor(dst, cv.COLOR_GRAY2BGR)
 cdstP = np.copy(cdst)
 
 
 lines = cv.HoughLines(dst, 1, np.pi / 180, 150, None, 0, 0)
 
 if lines is not None:
    print("u")
    for i in range(0, len(lines)):
        rho = lines[i][0][0]
        theta = lines[i][0][1]
        a = math.cos(theta)
        b = math.sin(theta)
        x0 = a * rho
        y0 = b * rho
    pt1 = (int(x0 + 1000*(-b)), int(y0 + 1000*(a)))
    pt2 = (int(x0 - 1000*(-b)), int(y0 - 1000*(a)))
    
    cv.line(cdst, pt1, pt2, (0,0,255), 3, cv.LINE_AA)
    
    
    
    linesP = cv.HoughLinesP(dst, 1, np.pi / 180, 50, None, 50, 10)
    
    if linesP is not None:
        print("e")
        for i in range(0, len(linesP)):
            l = linesP[i][0]
            cv.line(cdstP, (l[0], l[1]), (l[2], l[3]), (0,0,255), 3, cv.LINE_AA)
            cv.imshow("window",cdst)
    
        # cv.imshow("Source", src)
        
        
    
        cv.waitKey() 
        video.release()
        cv.destroyAllWindows()
        # return 0
 
 
if __name__ == "__main__":
 main(sys.argv[1:])

  