"""
@author: TangSan
This is a program to solve the r/dailyprogrammer challenge 364 Intermediate: Ducci Sequence
https://www.reddit.com/r/dailyprogrammer/comments/8sjcl0/20180620_challenge_364_intermediate_the_ducci/\

"""

def nextSequence(t):
    """
    :t is tuple or list:
    :return tuple containing difference between different neighboring elements:
    """
    newSequence = []
    length = len(t)
    for i in range(length):
        newSequence.append(abs(t[i%length]-t[(i+1)%length]))
    return tuple(newSequence)

def ducciSequence(t):
    """
    :param t is the first list/tuple:
    :returns number of times it takes to enter a repeating pattern or become all 0s:
    """
    #set sequences[0] to be a tuple same length as t full of 0s
    sequences = [(), ()]
    for i in t:
        sequences[0] + (0,)
    #set sequence[1] to be the input tuple
    sequences[1] = t[:]
    currentStep = 1
    while True:
        new = nextSequence(sequences[currentStep])
        print(new)
        currentStep += 1
        if new in sequences: #Loop keeps going until a sequence has repeated
            break
        else:
            sequences.append(new)

    print(currentStep, "steps")
