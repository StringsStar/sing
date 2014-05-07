#!/usr/bin/env python
# -*- coding:utf-8 -*-
from socket import *
from time import ctime

HOST = '192.168.10.20'
PORT = 1024
BUFSIZE = 1024
ADDR = (HOST, PORT)

tcpSock = socket(AF_INET, SOCK_STREAM)
tcpSock.bind(ADDR)
tcpSock.listen(5)

try:
  while True:
	print 'waiting For connection'
  	CSock, addr = tcpSock.accept()
	print '..connect from:', addr
	  while True:
		CSock.send('Yes I do I do')



CSock.close()
tcpSock.close()
