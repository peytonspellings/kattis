#!/usr/bin/python3

line = input()
splitLine = line.split(' ')
n = int(splitLine[0])
m = int(splitLine[1])
s = int(splitLine[2])
t = int(splitLine[3])

adjList = []
for i in range(n):
  adjList.append([])

for i in range(m):
  line = input()
  splitLine = line.split(' ')
  v = int(splitLine[0])
  w = int(splitLine[1])

  adjList[v].append(w)
  adjList[w].append(v)

squawksIn = []
squawksOut = []

for i in range(n):
  squawksIn.append(0)
  squawksOut.append(0)

squawksOut[s] = 1

for i in range(t):
  for v in range(n):
    for w in adjList[v]:
      squawksIn[w] += squawksOut[v]
  for v in range(n):
    squawksOut[v] = squawksIn[v]
    squawksIn[v] = 0

totalSquawks = 0
for i in range(n):
  totalSquawks += squawksOut[i]

print(totalSquawks)

