from conwaylib import *
from random import randint
from time import sleep
from rule import rule
import os

H=22
V=40
C=conway(H,V,'zeros')

C.setPos(10,1,1)
C.setPos(9,1,1)
C.setPos(12,1,1)
C.setPos(10,0,1)
C.setPos(11,0,1)
C.setPos(10,2,1)
C.setPos(11,2,1)

C.setPos(10,11,1)
C.setPos(11,12,1)
C.setPos(12,10,1)
C.setPos(12,11,1)
C.setPos(12,12,1)

n=0
while True:
   C.evolve(rule)
   os.system('clear')
   C.printDisp()
   print("STEP:",n)
   sleep(0.1)
   n=n+1
