#coding=utf8
import os,sys
num = 377
for i in range(1,num+1):
	dirname = "%03d"%i;
	#print(dirname)
	if not os.path.isdir(dirname):
		os.mkdir(dirname)
