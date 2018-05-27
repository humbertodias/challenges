a=int(raw_input())
print "%d ano(s)" % (a/365)
print "%d mes(es)" % ((a%365)/30) 
print "%d dia(s)" % ((a%365)%30)