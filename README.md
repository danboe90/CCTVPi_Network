# CCTVPi_Network

## Introduction and Motivation
This project has been one of our projects during the studies at the UAS FH Technikum Wien. The implementation of this project relies on the ideas gathered from the Workshop in Embedded Software.
The here presented implementation contains some of the methods already implemented.
However, the rest of the functionality has been implemented on my very own.

The entire network consists of nodes. Each node is represented as a Raspberry Pi 2 (or later) running one of the node-applications.
The designed protocoll is capable of covering one network consisting of:
- max. 1 control-node
- min. 1 display-node
- min. 1 camera-node
- min. 1 authentication-node

## Content
This repository will contain:
- [x] Folder ctrl containing the QT project for a control-node
- [ ] Folder auth containing the QT project for an authentication-node
- [ ] Folder disp containing the QT project for an display-node
- [ ] Folder cam containing the QT project for a camera-node

For more information about the nodes, please visit the corresponding folders

## Licence
Copyright (c) 2017 Daniel B.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
