#!/usr/bin/python
import sys
import os
import stat
import cgi, cgitb
form=cgi.FieldStorage()
user=form.getvalue("user")
print "content-type:text/html\n\n"
print "<html> <head> <title> make a friend </title> </head> <body bgcolor=\"D9D5D9\"><font face=\"Comic sans Ms\"><center>"
print "<h1> Add new friends!</h1>"
print '<form action="http://cgi.cs.mcgill.ca/~cwang84/newfriends.py" method="post">'
input = open("users.txt", "r")
while 1:
	l1=[]
	l2=[]
	Username = input.readline().split()
	if not Username:	break
	for token in Username:
		l1=l1+[token," "]
	l1.pop()
	s1=""
	for string in l1:
		s1=s1+string
	Fullname = input.readline().split()
	for token in Fullname:
		l2=l2+[token," "]
	s2=""
	l2.pop()
	for string in l2:
		s2=s2+string
	print '<input type="checkbox" name="friends" value=%s>Username:%s&nbsp Fullname: %s</input>'%(s1,s1,s2)
	print "<br>"
	input.readline()
	input.readline()
input.close()

form = cgi.FieldStorage()
me = form.getvalue("user")
print '<input type="hidden" name="user" value=%s>'%user 
print "<input type=\"submit\" value=\"add friends!\">"
print "</form></body></html>"


