from datetime import datetime

records = []


def add_record():
    print("\n--- Add Daily Activity ---")

    date = input("Enter date (YYYY-MM-DD): ").strip()

    if not date:
        date = datetime.now().strftime("%Y-%m-%d")

    try:
        datetime.strptime(date, "%Y-%m-%d")

        distance = float(input("Travel distance (km): "))
        electricity = float(input("Electricity used (kWh): "))

        if distance < 0 or electricity < 0:
            print("Values cannot be negative!")
            return

    except ValueError:
        print("Invalid input! Please enter a valid date and numbers.")
        return

    # Illustrative emission factors only; adjust for your region.
    travel_emissions = distance * 0.12
    electricity_emissions = electricity * 0.70

    total = travel_emissions + electricity_emissions

    record = {
        "date": date,
        "distance": distance,
        "electricity": electricity,
        "travel_emissions": travel_emissions,
        "electricity_emissions": electricity_emissions,
        "total": total
    }

    records.append(record)

    print("\nActivity recorded successfully!")
    print(f"Estimated emissions: {total:.2f} kg CO2e")


def view_records():
    if not records:
        print("\nNo records available.")
        return

    print("\n===== DAILY ACTIVITY RECORDS =====")

    for number, record in enumerate(records, start=1):
        print(f"\nRecord {number}")
        print(f"Date: {record['date']}")
        print(f"Travel: {record['distance']:.2f} km")
        print(f"Electricity: {record['electricity']:.2f} kWh")
        print(f"Estimated emissions: {record['total']:.2f} kg CO2e")


def calculate_summary():
    if not records:
        print("\nNo records available to calculate.")
        return

    total_travel = sum(r["travel_emissions"] for r in records)
    total_electricity = sum(r["electricity_emissions"] for r in records)
    total_emissions = sum(r["total"] for r in records)

    print("\n===== CARBON FOOTPRINT SUMMARY =====")
    print(f"Travel emissions: {total_travel:.2f} kg CO2e")
    print(f"Electricity emissions: {total_electricity:.2f} kg CO2e")
    print(f"Combined estimated emissions: {total_emissions:.2f} kg CO2e")
    print(f"Activities recorded: {len(records)}")


def search_by_date():
    search_date = input("Enter date to search (YYYY-MM-DD): ").strip()

    matching_records = [
        record for record in records
        if record["date"] == search_date
    ]

    if not matching_records:
        print("No records found for this date.")
        return

    for record in matching_records:
        print(f"\nDate: {record['date']}")
        print(f"Travel: {record['distance']:.2f} km")
        print(f"Electricity: {record['electricity']:.2f} kWh")
        print(f"Estimated emissions: {record['total']:.2f} kg CO2e")


def main():
    while True:
        print("\n===== PERSONAL CARBON FOOTPRINT TRACKER =====")
        print("1. Add Daily Activity")
        print("2. View All Records")
        print("3. Calculate Summary")
        print("4. Search by Date")
        print("5. Exit")

        choice = input("Enter your choice: ").strip()

        if choice == "1":
            add_record()
        elif choice == "2":
            view_records()
        elif choice == "3":
            calculate_summary()
        elif choice == "4":
            search_by_date()
        elif choice == "5":
            print("Thank you for using Carbon Footprint Tracker!")
            break
        else:
            print("Invalid choice! Please select 1-5.")


if __name__ == "__main__":
    main()
