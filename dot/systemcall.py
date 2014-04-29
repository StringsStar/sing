#!/bin/env python
#coding: utf-8
import subprocess
import os
import time

p = subprocess.Popen('ls -l',shell=True,stdout=subprocess.PIPE,stderr=\
	subprocess.STDOUT)	#subprocess Popen对象是一个类,后面是初始化参数
for line in p.stdout.readlines():	#PIPE的话,stdout将会是一个文件
	print line,		# ','是打印不换行的意思

os.system('ls')		#不能获取返回状态

#subprocess 可以正常显示中文信息 popen不能
#因此subprocess优先使用 os.system在不需返回状态时使用
tmp = os.popen('ls').readlines()
print tmp

# 做一个定时闹钟
# time.time() 返回时间戳
# time.localtime(seconds) 转换为本地时间 返回的是一个元组,只好通过指针访问
# time.mktime() tuple--> floating seconds
# time.clock() current floating seconds
i=1
while 1:
	t = time.localtime(time.time() )
	if(t[3]==15 and t[4]==36):
  		print 'now it is the time'
	time.sleep(1)
	print time.clock()
	print time.ctime(time.time() )
