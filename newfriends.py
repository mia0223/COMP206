#!/usr/bin/python
import sys
import os
import cgi, cgitb

print "Content-type:text/html\r\n\r\n"
print '<html><body bgcolor="D9D5D9"><font face="Comic sans Ms"><div><center><h1>Friends Added!</h1></center></div>'
print "<body><center>"
form = cgi.FieldStorage()
me = form.getvalue("user")
name=form.getlist("friends")
print name
newlist=[]
if name==None:
	print"""<form action="dashboard.py" method="post"><input type="hidden" name="user" value=%s></input><input type="submit" value="Back to dashboard"></input></form></body></html>"""%(me)

else:
	print "<br>"
	ref=open("friends.txt", "a+")
	new=open("newfriends.txt","w+")

	for line in ref.readlines():
		if(line=="\n"): break
		namelist=line.split()
		if namelist[0] == me:	
			line=line.rstrip()
			for friend in name:
				if friend not in namelist:
					line=line+' '+friend
					newlist+=[friend] 	
			line=line+'\n'
		new.write(line)
	new.close()
	ref.close()
	print newlist
	new=open("newfriends.txt", "r")
	mutual=open("mutual.txt", "w")
	for line in new.readlines():
		if(line=="\n"):break
		namelist=line.split()
		if namelist[0] in newlist:
			line=line.rstrip()
			line+=" "+me+"\n"
		mutual.write(line)
	mutual.close()
	new.close()
	os.system('rm newfriends.txt')	
	os.system('mv mutual.txt friends.txt')
print """
<html><body><center>
<form action="dashboard.py" method="post">
<input type="hidden" name="user" value=%s></input>
<input type="submit" value="Back to dashboard"></input>
</form></center></body></html>"""%(me)

