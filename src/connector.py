import socket
import sys

SOCKET_PATH = "/run/user/1000/openspeedrun.sock"
class IncorrectOSError(Exception):
    pass

def send_command(command):
    try:
        if sys.platform == "win32":
            raise IncorrectOSError()
        else:
            with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as client:
                client.connect(SOCKET_PATH)
                full_command = command + "\n"
                client.sendall(full_command.encode())
    except ConnectionRefusedError:
        print("The connection refused. check if open speed run is running. ")
    except IncorrectOSError:
        print("Usage with Windows not possible due to openspeedrun using unix sockets. Livesplit auttosplitter is planned in the future.")


def test():
    print("test")