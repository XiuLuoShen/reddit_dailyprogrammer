# -*- coding: utf-8 -*-
"""
Created on Thu Jun 14 13:13:54 2018
This is a program to complete the I before E except after C 
Reddit challenge 363, Level: Easy
https://www.reddit.com/r/dailyprogrammer/comments/8q96da/20180611_challenge_363_easy_i_before_e_except/
A word follow the rule  if neither "ei" nor "ie" appears anywhere in the word.
The rule is:
    If "ei" appears in a word, it must immediately follow "c".
    If "ie" appears in a word, it must not immediately follow "c".

@author: TangSan
"""

def followsRule(word):
    ''' word: a string
        Takes in word and determines if it follows the rule 
    '''
    word = word.lower()
    
    #A word with 'cie' is automatically an exception
    if word.find('cie') >= 0:
        return False
    
    ei_index = word.rfind('ei')
    # A word that starts with ei is an exception
    if ei_index == 0:
        return False
    
    # If it passes the first two tests we go through the entire word
    valid = True
    while ei_index > 0 and valid:
        word_copy = word[:ei_index+1]
        try:
            if word_copy[-2] != 'c':
                valid = False
                break
            else:
                 ei_index = word_copy.rfind('ei')
        except IndexError:
            valid = False
            break    
    
    ie_index = word.rfind('ie')
    while  ie_index >= 0 and valid:
        word_copy = word[:ie_index+1]
        # use word copy because need to check the entire word again later
        try:
            if word_copy[-2] == 'c':
                valid = False
                break
            else:
                 ie_index = word_copy.rfind('ie')
        except IndexError:
            break
    
    return valid

    

exceptions = 0
bonus1 = open("bonus1.txt", 'r')
list = str(bonus1.read()).split('\n')
bonus1.close

for word in list:
    if not followsRule(word):
        exceptions += 1
print("Exceptions:", exceptions)
