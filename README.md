# ft_ls
ft_ls is reprogrammed UNIX ls command.

## Getting Started
To create a executable that acts like UNIX ls command, run **make** in root folder to get executable called **ft_ls**.
By running ft_ls executable, current working directory's items will be listed by their ASCII values.

```
./ft_ls
```
## Functionality
ft_ls acts just like ls with R,r,l,a,t flags and any combination of them.
```
R - list subdirectories of current directory recursively
r - reverse the order of listed items
l - long form displays persmissions of a file, links, owner, group,
size of file in byte, date of modifictation and name.
```

Also displays set user id, set group id and sticky bit in addition to major
and minor device numbers for devices. Supports extended attributes.

![alt text](https://i.imgur.com/YZgPXDw.png)
