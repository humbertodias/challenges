a=gets.to_i
print "%d ano(s)\n" % (a/365)
print "%d mes(es)\n" % ((a%365)/30) 
print "%d dia(s)\n" % ((a%365)%30)