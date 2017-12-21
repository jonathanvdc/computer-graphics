# Builds all the projects in the solution...
.PHONY: all
all: Engine 

# Builds project 'Engine'...
.PHONY: Engine
Engine: 
	make --directory="." --file=Engine.makefile

# Cleans all projects...
.PHONY: clean
clean:
	make --directory="." --file=Engine.makefile clean

