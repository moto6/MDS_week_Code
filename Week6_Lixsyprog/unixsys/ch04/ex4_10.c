#include <shadow.h>

int main(void) {
    struct spwd *spw;

    spw = getspnam("hbooks");
    printf("Login Name : %s\n", spw->sp_namp);
    printf("Passwd : %s\n", spw->sp_pwdp);
    printf("Last Change : %d\n", spw->sp_lstchg);

    return 0;
}
