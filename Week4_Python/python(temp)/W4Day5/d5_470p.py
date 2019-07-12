import tkinter
from tkinter import messagebox

def CancleClick():
	text_id.set("")
	text_pw.set("")


def okClick():
	try:
		id_value = text_id.get()
		pw_value = text_pw.get()
		messagebox.showinfo("ID","ID:{}, pw:{}".format(id_value, pw_value))
	except:
		messagebox.showwarning("입력오류", "정확히 입력하세요")
		text_id.set("")
		text_pw.set("")


root = tkinter.Tk()
root.title("login")
root.geometry('300x200')
text_id = tkinter.StringVar(value=' ')
text_pw = tkinter.StringVar(value=' ')

frame = tkinter.Frame(root)
#grid()

button = tkinter.Button(frame,text = 'reset',command = reset)
button.grid(row=0,column=0 , columnspan=2)
label = tkinter.Label(frame, text = 'ID')
label.grid(row =1 , column=0)
entry_id = tkinter.Entry(frame, textvariable = text_id)
entry_id.grid(row =1, column =1)
label = tkinter.Label(frame, text = 'PW')
label.grid(row= 2, column = 0)
entry_pw = tkinter.Entry(frame, textvariable = text_pw, show='*')
entry_pw.grid(row = 2, column =1)

#bt=tkinter.Button(root, text = "Quit")
#bt.grid(row = 3, column = 1)
lb_test = tkinter.Label(root, text="ID insert reset")
lb_test.grid(row = 2, column = 1)

lb_test = tkinter.Label(root, text="PW insert reset")
lb_test.grid(row = 0, column = 1)



root.mainloop()

'''
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

'''