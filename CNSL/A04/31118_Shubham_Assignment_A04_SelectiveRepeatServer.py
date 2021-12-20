import socket
import sys,time

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

def socket_accept():
    global host
    global port
    global s
    try:
        connection,address=s.accept()
        print(f"connection: {connection}\naddress: {address}")
        send_commands(connection)
        if connection:
            connection.close()
    except socket.error as e:
        print("Socket accept error: ",e,"\nRetrying...")
        socket_accept()


def send_commands(connection):
    n=10
    packets=list(str(i) for i in range(n))
    ack=[0]*n
    i,j=0,4
    while True:
        for data in packets[i:j]:
            if not ack[int(data)]:
                print(f"Sending {data}", end=" ")
                for t in range(5):
                    print(end=".")
                    time.sleep(0.5)
                connection.send(str.encode(data))
                print()
        time.sleep(5)
        responses = str(connection.recv(1024), 'utf-8').split()
        for data in packets[i:j]:
            try:
                response=responses.pop(0)
            except:
                break
            response=response.split('-')
            if response[0]=='ACK' and int(response[1])<n and (not ack[int(response[1])]):
                print("-".join(response))
                ack[int(response[1])]=1
        for data in packets[i:j]:
            if not ack[int(data)]:
                break
            else:
                i,j=i+1,j+1
        if i==len(packets):
            print("All sent")
            connection.send(str.encode("All sent"))
            break



def main():
    create_socket()
    bind_socket()
    socket_accept()

main()