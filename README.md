<h2 align="center"> 
  Concordo - C++
</h1>

### :bookmark_tabs: Resume

This application was a challenge proposed by the Linguagem de Programação I. This is an application developed in c ++ for clone Discord actions. It is possible to create a user, server, update server description, update server code, remove server, enter a server, disconnect etc.

### :toolbox: Prerequisites
Before starting, you will need to have the following tools installed on your machine:
[Git](https://git-scm.com), [G++](https://www.geeksforgeeks.org/compiling-with-g-plus-plus/) and [Make](https://www.gnu.org/software/make/). 
In addition, it is good to have an editor to work with the code as [VSCode](https://code.visualstudio.com/)

### 🎲 Running the project

```bash
# Clone this repository
$ git clone https://github.com/franklaercio/lp1-concordo-base.git

# Access the project folder in the terminal/cmd
$ cd lp1-concordo-base

# Compile the code
$ make all

# Run the application
$ ./concordo

# Run the application with script
$ ./concordo < script_comandos.txt
```

### :keyboard: Commands

```bash
# Create user
$ create-user email password name

# Login in app
$ login email password

# Disconnect of application
$ disconnect

# Create new server
$ create-server name

# Set server description
$ set-server-desc name description

# Set server invite code
$ set-server-invite-code name code

# List all servers
$ list-servers

# Remove servers
$ remove-server name

# Enter on server
$ enter-server name code

# Leave server
$ leave-server

# List all participants of server
$ list-participants

# List all channels
$ list-channels

# Create new channel
$ create-channel name type

# Enter on channel
$ enter-channel name

# Send new message
$ send-message message

# List all messages of channel
$ list-messages

```

### :artificial_satellite: Acknowledgments

- C++
- POO
