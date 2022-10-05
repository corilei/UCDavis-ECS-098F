## Command Line 

- Sorry, no manipulations with clipboard allowed

### `ls` - list directory contents
*  `ls -a`: do not ignore entries starting with `.`, list all files
*  `ls -l`: use a long listing format
*  `ls -h`: with -l and -s, print sizes like 1K 234M 2G etc.
*  `ls -S`: sort by file size, largest first
*  `ls -R`: list subdirectories recursively

eg: `ls -alhSR`


### `tree` - list contents of directories in a tree-like format.
*  `tree -a`: All files are printed.
*  `tree -p`: Print the file type and permissions for each file (as per ls -l)
*  `tree -h`: Print  the  size  of each file but in a more human readable way, e.g. appending a
              size letter for kilobytes (K),  megabytes  (M),  gigabytes  (G),  terabytes  (T),
              petabytes (P) and exabytes (E).
*  `--sort[=]<name>`: Sort the output by name (as per ls): name (default), ctime (-c), mtime (-t), size
                      or version (-v).
*  `tree -R`: list subdirectories recursively

eg: `tree -aphR --sort=size`


### `rm` - remove files or directories
*  `rm -I`:prompt once before removing more than three files, or when removing  recursively;
           less intrusive than -i, while still giving protection against most mistakes
*  `rm -r, -R, --recursive`: remove directories and their contents recursively

eg: `rm -Ir webapp index.html`


### `cp` - copy files and directories
*  `cp -b --backup[=CONTROL]`: make a backup of each existing destination file
*  `cp -u, --update`: copy only when the SOURCE file is newer than the destination  file  or  when  the
                      destination file is missing
*  `cp -R, -r, --recursive`: copy directories recursively

eg: `cp -b ~/Downloads/conf.json ~/Game/`
eg: `cp -ru ~/noan_homework/* ~/grant_homework`


### `mv` - move (rename) files
*  `mv -i, --interactive`: prompt before overwrite

eg: `mv -i ~/noan_homework/* ~/grant_homework`


### `alias` - substitutes the alias name with the command to be run

eg: `alias buildDir='cd ~/School/SDP'`


### VIM

*  To exit the editor, without saving the changes, switch to normal mode by pressing Esc , type :q! and hit Enter . Type :q!

*  eg: `:%s/temp_var/min_elapsed/g`:  Change each 'temp_var' to 'min_elapsed' in all the lines.


### `zip`

*  eg: 'zip assignment.zip main.c node.h node.c'



### `tar` - an archiving utility
*  `tar -t, --list`: List the contents of an archive.  Arguments are optional.  When given, they specify the names of the members to list.
*  `tar -v, --verbose`: Verbosely list files processed.
*  `tar -f, --file=ARCHIVE`: Use archive file or device ARCHIVE.
*  `tar -x, --extract, --get`: Extract files from an archive.  Arguments are optional.  When given, they specify
              names of the archive members to be extracted.
*  `tar -c, --create`: Create a new archive. 

eg: `tar -vf boost_1.75.tar.gz`








