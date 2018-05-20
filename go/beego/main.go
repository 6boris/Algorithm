package main

import (
	_ "beego-demo/routers"
	"github.com/astaxie/beego"
)

func main() {
	beego.Get("/", func(ctx *context.Context) {
		ctx.Output.Body([]byte("hello world"))
	})

	beego.Run()
}
