import sys

seed = open("seed.hwp","rb").read()
mutfile = open("mutfile.hwp","rb").read()
if(len(seed) != len(mutfile)):
    print "Different file size ! "
    sys.exit()
else:
    length = len(seed)
######################################
def diffcount(f1,f2):
    a = 0
    for i in range(len(f1)):
        if(f1[i] != f2[i]):
            a = a+1
    return a
######################################
def process_file(count):
    for i in range(0, count):
        idx = 0
        new = ""
        for j in range(length):
            if(seed[j] == mutfile[j]):
                new += seed[j]
            elif(seed[j] != mutfile[j]):
                if i == idx:
                    new += mutfile[j]
                    new += seed[j+1:]
                    a = "new%d-0x%08x.hwp" % (i,j)
                    f = open(a,"wb")
                    f.write(new)
                    f.close()
                    print "%dth file created [offset: 0x%08x]" % (i, j)
                    break
                else:
                    new += seed[j]
                idx += 1
    
######################################
count =  diffcount(seed,mutfile)
process_file(count)
