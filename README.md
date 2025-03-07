# 🚀 rondo-man

rondo-man is a Linux utility that simplifies common tasks via the command line. From cleaning temporary files to generating ASCII art, it's designed to boost your workflow! 🎯

## 🔥 Features

- 🗑️ **Delete Old Files**: Remove files untouched for a specified time.
- ✍️ **Quick Coding**: Instantly create a temporary file and open it in an editor.
- 🎨 **Random ASCII Art**: Displays a unique ASCII pattern every run.
- 📂 **Check Directory Size**: Get the total size of a folder.
- ⏳ **Set Timers**: Create custom reminders.
- 📋 **View Running Tasks**: List active system processes.

## 📦 Installation

### Arch Linux 🐧
```bash
sudo pacman -S g++ make
```

### Ubuntu/Debian 📜
```bash
sudo apt update && sudo apt install g++ make
```

### 🔧 Build from Source
```bash
git clone https://github.com/srujaniyengar/rondo-man.git
cd rondo-man
make
sudo make install  # Optional
```

## 🐳 Run with Docker
If you prefer using Docker, follow these steps:

### 🔨 Build the Docker Image
```bash
docker build -t rondo-man .
```

### ▶️ Run `rondo-man` in a Container
```bash
docker run --rm -it rondo-man
```

### 📂 Mount Local Files (Optional)
To access your local files inside the container:
```bash
docker run --rm -it -v "$PWD":/app rondo-man
```

## ⚡ Usage
```bash
rondo-man --help          # Show help info
rondo-man delete --older-than 30  # Delete files older than 30 days
rondo-man create-temp-file  # Make a quick coding file
rondo-man size /path/dir  # Get directory size
rondo-man timer 10        # Set a 10-minute timer
rondo-man tasks           # View running tasks
```

## 🤝 Contribute
Fork, report issues, or submit pull requests to help improve `rondo-man`!

## 📜 License
MIT License.

