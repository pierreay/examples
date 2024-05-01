# Object files.
obj-m += hello-1.o

# Allows to compile with `sudo' if needed.
PWD := $(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

info:
	modinfo hello-1.ko

ls:
	lsmod | grep hello

load:
	sudo insmod hello-1.ko

remove:
	sudo rmmod hello_1
