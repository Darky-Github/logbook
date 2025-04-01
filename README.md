# logbook - Command History Manager

`logbook` is a powerful alternative to `history`, designed to enhance command tracking with additional features like search, undo, deletion, and command blocking.

## Features

- **List Command History** (`logbook list`)
- **Search Past Commands** (`logbook search <keyword>`)
- **Undo Last Command** (`logbook undo`)
- **Delete Entire History** (`logbook clear`)
- **Remove Specific Command from History** (`logbook remove <command>`)
- **Block a Command from Execution** (`logbook block <command>`)
- **Unblock a Previously Blocked Command** (`logbook unblock <command>`)

## Installation

```sh
git clone https://github.com/Darky-Github/logbook.git
cd logbook
make
sudo make install
```

## Usage

### View command history
```sh
logbook list
```

### Search for a command
```sh
logbook search "rm"
```

### Undo last command (future feature)
```sh
logbook undo
```

### Clear history
```sh
logbook clear
```

### Remove a specific command from history
```sh
logbook remove "sudo rm -rf"
```

### Block a command from execution
```sh
logbook block "rm -rf"
```

### Unblock a command
```sh
logbook unblock "rm -rf"
```

## Uninstallation
```sh
sudo make uninstall
```

## License
MIT License

---
Built for safe and efficient command tracking!
