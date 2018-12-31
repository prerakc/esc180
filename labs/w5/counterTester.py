from counterlib import *

myCnt = counter(100)
myCnt.evolve(10)
myCnt.evolve(20)
print(myCnt.getState())

anotherCnt = counter(50)
anotherCnt.evolve(5)
anotherCnt.evolve(25)
print(anotherCnt.getState())