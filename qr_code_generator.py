import qrcode

print("===== QR Code Generator =====")

data = input("Enter text or URL: ")

qr = qrcode.make(data)

file_name = input("Enter file name (without .png): ") + ".png"

qr.save(file_name)

print(f"\nQR Code saved successfully as '{file_name}'")
