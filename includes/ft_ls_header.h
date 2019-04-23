/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ls_header.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 19:00:15 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/04/10 19:00:17 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_HEADER_H
# define FT_LS_HEADER_H
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <string.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <grp.h>
# include <uuid/uuid.h>

typedef struct		s_file
{
	char			type;
	char			*permissions;
	int				hardlinks;
	char			*owner;
	char			*group;
	unsigned long	size;
	char			*year;
	char			*month;
	char			*month_day;
	char			*hour_minute;
	char			*name;
	int				l_flag;
	time_t			last_mod;
	blksize_t		blocks;
	char			*path;
	int				err;
	int				dev_major;
	int				dev_minor;
	int				dev_layout;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

typedef struct		s_folder
{
	char			*name;
	time_t			last_mod;
	int				index;
	struct s_folder	*prev;
	struct s_folder	*next;
}					t_folder;

typedef struct		s_error
{
	char			*name;
	struct s_error	*prev;
	struct s_error	*next;
}					t_error;

void				ft_process_argv(char **argv, int argc,
					char **flags, int flag);
void				ft_ls(char *path, char *flags, int flag, int argc);
size_t				ft_hardlinks_width(t_file *head);
size_t				ft_owner_width(t_file *head);
size_t				ft_group_width(t_file *head);
size_t				ft_size_width(t_file *head);
void				ft_sort_ascii(int *array_ptr, int len, char **argv);
int					ft_file_type(char *path);
int					ft_file_type2(char *path);
char				*ft_permissions(char *name, struct stat *buf);
char				*ft_extract_date(char *timestamp, int value);
t_file				*ft_file_origin(char *name, char *flags, int flag,
					t_file *prev);
void				ft_file_append(t_file *head, char *name, char *flags,
					int flag);
t_file				*ft_list_files(int *files, char **argv, char *flags,
					int flag);
int					*ft_argv_files(char **argv, int argc, char **flags);
int					*ft_argv_directories(char **argv, int argc,
					char **flags);
void				ft_display(t_file *head, char *flags, int flag,
					int folder);
void				ft_display_files(t_file *head, int folder);
void				ft_display_files_rev(t_file *head, int folder);
t_file				*ft_rewind(t_file *head);
t_file				*ft_ascii(t_file *head);
void				ft_list_swap(t_file *left, t_file *right);
t_file				*ft_time(t_file *head);
t_folder			*ft_folder_origin(char *name, t_folder *prev, int i);
void				ft_folder_append(t_folder *head, char *name, int i);
void				ft_display_long(t_file *head, int *widths);
void				ft_col_width(t_file *head, int *widths);
t_folder			*ft_rewind_subfolder(t_folder *head);
t_folder			*ft_time_subfolders(t_folder *head);
void				ft_list_swap_subfolder(t_folder *left, t_folder *right);
void				ft_time_directories(char **argv, int *directories);
t_folder			*ft_ascii_subfolders(t_folder *head);
void				ft_free_files(t_file *head);
void				ft_free_folders(t_folder *head);
t_folder			*ft_list_folders(char **argv, int *directories);
size_t				ft_dev_major_width(t_file *head);
size_t				ft_dev_minor_width(t_file *head);
int					ft_isdevice(t_file *new_link);
int					ft_dot(char *name);
size_t				ft_unum_len(unsigned long long num);
int					ft_invalid_flag(char flag);
void				ft_save_flag(char **flags, char flag, int *j);
char				ft_extract_flags(char **argv, char **flags, int argc);
void				ft_display_long_dev(t_file *head);
void				ft_fill_file_name(char *path, char *name, int i, int j);
char				*ft_file_name(char *path);
void				ft_file_origin_basics(t_file *new_link, t_file *prev,
					char *name);
void				ft_file_origin_id(struct stat *buf, t_file *new_link);
void				ft_file_origin_date(struct stat *buf, t_file *new_link);
void				ft_file_origin_type(t_file *new_link);
void				ft_file_origin_device(struct stat *buf, t_file *new_link);
size_t				ft_blocks(t_file *head);
void				ft_col_width(t_file *head, int *widths);
void				ft_permissions_core(struct stat *buf, char *permissions);
void				ft_extract_part(char *extracted, char *timestamp, int len,
					int start);
void				ft_sort_folders(t_folder **head, char *flags, int flag);
void				ft_file_list_launcher(t_file **head, char *path,
					char *flags, int flag);
void				ft_folder_list_launcher(t_folder **head, char *path,
					char *f, int flag);
void				ft_ls_file_launcher(t_file **head, char *flags,
					int flag, DIR *dir);
void				ft_ls_directories_launcher(t_folder **head, char *flags,
					int f, int a);
void				ft_sort_files(t_file **head, char *flags, int flag);
void				ft_pathname(char *pathname, char *path, char *d_name);
void				ft_dev_layout(t_file *head);
int					ft_dot(char *name);
void				ft_initialize_null(t_file **head, t_folder **head_folder);
void				ft_close_dir(DIR *dir);
void				ft_initialize_ls(DIR **dir, t_file **head,
					t_folder **folder, char *p);
void				ft_ls_error(char *path, int flag, int argc, char *flags);
int					ft_dashcount(char *flags);
void				ft_print_path_r(int argc, int dashes, int *times,
					char *path);
void				ft_print_path_etc(int *times, char *path);
void				ft_print_path(char *path, int flag, int argc, char *flags);
void				ft_free(int *files, int *directories, t_file *files_head);
int					ft_index(int *directories, int flag, char **flags);
void				ft_process_directories(char **argv, int argc,
					char **flags, int flag);
void				ft_recursive(t_folder *head_folder, char *flags,
					int flag, int argc);
int					ft_validate(struct dirent *sd, int flag, char *flags);
int					ft_validate2(struct dirent *sd, int flag, char *flags);
void				ft_print_name_err(char *path);
void				ft_error_argv(char **argv, int argc, char *flags);
int					ft_index_file(char *flags);
t_error				*ft_error_origin(char *name, t_error *prev);
void				ft_error_append(t_error *head, char *name);
void				ft_error_print(t_error *head);
t_error				*ft_rewind_error(t_error *head);
t_error				*ft_ascii_error(t_error *head);
void				ft_error_swap(t_error *left, t_error *right);
void				ft_display_argv_files(t_file *head, char *flags,
					int flag, int folder);
void				ft_display_argv(t_file *head, int folder);
void				ft_display_argv_rev(t_file *head, int folder);
#endif
