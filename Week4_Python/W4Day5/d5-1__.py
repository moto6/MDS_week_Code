'''
import tkinter
mywin = tkinter.Tk()
mywin.geometry("200x200")
bt = tkinter.Button(mywin, text = "Quit")
bt.grid(row = 0, column = 2)
lb_test = tkinter.Label(mywin, text="label Create")
lb_test.grid(row = 0, column = 1)
'''

def change_bg():
	btn.configure(background = "green")
mywin = tkinter.Tk()
mywin = tkinter.Tk()
mywin.geometry("{}x{}".format(200,200))
frame_up = tkinter.Frame(mywin, height = 60, width = 90, background = "blue")
frame_down = tkinter.Frame(mywin, height = 30, width = 90, background = "red")
frame_up.pack()
frame_down.pack()
btn = tkinter.Button(frame_down, text = "click", command = change_bg,
foreground = "white", background = "black",
activeforeground = "blue",
activebackground = "#FF007F")
btn.pack()
mywin.mainloop()