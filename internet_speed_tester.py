import speedtest

print("========== Internet Speed Tester ==========\n")
print("Testing internet speed... Please wait.\n")

try:
    st = speedtest.Speedtest()

    st.get_best_server()

    download_speed = st.download() / 1_000_000
    upload_speed = st.upload() / 1_000_000
    ping = st.results.ping

    print("===== RESULT =====")
    print(f"Download Speed : {download_speed:.2f} Mbps")
    print(f"Upload Speed   : {upload_speed:.2f} Mbps")
    print(f"Ping           : {ping:.2f} ms")

except Exception as e:
    print("Error:", e)
