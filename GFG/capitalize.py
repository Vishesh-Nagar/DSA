import os

def capitalize_folders():
    for item in os.listdir():
        if os.path.isdir(item):
            new_name = item.capitalize()
            if new_name != item:
                os.rename(item, new_name)
                print(f"Renamed folder: '{item}' → '{new_name}'")

if __name__ == "__main__":
    capitalize_folders()
