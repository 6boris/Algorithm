package main

import "github.com/astaxie/beego"

type BeeferController struct {
	beego.Controller
}

func (c *BeeferController) Get() {
	c.Ctx.WriteString("Hello Bego")
}

func main() {
	beego.Router("/", &BeeferController{})
	beego.Run(":8085")
}
