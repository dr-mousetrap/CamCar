import sys
import math
import cv2 as cv
import numpy as np

video=cv.VideoCapture(0)
#video=cv.VideoCapture('Vid2.mp4')

while True:
    ret,frame=video.read()
    if not ret:
        pass

    img=cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
    blured = cv.blur(img,(9,9))
    edge=cv.Canny(blured,100,200)
    lines=cv.HoughLinesP(edge,rho =1, theta=1*np.pi/180,threshold=10, minLineLength= 100, maxLineGap= 50)

    NumLLine = 0
    NumRLine = 0
    LLineAv = np.zeros(4)
    RLineAv = np.zeros(4) # {0,0,0,0}
    try:
        for i in lines:
            x1,x2,y1,y2=i[0]
            if x1==x2:
                continue
            Gra = (y2-y1)/(x2-x1)
            if Gra < 0 and x2 < (img.shape[1] / 2):
               RLineAv += i[0] # {x1,x2,y1,y2} + {1,1,1,3} = {x1+1, }
               NumRLine += 1 
            elif Gra > 0 and x1 > (img.shape[1] / 2):
               LLineAv += i[0] # {x1,x2,y1,y2} + {1,1,1,3} = {x1+1, }
               NumLLine += 1 
    except:
        pass

    if NumRLine > 0:
        RLineAv /= NumRLine
        x1,x2,y1,y2=RLineAv
        cv.line(frame,(int(x1),int(x2)), (int(y1),int(y2)), (0,255,0), 3)

    if NumLLine > 0:
        LLineAv /= NumLLine
        x1,x2,y1,y2=LLineAv
        cv.line(frame,(int(x1),int(x2)), (int(y1),int(y2)), (0,255,0), 3)

    cv.imshow("window",frame)
    key=cv.waitKey(33)
    if(key==27):
        break
video.release()
cv.destroyAllWindows()
