import sys
import math
import cv2 as cv
import numpy as np

video=cv.VideoCapture(0)
#video=cv.VideoCapture('Vid2.mp4')


while True:
    ret,frame=video.read()
    frame_line = frame
    if not ret:
        pass

    dst =  cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    blur = cv.GaussianBlur(dst, (7,7), 0)
    cdst = cv.Canny(blur, 50, 130, None, 3)

        
    linesP = cv.HoughLinesP(cdst, 1, np.pi / 180, 30, 100, 1)
        
    NumLLine = 0
    NumRLine = 0
    LLineAv = np.zeros(4)
    RLineAv = np.zeros(4) # {0,0,0,0}
    try:
        for i in linesP:
            x1,x2,y1,y2=i[0]
            if x1==x2:
                continue
            Gra = (y2-y1)/(x2-x1)
            if Gra < 0 and x2 < (cdst.shape[1] / 2):
               RLineAv += i[0] # {x1,x2,y1,y2} + {1,1,1,3} = {x1+1, }
               NumRLine += 1 
            elif Gra > 0 and x1 > (cdst.shape[1] / 2):
               LLineAv += i[0] # {x1,x2,y1,y2} + {1,1,1,3} = {x1+1, }
               NumLLine += 1 
    except:
        pass


    if NumRLine > 0:
        RLineAv /= NumRLine
        x1,x2,y1,y2=RLineAv

        RGra = (y2-y1)/(x2-x1)

        interR = y1 - RGra * x1

        #
        try:
            cv.line(frame,(int(0),int(interR)), (cdst.shape[1],int(cdst.shape[1] * RGra + interR)), (0,255,0), 3)
        except:
            pass
    if NumLLine > 0:
        LLineAv /= NumLLine
        x1,x2,y1,y2=LLineAv
        cv.line(frame,(int(x1),int(x2)), (int(y1),int(y2)), (0,255,0), 3)
        
        
    cv.imshow("1-greyscale", dst)
    cv.imshow("2-canny", cdst)
    cv.imshow("final-product", frame_line)

    key=cv.waitKey(33)
    if(key==27):
        break
video.release()
cv.destroyAllWindows()


