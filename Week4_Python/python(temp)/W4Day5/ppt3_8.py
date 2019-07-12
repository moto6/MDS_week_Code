
#ppt3-8p
import tkinter
def change_bg():
	btn.configure(background = "green")
mywin = tkinter.Tk()
mywin.geometry("{}x{}".format(450,500))
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
mywin.mainloop()

