#include <unistd.h>
int	main(int argc, char **argv){
static int d[256]; int i = 2, j;
if (argc == 3){
while (i > 0){
j = 0;
while (argv[i][j]){
if (i == 2 && !d[(unsigned char)argv[i][j]]){d[(unsigned char)argv[i][j]] = 1;}
else if (i == 1 && d[(unsigned char)argv[i][j]] == 1){
write(1, &argv[i][j], 1);
d[(unsigned char)argv[i][j]] = 2;}
j++;}
i--;}
}
write(1, "\n", 1); return (0);}