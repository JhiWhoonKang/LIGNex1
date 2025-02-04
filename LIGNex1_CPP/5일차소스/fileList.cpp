#include <stdio.h>
#include <io.h>
#include <conio.h>
int main() {
_finddata_t fd;
long handle;
int result = 1;
handle = _findfirst(".\\*.*", &fd);  //현재 폴더 내 모든 파일을 찾는다.
if (handle == -1)     {
printf("There were no files.\n");
return 0;
}
while (result != -1)     {
        printf("File: %s\n", fd.name);
result = _findnext(handle, &fd);     }
_findclose(handle);
return 0; }
