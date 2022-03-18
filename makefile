CC:=g++
srcs:=$(wildcard ./Source/*.cpp)
objs:=$(srcs:%.cpp=%.o)
out:=threadpool
all:$(out) 
$(out):$(objs)
	$(CC) $(objs) -g -o $(out) 
%.o:%.cpp
	$(CC) -g -Wall -c $^ -o $@
.PHONY:clean rebuild
clean:
	$(RM) $(objs) $(out) 
rebuild:clean all



