#Creates a list of potential passwords
def makeList(fname):
	startList = []
	doubleWordList = []
	numbers = ['0','1','2','3','4','5','6','7','8','9']
	numberList = []
	finalList = []
	#Get the list of words from file fname
	with open(fname) as f:
		startList = f.readlines()
    #Create word pairs
	for item in startList:
		for i in startList:
			tempWord = "%s%s" % (item.replace("\n",""),i.replace("\n",""))
			doubleWordList.append(tempWord)
	#Creates the number pairs omitting duplicates such as 11, 99, etc
	for n in numbers:
		tempnums = numbers
		for num in tempnums:
			#p = 1
    		#if not num == n:
			numberList.append(str(n) + str(num))
	for item in doubleWordList:
		for num in numberList:
			finalList.append(str(item + num))
	#print to output file
	outputfile = open('passwordList.txt','w')
	#for word in finalList:
	#	print>>outputfile, word
	outputfile.write("\n".join(finalList))
    
makeList('testFile')	##REPLACE testFile with your file name HERE
