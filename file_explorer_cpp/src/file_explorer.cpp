#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

void listDirectory(const string &path){
	DIR *dir;
	struct dirent *entry;
	struct stat info;

	dir=opendir(path.c_str());
	if(!dir){
		perror("opendir");
		return;
	}

	cout<<"\nContents of " << path << ":\n";
	cout << left << setw(30) << "Name" << setw(10) << "Type" << setw(10) << "Size(bytes)" << setw(25) << "Last Modified" << endl;
	cout << string(75, '-') << endl;

	while((entry=readdir(dir)) !=nullptr) {
		string fullPath=path + "/" + entry->d_name;
		if(stat(fullPath.c_str(), &info) !=0) continue;

		string type = S_ISDIR(info.st_mode) ? "DIR" : "FILE";
	        char modTime[20];
        	strftime(modTime, sizeof(modTime), "%Y-%m-%d %H:%M:%S", localtime(&info.st_mtime));
		cout << left << setw(30) << entry->d_name
             		<< setw(10) << type
             		<< setw(10) << info.st_size
             		<< setw(25) << modTime << endl;
    	}
    	closedir(dir);
}

// Function to change directory
void changeDirectory(string &currentDir, const string &newDir) {
    if (chdir(newDir.c_str()) == 0) {
        char buffer[1024];
        getcwd(buffer, sizeof(buffer));
        currentDir = buffer;
        cout << "Changed directory to: " << currentDir << endl;
    } else {
        perror("chdir");
    }
}

// Function to create a directory
void createDirectory(const string &dirName) {
    if (mkdir(dirName.c_str(), 0755) == 0)
        cout << "Directory created successfully.\n";
    else
        perror("mkdir");
}

// Function to remove a directory
void removeDirectory(const string &dirName) {
    if (rmdir(dirName.c_str()) == 0)
        cout << "Directory removed successfully.\n";
    else
        perror("rmdir");
}

// Function to delete a file
void deleteFile(const string &filename) {
    if (remove(filename.c_str()) == 0)
        cout << "File deleted successfully.\n";
    else
        perror("remove");
}

// Function to rename file or directory
void renameItem(const string &oldName, const string &newName) {
    if (rename(oldName.c_str(), newName.c_str()) == 0)
        cout << "Renamed successfully.\n";
    else
        perror("rename");
}

// Function to display file content
void viewFile(const string &filename) {
    FILE *file = fopen(filename.c_str(), "r");
    if (!file) {
        perror("fopen");
        return;
    }
    cout << "\n--- File Content: " << filename << " ---\n";
    char ch;
    while ((ch = fgetc(file)) != EOF)
        cout << ch;
    cout << "\n--- End of File ---\n";
    fclose(file);
}

// Function to search for a file recursively
void searchFile(const string &basePath, const string &target) {
    DIR *dir = opendir(basePath.c_str());
    if (!dir) return;

    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
        string name = entry->d_name;
        if (name == "." || name == "..")
            continue;

        string fullPath = basePath + "/" + name;
        if (name.find(target) != string::npos)
            cout << "Found: " << fullPath << endl;

        struct stat st;
        stat(fullPath.c_str(), &st);
        if (S_ISDIR(st.st_mode))
            searchFile(fullPath, target);
    }
    closedir(dir);
}

// Display menu
void showMenu() {
    cout << "\n===== FILE EXPLORER MENU =====\n";
    cout << "1. List current directory\n";
    cout << "2. Change directory\n";
    cout << "3. Create directory\n";
    cout << "4. Remove directory\n";
    cout << "5. Delete file\n";
    cout << "6. Rename file/directory\n";
    cout << "7. View file content\n";
    cout << "8. Search for file\n";
    cout << "9. Show current path\n";
    cout << "0. Exit\n";
    cout << "==============================\n";
}

int main() {
    string currentDir;
    char buffer[1024];
    getcwd(buffer, sizeof(buffer));
    currentDir = buffer;

    int choice;
    while (true) {
        showMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) {
            cout << "Exiting File Explorer...\n";
            break;
        }

        string name, newName;
        switch (choice) {
            case 1:
                listDirectory(currentDir);
                break;
            case 2:
                cout << "Enter directory name/path: ";
                getline(cin, name);
                changeDirectory(currentDir, name);
                break;
            case 3:
                cout << "Enter directory name to create: ";
                getline(cin, name);
                createDirectory(name);
                break;
            case 4:
                cout << "Enter directory name to remove: ";
                getline(cin, name);
                removeDirectory(name);
                break;
            case 5:
                cout << "Enter filename to delete: ";
                getline(cin, name);
                deleteFile(name);
                break;
            case 6:
                cout << "Enter old name: ";
                getline(cin, name);
                cout << "Enter new name: ";
                getline(cin, newName);
                renameItem(name, newName);
                break;
            case 7:
                cout << "Enter filename to view: ";
                getline(cin, name);
                viewFile(name);
                break;
            case 8:
                cout << "Enter filename to search: ";
                getline(cin, name);
                searchFile(currentDir, name);
                break;
            case 9:
                cout << "Current directory: " << currentDir << endl;
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
