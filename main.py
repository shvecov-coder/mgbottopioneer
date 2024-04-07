import socket
from pioneer_sdk import Pioneer

server_addr = ''
port_addr = 50007
mini = Pioneer(ip='192.168.0.103')

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((server_addr, port_addr))
    s.listen(1)

    while True:
        conn, addr = s.accept()

        with conn:
            print(f'Connected by {addr}')
            while True:
                data = conn.recv(1024)
                if not data:
                    break
                print(data)
                try:
                    eval(data)
                except:
                    print('Unknown command...')
