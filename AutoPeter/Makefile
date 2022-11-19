compiler:=g++
srcs:=Prototype GraphCore/GraphCore GraphRepr/GraphRepr
dbg_flags:=-g3 -O0
ld_flags:= -lglut -lGLU -lGL
bin_name:=app

all:
	$(compiler) $(addsuffix .cpp, $(srcs)) $(dbg_flags) -o $(bin_name) $(ld_flags)
