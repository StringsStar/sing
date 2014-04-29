#!/usr/bin/env python
# -*- coding:utf-8 -*-
import os,sys,time
import re
from stat import *

filename = "D:\\script\\helo.txt"
TimeForChange = '2014-04-30 14:51:21'

#转换时间格式为long型
ConverTime = time.mktime(time.strptime(TimeForChange,'%Y-%m-%d %H:%M:%S') )
print TimeForChange + '转换后' + str(ConverTime)

def GetFileAttr():
	statinfo = os.stat("D:\\script\\helo.txt")
	print statinfo.st_size
	print time.ctime(statinfo.st_atime)
	print time.ctime(statinfo.st_mtime)
	print time.ctime(statinfo.st_ctime)

GetFileAttr()

times=(ConverTime, ConverTime)
os.utime(filename,times)
GetFileAttr()

#遍历文件
regex_cpp=ur".*\.cpp"
regex_h=ur".*\.h"
regex_rc=ur".*\.rc"
def walkdir(dirname):
	ls=os.listdir(dirname)
	for l in ls:
		temp=os.path.join(dirname,l)
		if(os.path.isdir(temp)):
			walkdir(temp)
		else:
			if(re.match(regex_cpp,temp) or \
				re.match(regex_h,temp) or re.match(regex_rc,temp)):
				os.utime(temp,times)
				print(temp)


walkdir("D:\\Code\\Card24GDemo")
