class counter:
    def __init__(self, initCnt):
        self.cnt = initCnt
    def evolve(self, x):
        self.cnt = self.cnt + x
    def getState(self):
        return self.cnt