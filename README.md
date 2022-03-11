<a href="https://github.com/brerickner/">
    <img src="bre_favi.png" alt="Bre" title="Bre's Github" align="right" height="60" />
</a>
# Holberton Simple C-Shell - hsh

A simple UNIX command interpreter assigned in the curriculum at Holberton School

## Description

Hsh is a simple rendition of a UNIX command language interpreter that reads and executes commands from standard input, or a file.

## Initialization

Compile all c files in the repository, using the wildcard command (*.c), and run the executable:

```bash
gcc *.c -o hsh
./hsh
```
Hsh can be used in two different modes, interactive and non-interactive.

Interactive hsh displays the prompt $ when it is ready to read a command and the user is able to interactively type or interrupt commands.

Example:
```bash
$./hsh
$
```
Non-interactive hsh will take a script and emulate an interactive shell by prompting the user to input values.

Example:
```bash
$ echo "echo 'hello world'" | ./hsh
'hello world'
$
```

## Usage

```bash
echo "hello world" | ./hsh

or

./hsh

```

## Contributing
Holberton students have contributed test cases in order to check for edge cases.
