import urllib.request
import xml.etree.ElementTree as ET

class HudsonChecker:
    def __init__(self, url):
        sock = urllib.request.urlopen(url)
        xmlstring = sock.read();
        self.root = ET.fromstring(xmlstring)
        #if root.tag != "hudson": #error

    def jobStats(self):
        numPassed = 0;
        numTested = 0;
        for elem in list(self.root):
            if elem.tag == "job":
                name = elem.find('name')
                color = elem.find('color')
                if color is None:
                    continue
                if "anime" in color.text:
                    continue
                if color.text in ( "green", "yellow" ):
                    numPassed += 1
                else:
                    print("Hundson: %s is %s" % (name.text, color.text))
                numTested += 1
        return (numPassed, numTested)

if __name__ == "__main__":
    checker=HudsonChecker("http://ics-web4.sns.ornl.gov:8185/api/xml")
    stats = checker.jobStats()
    print("Green jobs: %d/%d" % stats)
        
