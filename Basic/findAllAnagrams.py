# reference: https://leetcode.com/problems/find-all-anagrams-in-a-string/

def findAllAnagrams(word, p):
    indexes = []

    map_p = {}
    for letter in p:
        if (letter in map_p):
            map_p[letter] += 1
        else:
            map_p[letter] = 1


    map_word = {}

    # base case
    for letter in word[:len(p)]:
        if (letter in map_word):
            map_word[letter] += 1
        else:
            map_word[letter] = 1

    if (map_word == map_p):
        indexes.append(0)

    # general case
    for i in range(1, len(word)-len(p)+1):

        map_word[word[i-1]] -= 1

        letter = word[i+len(p)-1]
        if (letter in map_word):
            map_word[letter] += 1
        else:
            map_word[letter] = 1

        if (map_word[word[i-1]] == 0):
            map_word.pop(word[i-1])

        if (map_word == map_p):
            indexes.append(i)
        
    return indexes



string_s = str(input('String 1: '))
string_p = str(input('String 2: '))

result = findAllAnagrams(string_s, string_p)
print(result)