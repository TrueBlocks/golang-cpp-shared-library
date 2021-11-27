package main

// #include "./bbb.h"
import "C"
import (
	"fmt"
	"sync/atomic"
)

var totalSpent int64
var totalSpentError int64

//export Filter
func Filter() bool {
	return true
}

func (t *C.MyNewClass) String() string {
	return fmt.Sprintf("bar: %d foo: %d { kk: %d gg: %d ff: %d}", t.bar, t.foo, t.c.kk, t.c.gg, t.c.ff)
}

//export Header
func Header(t *C.MyNewClass) bool {
	fmt.Println(t)
	fmt.Println(t.c)
	t.c.kk = 10
	fmt.Println(t)
	fmt.Println("some header functionality >>> ")
	return false
}

//export Display
func Display(spent int, isErr bool) bool {
	atomic.AddInt64(&totalSpent, int64(spent))
	if isErr {
		atomic.AddInt64(&totalSpentError, int64(spent))
	}

	fmt.Printf("Spent: current: %d > isErr : %t, total %d, total err %d\n", spent, isErr, totalSpent, totalSpentError)
	return true
}

//export Footer
func Footer() bool {
	atomic.StoreInt64(&totalSpent, 0)
	atomic.StoreInt64(&totalSpentError, 0)
	return true
}

func main() {}
