import math
import numpy as np
import csv

seconds_in_day = 86400

def getJdAndFr(jd_ep, fr_ep, x):
    jd = jd_ep + math.floor(x / seconds_in_day)
    fr = fr_ep + (x % seconds_in_day) / seconds_in_day
    return jd, fr

def GetJdAndFrArrayForSattelite(sat, time_points):
    jd_list = []
    fr_list = []

    jd_ep = sat.jdsatepoch
    fr_ep = sat.jdsatepochF

    for time_point in time_points:
        jd, fr = getJdAndFr(jd_ep, fr_ep, time_point)
        jd_list.append(jd)
        fr_list.append(fr)

    jd = np.array(jd_list)
    fr = np.array(fr_list)

    return jd, fr

def savePointToFile(point, time_points, name):
    with open('data/' + name + ".csv", 'w') as file:
        writer = csv.writer(file)
        writer.writerow(['distance', 'time'])
        for row in range(len(time_points)):
            writer.writerow([point[row], time_points[row]])
        file.close()