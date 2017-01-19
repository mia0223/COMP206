#!/usr/bin/python

#Import modules for CGI handling
import cgi
print "Content-type:text/html\r\n\r\n"
#Create instance of FieldStorage
form = cgi.FieldStorage()

#Get data from fields
user=form.getvalue('user')
update = form.getvalue("status update")
update=update.rstrip()
if update != None:
	#Open a file
	appendTo = open("status.txt","a")
	#Append the data to this file
	appendTo.write(user)
	appendTo.write(" ")
	appendTo.write(update)
	appendTo.write("\n")
	#Close the file
	appendTo.close()
print """
<html>
	<br><br><br><br><br>
	<body bgcolor="D9D5D9"><center>
	<p><h3>Status has been updated!</h3></p>
	<form action="http://cgi.cs.mcgill.ca/~cwang84/dashboard.py" method="post">
	<input type="hidden" name="user" value=%s></input>
	<input type="submit" value="Go back to dashboard"></input></form></center></body>
<html>"""%user


