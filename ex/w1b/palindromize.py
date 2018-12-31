def Palindromize(word):
    reverse = ""
    for letter in word:
        reverse = letter + reverse
    return word[0:len(word)-1]+reverse

print(Palindromize("abcd"))