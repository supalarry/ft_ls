# ft_ls
ft_ls is reproduced UNIX ls command. Just like real ls, ft_ls allows to use various flags too.
To produce ft_ls() function, UNIX write, opendir, readdir, closedir, stat, lstat, getpwuid, getgrgid, listxattr, getxattr, time, ctime, readlink, malloc, free, perror, strerror, exit functions have been used. Rest of the functionality is custom built. 

## Project folder structure
```
ft_ls
├── includes [header file for project]
├── libft [my library with various functions]
└── srcs [source files of the project]
Makefile [compiles the project]
author [my username]
```

## Getting Started
To create a executable that acts like UNIX ls command, run **make** in root folder to get executable called **ft_ls**.
By running ft_ls executable, current working directory's items will be listed by their ASCII values.

```
./ft_ls
```
## Functionality
### flags
ft_ls acts just like ls with R, r, l, a, t flags and any combination of them.
```
R - list subdirectories of current directory recursively
r - reverse the order of listed items
l - long form displays persmissions of a file, links, owner, group,
size of file in byte, date of modifictation and name.
a - displays also hidden files, current directory '.' and parent directory '..'
t - displays files by their modification file. Most recently edited comes first.
```
This flags can be used in combination with each other, like './ft-ls -Rla', and also
seperately, like './ft_ls -R -l -a'.
### supports specified path
If you simply run ft_ls(), then it will list current directory. You can also specifiy
target path you want to list. For example, I could launch ft_ls from my root folder but list my Desktop:
```
./ft_ls /Users/lskrauci/Desktop
```
### extra features
Also, ft_ls() displays set user id, set group id and sticky bit in addition to major
and minor device numbers for devices. Furthermore, it supports extended attributes.

## Example
I will run ft_ls on my root folder, and you can see the output that it produces right after it.
```
./ft_ls -lrt /
total 553
-rw-r--r--@   1 root  wheel     313 Dec 22  2016 installer.request
drwxrwxr-t@   2 root  wheel     68  Feb 21  2017 cores
...
...
...
```
As you can see, 'total' informs about total disk allocation. Then permission rights, number of links, owner, owner group, file size, time of last modification and file/directory name can be seen.

