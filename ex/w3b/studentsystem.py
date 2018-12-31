class student:
    def __init__(self,name,number,courses,grades,tuition,paidInFull):
        self.name = name
        self.number = number
        self.courses = courses
        self.grades = grades
        self.tuition = tuition
        self.paidInFull = paidInFull
        
    def getName(self):
        return self.name
    def setName(self,name):
        self.name = name
        
    def getNumber(self):
        return self.number
    def setNumber(self,number):
        self.number = number
        
    def getCourses(self):
        return self.courses
    def setCourses(self,courses):
        self.courses = courses
        
    def getGrades(self):
        return self.grades
    def setGrades(self,grades):
        self.grades = grades
        
    def getTuition(self):
        return self.tuition
    def setTuition(self,tuition):
        self.tuition = tuition
        
    def getPaidInFull(self):
        return self.paidInFull()
    def setPaidInFull(self,paidInFull):
        self.paidInFull = paidInFull

def main():
    students = []
    
    while True:
        try:
            option = int(input("Enter 1 to enter new student, 2 to retrieve student information, 3 to exit: "))
        except:
            print("Please enter a valid input")
        
        if option == 1:
            firstName = ""
            lastName = ""
            number = -1
            courses = []
            grades = []
            tuition = -1
            paidInFull = False
            
            firstName = input("Enter student's first name: ")
            lastName = input("Enter student's last name: ")
            try:
                number = int(input("Enter student's number: "))
            except:
                print("Please enter a valid input")
            while True:
                course = input("Enter names of student's courses(enter stop to continue): ")
                if course == "stop":
                    break
                else:
                    courses += [course]
            for i in range(0, len(courses), 1):
                try:
                    grade = int(input("Enter grade for " + courses[i] + ": "))
                    grades += [grade]
                except:
                    print("Please enter a valid input: ")
            try:
                tuition = int(input("Enter student's tuition: $"))
            except:
                print("Please enter a valid input")
            while True:
                paidInFull = input("Enter 'yes' if student paid in full, otherwise enter 'no': ")
                if paidInFull == "yes":
                    paidInFull = True
                    break
                elif paidInFull == "no":
                    painInFull = False
                    break
                else:
                    print("Please enter a valid input")
            students += [student(firstName + " " + lastName,number,courses,grades,tuition,paidInFull)]
            
        if option == 2:
            studentIndex = -1
            number = -1
            try:
                number = int(input("Enter student's number: "))
            except:
                print("Please enter a valid input")
                
            for i in range(0, len(students), 1):
                if number == students[i].getNumber():
                    studentIndex = i
                    break
            
            if studentNumber == -1:
                print("Student does not exist.")
            
            else:
                student = students[studentIndex]
                
                firstName = student.getName().split(" ")[0]
                lastName = student.getName().split(" ")[1]
                number = student.getNumber()
                courses = student.getCourses()
                grades = student.getGrades()
                tuition = student.getTuition()
                paidInFull = student.getPaidInFull()
                
                print("Student Results")
                print("---------------")
                print("Name: " + firstName + " " + lastName)
                print("Student Number: " + number)
                print("Courses:\tGrades:")
                for i in range(0,len(courses),1):
                    print(courses[i] + "\t" + grades[i])
                print("Tuition: " + tuition)
                print("Paid In Full: " + paidInFull)
                
                    

main()
                    
        
        
    