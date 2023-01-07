import libtelefork


def f():
    # print("CHILD")
    # a = 1
    return 1


print(hex(id(f)))
dest = "127.0.0.1:7335"
ret = libtelefork.py_telefork(dest, id(f))
print("ret:", ret)

i = 0
while True:
    i += 1
