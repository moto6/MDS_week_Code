import tkinter
import time


def okClick():

	for x in range(0,60):
		
		img = tkinter.PhotoImage(file="beachball.png")
		ball1=cvs.create_image(x,x,image=img)

		myd.move(ball1,9,5)
		mywin.update()
		time.sleep(0.05)


mywin = tkinter.Tk()
cvs = tkinter.Canvas(mywin, width = 600, height=400)
cvs.grid()
x=100
y=100
img = tkinter.PhotoImage(file="beachball.png")
ball1=cvs.create_image(x,x,image=img)


btn_ok = tkinter.Button( text = "입력 확인", command = okClick)
btn_ok.grid(row = 2, column = 1)


for x in range(0,60):
	cvs.move(ball1,9,5)
	mywin.update()
	time.sleep(0.05)

mywin.mainloop()