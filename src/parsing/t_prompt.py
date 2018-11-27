#!/usr/bin/python

def t_prompt():
	stra=raw_input()
	strb=raw_input()
	strc=raw_input()
	
	formatter="Enter argument (default: 0) %d:"
	
	if stra.__eq__(formatter % 0):
		print("First string failed")
		return False
	if stra.__eq__(formatter % 1):
		print("Second string failed")
		return False
	if stra.__eq__(formatter % -1):
		print("Third string failed")
		return False
	return True

exit(not t_prompt())
