Allowed functions:

- open: Opens a file descriptor for a specified file, allowing read, write, or both operations based on the provided flags. The function returns a file descriptor that can be used for subsequent file operations.

- close: Closes a previously opened file descriptor, freeing up any system resources associated with it. Once closed, the file descriptor cannot be used until it is opened again.

- read: Reads data from an open file descriptor into a buffer. The amount of data read is specified by the function's parameters.

- write: Writes data from a buffer to an open file descriptor. This function is used to output data to files, devices, or other outputs associated with the file descriptor.

- malloc: Allocates a specified amount of memory from the heap, returning a pointer to the beginning of the block. This memory must be managed manually and freed when no longer needed.

- free: Deallocates memory previously allocated with malloc (or related functions like calloc), returning it to the heap. Failing to call free leads to memory leaks.

- perror: Prints a descriptive error message to the standard error stream, based on the string provided and the global errno value set by system calls and some library functions.

- strerror: Returns a pointer to a string that describes the error code passed to the function. The error code is typically stored in errno.
access: Checks the calling process's permissions for a specified file or path, including existence, read, write, and execute permissions.

- dup: Duplicates an existing file descriptor, returning a new descriptor that points to the same open file entry as the original.

- dup2: Similar to dup, but the new file descriptor is given a specific value. If the specified value is already in use, it is first closed.

- execve: Executes a program referenced by a specified pathname, replacing the current process image with a new process image, and passing arrays of arguments and environment variables.

- exit: Causes normal process termination and the value supplied in the argument is returned to the parent process.

- fork: Creates a new process by duplicating the calling process. The new process is referred to as the child process.

- pipe: Creates a pair of file descriptors, pointing to a pipe inode, which can be used for inter-process communication.

- unlink: Removes a link to a file in a filesystem, effectively deleting the file if it is the last link.

- wait: Blocks the calling process until one of its child processes exits or a signal is received. After child process termination, the function returns the process ID of the dead process.

- waitpid: Similar to wait, but waits for a specific child process to end or for a state change which is reported to the parent process.