import qrcode
import os

print("========== QR Code Batch Generator ==========")

os.makedirs("qr_codes", exist_ok=True)

count = int(input("How many QR codes do you want to generate? "))

for i in range(1, count + 1):
    text = input(f"Enter text/URL for QR Code {i}: ")

    qr = qrcode.QRCode(
        version=1,
        box_size=10,
        border=4
    )

    qr.add_data(text)
    qr.make(fit=True)

    img = qr.make_image(fill_color="black", back_color="white")

    filename = f"qr_codes/qr_{i}.png"
    img.save(filename)

    print(f"✅ Saved: {filename}")

print("\nAll QR Codes generated successfully!")
