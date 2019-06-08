import tkinter
def increase():
	number.set(number.get()+1)
mywin = tkinter.Tk()
mywin.geometry("200x200")
frame = tkinter.Frame(mywin)
frame.pack()
number = tkinter.IntVar(value = 0)
button = tkinter.Button(frame, text = "increase", command = increase)
button.pack()
label = tkinter.Label(frame, text = "start", textvariable = number)
label.pack()
mywin.mainloop()