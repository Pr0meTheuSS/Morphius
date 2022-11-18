compiler:=g++
srcs:=Prototype GraphCore/GraphCore GraphRepr/GraphRepr
ld_flags:= -lglut -lGLU -lGL
bin_name:=app

all:
	$(compiler) $(addsuffix .cpp, $(srcs)) -o $(bin_name) $(ld_flags)
