package main

import (
	"github.com/astaxie/beego"
)

type MainController struct {
	beego.Controller
}

func (this *MainController) Get() {
	this.Ctx.WriteString("<h1>Demo Page</h1>")
}

func main() {
	beego.Router("/", &MainController{})
	beego.Run()
}
