BUILD:
----
We need to seperate builds of [telefork](https://github.com/trishume/telefork)
The version under `deps/telefork` wraps the two main functions needed
`telefork` and `telepad`

If you need to debug somehting create a second copy of the `telefork` repo,
which will remain untouched. See `DEBUG` for why you have to do this.

First run:
```bash
setup.sh
```
to create all needed files.


TODO:
----
- shell script zum aufsetztne einer testumgebung
- patch extracten erst wenn python fertig ist.
- cbindgen script
- telepad in rust exportieren
- telepad/telefork via some kind of SSH/TLS
- add build commands to readme
- die ganzen error msg is telefork mal verständlicher machen. das versteh kaum einer was da ab geht.
- vll auch das verwenden fur das python interface: https://github.com/pyo3/pyo3
- vll ist auch die lösung ganz anders [hier](https://pyo3.rs/latest/python_from_rust.html)
	gibt es typen die das vll auch cönnen
- python currently not working because `libpython` which is linked into it is transferred into remote, but not mmaped into remote

DEBUG:
----
Turns out debugging is a lot more difficult than I expected. Because `RUST` is 
the best language in the world its not able to link `cdylib` libraries with
normal `rust` programms. This means one cannot build the example files in the 
`telefork` repo. Therefore you need a second telefork repo `telefork_org` 
(or something else), from which you are able to run `cargo run --example teleserver`.
Note that this problem is also caused from the issue, that one cannot build 
different libs from the same cargo project, weird...

USAGE:
-----
Either in C:
```c
#include <stdio.h>

void c_telefork(const char *destination, void (*f)());

void f() {
	printf("child\n");
}

int main() {
	c_telefork("127.0.0.1:7335", f);	

	// make sure that we are "spinlockin" until everything is finished
	int i = 0;
	while(1){
		i++;
	}

	return i;
}
```

or in python:
```python
import libtelefork

def f():
    print("CHILD")
    return


dest = "127.0.0.1:7335"
ret = libtelefork.py_telefork(dest, id(f))
print("ret:", ret)

# loop to make sure the program is not killed befor forking
i = 0
while True:
	i += 1;
```

both examples are assuming that `teleserver` is running on `127.0.0.1:7335`
