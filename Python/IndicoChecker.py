"""
Checks number of registrants for an Indico web site
"""
import urllib.request
import re

class IndicoChecker:
    def __init__(self, url="https://conference.sns.gov/event/11/registration/registrants"):
        sock = urllib.request.urlopen(url)
        html = sock.read();
        m = re.search('Number of participants: ([0-9]+)', str(html))
        self.participants = int(m.group(1))


if __name__ == "__main__":
    checker = IndicoChecker()
    print("Participants: %d" % checker.participants)
        
