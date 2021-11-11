

go-build:
	go build -o goverser.dylib -buildmode=c-shared ./goverser/goverser.go


build: go-build
	g++ main.cpp goverser.dylib -o main
