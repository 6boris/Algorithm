import string
import random

sscore = input('Input Your Soure:')
score = int(sscore)
degree = 'DCBAAE'
if score > 100 or score < 0:
    print('Score Wrong')
else:
    index = (score - 60)//10
    if index >= 0:
        print(degree[index])
    else:
        print(degree[-1])
