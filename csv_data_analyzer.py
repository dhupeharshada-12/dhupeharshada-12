import csv
from pathlib import Path


def analyze_csv():
    filename = input("Enter CSV file path: ").strip().strip('"')
    file_path = Path(filename)

    if not file_path.is_file():
        print("Error: File not found!")
        return

    try:
        with file_path.open("r", newline="", encoding="utf-8-sig") as file:
            reader = csv.DictReader(file)

            if not reader.fieldnames:
                print("The CSV file is empty or has no headers.")
                return

            print("\nAvailable columns:")
            for column in reader.fieldnames:
                print("-", column)

            column_name = input(
                "\nEnter the numeric column to analyze: "
            ).strip()

            if column_name not in reader.fieldnames:
                print("Column not found!")
                return

            values = []

            for row in reader:
                try:
                    value = float(row[column_name])
                    values.append(value)
                except (ValueError, TypeError):
                    continue

        if not values:
            print("No valid numeric values found in this column.")
            return

        total = sum(values)
        average = total / len(values)

        print("\n===== CSV ANALYSIS REPORT =====")
        print("Column:", column_name)
        print("Valid values:", len(values))
        print("Total:", round(total, 2))
        print("Average:", round(average, 2))
        print("Maximum:", max(values))
        print("Minimum:", min(values))

    except (OSError, csv.Error) as error:
        print("Unable to read CSV file:", error)


if __name__ == "__main__":
    analyze_csv()
