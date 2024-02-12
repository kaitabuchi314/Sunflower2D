import os
import shutil

def copy_files_to_project(project_path):
    # List of files to copy
    files_to_copy = ['SDL2.dll', 'SDL2_image.dll', 'SDL2_mixer.dll', 'SDL2_ttf.dll']

    # Check if the project path exists
    if not os.path.exists(project_path):
        print("The specified project path does not exist.")
        return

    # Iterate over each file and copy it to the project folder
    for file_name in files_to_copy:
        source_file = os.path.join(os.getcwd(), file_name)
        destination_file = os.path.join(project_path, file_name)

        # Copy file to project folder
        try:
            shutil.copyfile(source_file, destination_file)
            print(f"Successfully copied '{file_name}' to '{project_path}'.")
        except FileNotFoundError:
            print(f"Error: '{file_name}' not found in the current directory.")

if __name__ == "__main__":
    # Get the path to the current project from the user
    project_path = input("Enter the path to the current project folder: ")

    # Copy files to the project folder
    copy_files_to_project(project_path)
