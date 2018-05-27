import math

def main():

    x1,y1 = [float(i) for i in raw_input().split(' ')]
    x2,y2 = [float(i) for i in raw_input().split(' ')]

    print("%.4f" % math.sqrt(math.pow( (x2-x1),2) + math.pow( (y2-y1),2)));

main()