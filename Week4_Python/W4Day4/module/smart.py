#smart.py
import smartpkg.camera.camera
import smartpkg.phone.phone

#import phone_base

print()
print("----")
camera.photo()
phone.makeacall()
phone.makeacall()

def smart_on():
	while True:
		choice = input('What do you want?')
		if choice == '0':
			break
		if choice == '1':
			camera.photo()
		elif choice == '2':
			photo.makeacall()
		elif choice == '3':
			print("나중에 구현")
	print("프로그램 종료")

if __name__ == '__main__':
	smart_on()
