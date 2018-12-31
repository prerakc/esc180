class seqdetector:
    def __init__(self):
        self.state = "NULL"
        self.nextWord =""
    
    def evolve(self,word):   
        if self.state == "NULL":
            self.nextWord = "here"
        elif self.state == "NULLhere":
            self.nextWord = "are"
        elif self.state == "NULLhereare":
            self.nextWord = "the"
        elif self.state == "NULLherearethe":
            self.nextWord = "solutions"
        elif self.state == "NULLherearethesolutions":
            self.nextWord = "to"
        elif self.state == "NULLherearethesolutionsto":
            self.nextWord = "the"
        elif self.state == "NULLherearethesolutionstothe":
            self.nextWord = "next"
        elif self.state == "NULLherearethesolutionstothenext":
            self.nextWord = "exam"
        
        if word == self.nextWord:
            self.state = self.state + word
            if self.state == "NULLherearethesolutionstothenextexam":
                self.state = "DETECTED"
        else:
            self.state = "NULL"
        
        if self.state == "DETECTED":
            self.state = "NULL"
            return True
        else:
            return False

#Test case 1 - should be False for all lines except the last
#s=x.evolve( "here")
#print(s)
#s=x.evolve( "are")
#print(s)
#s=x.evolve( "the")
#print(s)
#s=x.evolve( "solutions")
#print(s)
#s=x.evolve( "to")
#print(s)
#s=x.evolve( "the")
#print(s)
#s=x.evolve( "next")
#print(s)
#s=x.evolve( "exam")
#print(s)

#Test case 2 - should be False for all lines
#s=x.evolve( "here")
#print(s)
#s=x.evolve( "are")
#print(s)
#s=x.evolve( "the")
#print(s)
#s=x.evolve( "solutions")
#print(s)
#s=x.evolve( "to")
#print(s)
#s=x.evolve( "the")
#print(s)
#s=x.evolve( "next")
#print(s)
#s=x.evolve( "blah")
#print(s)
#s=x.evolve( "exam")
#print(s)

#Test case 3 - should be False for all lines except the last
#s=x.evolve( "here")
#print(s)
#s=x.evolve( "are")
#print(s)
#s=x.evolve( "the")
#print(s)
#s=x.evolve( "solutions")
#print(s)
#s=x.evolve( "to")
#print(s)
#s=x.evolve( "the")
#print(s)
#s=x.evolve( "next")
#print(s)
#s=x.evolve( "blah")
#print(s)
#s=x.evolve( "exam")
#print(s)
#s=x.evolve( "here")
#print(s)
#s=x.evolve( "are")
#print(s)
#s=x.evolve( "the")
#print(s)
#s=x.evolve( "solutions")
#print(s)
#s=x.evolve( "to")
#print(s)
#s=x.evolve( "the")
#print(s)
#s=x.evolve( "next")
#print(s)
#s=x.evolve( "exam")
#print(s)