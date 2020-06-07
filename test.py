# -*- coding: utf-8 -*-
"""
Created on Fri May  8 16:54:11 2020

@author: vishn
"""
import serial #importing serial library
send_serial = serial.Serial('COM6', 115200, timeout=1)  

from flask import Flask, request, render_template
app = Flask(__name__)
@app.route('/test', methods=['GET', 'POST'])
def test():
    if request.method == 'POST':
        option = request.form["speed"]
        send_val(option)                #taking the value the user entered in website and calling send_val function
        return render_template('test.html')
    elif request.method == 'GET':
        return render_template('test.html')
    else:
        return render_template('test.html')
        
    
def send_val(option):
    send_serial.write(option.encode())  #write the value recieved from website to serial
    recv = send_serial.read(4)          #reading the data sent by arduino
    print(recv)                         #printing