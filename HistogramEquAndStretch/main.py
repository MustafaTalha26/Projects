import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt

# 1306200015 - Mustafa Talha Mert
# Image Processing - Histogram Stretching and Histogram Equalization
# Visual Studio Code - OpenCV - Python
# Caution! It might take 1-2 minute

#
# Histogram Stretcher
# We take the risk of noise in exchange for more efficiency in this function
# Higher tolerance "tolPercent" means more noise yet more efficiency 
# 
def histoStr(img,min,max):
    img = np.asarray(img)
    flat = img.flatten()
    count = len(flat)
    tolPercent = count/10000
    oldmin = flat.min()
    oldmax = flat.max()
    pixelCount = 0
    minFlag = 0

    # This section used for finding smaller interval(bigger min,smaller max) of colors
    for i in range(oldmin,oldmax+1):
        for a,pixelColor in enumerate(flat):
            if(pixelColor == i):
                pixelCount += 1
        if(pixelCount > tolPercent):
            oldmax = i
            if(minFlag == 0):
                oldmin = i
                minFlag = 1
        pixelCount = 0

    # This section is the formula of Histogram Strecthing
    k = (max-min)/(oldmax - oldmin)
    for i,item in enumerate(flat):
        flat[i] = k*(item-oldmin)+min

    str = flat.reshape(img.shape)
    return str

#
# Histogram Equalization
# We take the risk of noise in exchange for more efficiency in this function
# Higher tolerance "tolPercent" means more noise yet more efficiency 
#
def histoEqu(img):
    img = np.asarray(img)
    flat = img.flatten()
    totalCount = len(flat)
    tolPercent = totalCount/10000
    minFlag = 0
    min = flat.min()
    max = flat.max()
    pixelCount = 0
    cumsum = 0
    hist = [0] * 256

    # This section used for finding smaller interval(bigger min,smaller max) of colors
    for i in range(min,max+1):
        for a,pixelColor in enumerate(flat):
            if(pixelColor == i):
                pixelCount += 1   
        if(pixelCount > tolPercent):
            max = i
            if(minFlag == 0):
                min = i
                minFlag = 1
        pixelCount = 0

    # This section is used for Cumulative_Probability equation.
    # We stored changed values of histogram in "hist" 
    for i in range(min,max+1):
        for a,pixelColor in enumerate(flat):
            if(pixelColor == i):
                pixelCount += 1
        cumsum += pixelCount/totalCount
        hist[i] = round(cumsum * 255)
        pixelCount = 0

    # We implemented the hist on picture in this section
    for a,color in enumerate(range(len(flat))):
       flag = 1
       for i,c in enumerate(range(len(hist))):
            if (flat[a] == i and flag == 1):
               flat[a] = hist[i]
               flag = 0

    equ = flat.reshape(img.shape)
    return equ

# This function is used for showing diagram and picture
def showNpArr(img):
    img = np.asarray(img)
    flat = img.flatten()
    plt.hist(flat, bins = 50)
    plt.show()
    return img

img = cv.imread('arabam.jpg', 0)
str = histoStr(img,0,255)
equ = histoEqu(img)
cv.imshow("normal",img)
showNpArr(img)
cv.imshow("streched",str)
showNpArr(str)
cv.imshow("equalized",equ)
showNpArr(equ)

collage = np.concatenate((img, str, equ), axis=1)
cv.imwrite('out.png', collage)
img2 = cv.imread('out.png', 0)
cv.imshow("collage",img2)

cv.waitKey(0)