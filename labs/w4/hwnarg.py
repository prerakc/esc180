# This is an example of a program that will take in arguments.
# It is best to name your arguments rather than relying on position;
# this enables a user to use your program without memorizing
# argument order. This is a standard industrial practice.
# Below, you see that there are two named arguments that each take
# an additional parameter:
# --fin <ADDITIONAL-PARAM> --fout <ADDITIONAL-PARAM>
# This may be used in a program that takes in the name of
# an input and output file, in order to do further processing.
# You may modify this template for your purposes.
#
# The loop that is iterating over all the input arguments begins at
# 1, since sys.argv[0] is always the name of the program
# (in this case, "argtest.py", unless you renamed it).
# The loop is incrementing one arg at a time; since --fin and --fout
# take an additional argument, I created a variable called "skip"
# that enables you to skip over the filename during the looping
# since the --fin and --fout processing will always look at and
# consume the next argument. Note that I test to ensure
# --fin or --fout always have a trailing argument. Otherways, the
# program will give an "out of range" warning.
#
# This is course content. You must understand this. To understand this
# use it, modify it and experiment with it.
#
# usage: python argtest.py --fin blah_in --fout blah_out
# where you may change the names blah_in and blah_out as needed
#
# mathaine@ecf.utoronto.ca


import sys

n=""
word=""
nargs=len(sys.argv)
skip=False
for i in range(1,nargs):
   if not skip:
      arg=sys.argv[i]
      print("INFO: processing",arg)
      if arg == "--n":
         if i != nargs-1:
            n=sys.argv[i+1]
            skip=True
      elif arg == "--word":
         if i != nargs-1:
            word=sys.argv[i+1]
            skip=True
      else:
         print("ERR: unknown arg:",arg)
   else:
      skip=False

print("INFO: n",n)
print("INFO: word",word)