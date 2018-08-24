"""
    @author: TangSan
    This is a program to solve the r/dailyprogrammer challenge 366 Easy: Word funnel 1 which can be found at:
    https://www.reddit.com/r/dailyprogrammer/comments/98ufvz/20180820_challenge_366_easy_word_funnel_1/
    The goal is, given two strings of letters, determine whether the second can be made from the first by removing one
    letter. The remaining letters must stay in the same order.
"""


def loadWords():
    # For bonus
    file = open('enable1.txt')
    stringList = str(file.read()).split('\n')
    file.close()
    return set(stringList)


def funnel(string1, string2):
    """
        Input: Takes in 2 strings
        Effect: Return True if the second string can be made by removing a single letter from the first
                Else return False
    """
    if (len(string1) - len(string2)) != 1:
        return False
    for i in range(len(string1)):
        funneled = string1[:i]+string1[i+1:]
        if funneled == string2:
            return True
    return False


def bonus1(string, words):
    """
        Bonus 1: Given a string, find all words from the enable1 word list that can be made by removing one letter from
        the string.
    """
    funneled = set()
    for i in range(len(string)):
        funneled_string = string[:i]+string[i+1:]
        if funneled_string in words:
            funneled.add(funneled_string)
    return funneled


def bonus2():
    """
    Given an input word from enable1, the largest number of words that can be returned from bonus(word) is 5.
    One such input is "boats". There are 28 such inputs in total. Find them all.
    :return: All 28 inputs
    """
    funnel5 = {}
    slist = loadWords()
    for string in slist:
        # to have 5 words returned, the length of i must be at least 5
        if len(string) > 4:
            matches = bonus1(string, slist)
            if len(matches) >= 5:
                funnel5[string] = matches
    return funnel5
