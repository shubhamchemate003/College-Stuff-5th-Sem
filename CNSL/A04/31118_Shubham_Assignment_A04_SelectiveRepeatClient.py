import socket,os,subprocess,time

host="172.20.10.2"
port=9999
s=socket.socket()

s.connect((host,port))
n=9
i,j=0,4
while True:
    data = s.recv(1024)
    data = data.decode('utf-8')
    if data == "All sent":
        print("Thank you")
        break
    print(f"Received: {data}")
    time.sleep(1)
    if input(f'Send ACK for {data}: ') == 'y':
        s.send(str.encode(f"ACK-{data} "))
    else:
        s.send(str.encode(f"NACK-{data} "))