def read_sentence(N):
    s=""
    for i in range(N):
        s=s+input()+" "
    return s

    
def read_words(T):
    w=[]
    for i in range(T):
        w.append(input())
    return w

def find_words_count(s,T,w):
    cleaned=s.replace("("," ").replace(")"," ").replace("-"," ").replace("'"," ").replace(","," ").replace("."," ")
    s_words=cleaned.split()

    for i in range(T):
        count=0
        for x in s_words:
            if x == w[i]:
                count+=1
        print(count)
    

N=int(input())
s=read_sentence(N)
T=int(input())
w=read_words(T)
find_words_count(s,T,w)
