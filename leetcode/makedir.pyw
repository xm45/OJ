#coding=utf8
import os,sys
num = 377
for i in range(1,num+1):
	if not os.path.isdir(str(i)):
		os.mkdir(str(i))