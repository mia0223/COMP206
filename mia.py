#!/usr/bin/python
import cgi,cgitb
import sys
import os

form = cgi.FieldStorage()
print "Content-Type:text/html\n\n"
print "<html><head><title>hello world</title>Mia</head><body>"
print "%s <br>"%form
'''if form.has_key("name"):
	vlaue = form["name"]
	print "<br>"value"<br>"
	#print "hello"'''
input = form.getvalue("All Mango")
print "%s<br>"%input
print "hello world<br>"
print "</body></html>"

