from HudsonChecker import HudsonChecker
import serial #pySerial library
import time
import sys

if len(sys.argv) < 2 or len(sys.argv) > 3:
    print("Usage: python HudsonCompanion.py <port> (<url>)")
else:
    if len(sys.argv) == 3:
        url = sys.argv[2]
    else:
        url = "http://ics-web4.sns.ornl.gov:8185/api/xml"
    stats = HudsonChecker(url).jobStats()
    stats = str(int(100*stats[0]/stats[1]))
    data = stats.encode('utf-8')
    print(stats)
    print(data)

    ser = serial.Serial(port=sys.argv[1], timeout=5)
    readout = ser.read(1) #wait until signal sent to write
    ser.write(data)
    while readout and readout != '\n' and readout != '\r':
        print(readout.decode('utf-8'), end="", flush=True)
        readout = ser.read()
    print("^C to exit")
    while True: #endless loop, prevents Serial close and reset
        time.sleep(1)
