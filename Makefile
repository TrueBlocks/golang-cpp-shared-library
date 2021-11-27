

go-build:
	go build -o goverser.dylib -buildmode=c-shared ./goverser.go


build: go-build
	g++ main.cpp goverser.dylib -o main
