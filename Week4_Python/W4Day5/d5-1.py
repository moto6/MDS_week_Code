'''
import tkinter

mywin = tkinter.Tk()
mywin.geometry("450x500")

bt1 = tkinter.Button(mywin, text = "Quit")
bt1.grid(row=6, column=6)
lb1 = tkinter.Label(mywin,text = "label Create")
lb1.grid(row =6, column= 7)

bt2 = tkinter.Button(mywin, text = "Start")
bt2.grid(row=7, column=7)
lb2 = tkinter.Label(mywin,text = "Helo GUI World")
lb2.grid(row =7, column= 8)

bt1 = tkinter.Button(mywin, text = "r5c5")
bt1.grid(row=5, column=5)
lb2 = tkinter.Label(mywin,text = "r5c5")
lb2.grid(row =5, column= 4)


'''
#ppt3-8p
import tkinter
mywin = tkinter.Tk()
mywin.geometry("450x500")
def change_bg():
	btn.configure(background = "green")
def increase():
	number.set(number.get()+1)

#mywin = tkinter.Tk()


frame = tkinter.Frame(mywin)
#frame.pack()
number = tkinter.IntVar(value=0)
button = tkinter.Button(frame,text = 'increase',command=increase)
button.pack()
label = tkinter.Label(frame,text = 'Start', textvariable = number)
label.pack()


'''
mywin.geometry("{}x{}".format(200,200))
frame_up = tkinter.Frame(mywin,height = 60, width =90, background = "blue")
frame_down = tkinter.Frame(mywin,height = 30, width = 90, background = "red")
frame_up.pack()
frame_down.pack()

btn = tkinter.Button(frame_down,text="click", command = change_bg,
foreground = "white",
background = "black",
activeforeground = "blue",
activebackground = "#FF007F")
btn.pack()
'''
mywin.mainloop()

