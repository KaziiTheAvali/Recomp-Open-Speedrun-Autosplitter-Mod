import socket
import os

SOCKET_PATH = "/run/user/1000/openspeedrun.sock"


def send_command(command):
    try:
        with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as client:
            client.connect(SOCKET_PATH)
            full_command = command + "\n"
            client.sendall(full_command.encode())
    except ConnectionRefusedError:
        print("The connection refused. check if open speed run is running. ")
