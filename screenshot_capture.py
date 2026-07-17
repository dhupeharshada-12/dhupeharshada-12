from PIL import ImageGrab
from datetime import datetime

print("===== Screenshot Capture Tool =====")

filename = "screenshot_" + datetime.now().strftime("%Y%m%d_%H%M%S") + ".png"

try:
    screenshot = ImageGrab.grab()
    screenshot.save(filename)

    print(f"Screenshot saved successfully as '{filename}'")

except Exception as e:
    print("Error:", e)
