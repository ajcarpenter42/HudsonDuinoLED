from HudsonChecker import HudsonChecker
from IndicoChecker import IndicoChecker
import serial #pySerial library
import time
import sys

if len(sys.argv) < 2 or len(sys.argv) > 3:
    print("Usage: python Combined.py <port> (<url>)")
else:
    if len(sys.argv) == 3:
        url = sys.argv[2]
    else:
        url = "http://ics-web4.sns.ornl.gov:8185/api/xml"

    ser = serial.Serial(sys.argv[1], 9600, timeout=5, xonxoff=0, rtscts=0)
    # Wait for Arduino to boot up after opening the serial line reset it
    time.sleep(5)
    readout = ser.read(1) #wait until signal sent to write

    while True:
        print("Checking Hudson status")
        stats = HudsonChecker(url).jobStats()
        print("Hudson: " + stats)

        print("Checking Indico")
        p = IndicoChecker().participants
        print("Participants: " + p)

        perc = int(100*stats[0]/stats[1])
        if perc >= 100:
            data = "H @"
        else:
            data = "H " + str(perc) + "%"

        data = data + " E " + str(p)

        data = data + "\n"

        data = data.encode('utf-8')
        print(data)
    
        ser.write(data)
        while readout:
            print(readout.decode('utf-8'), end="", flush=True)
            readout = ser.read()
        print("^C to exit")
        time.sleep(10)
