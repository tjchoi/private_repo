#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    char id[] = "0x48575443";
    char sn[] = "0x30303031";
    char *p;
    
    // change numeric characters into decimal number
    // "0x256" -> 598
    // "256" -> 256
    uint32_t vsid = strtoul(id, NULL, 0);
    uint32_t vssn = strtoul(sn, NULL, 0);
    uint16_t class_id = strtoul("0x256", NULL, 0);
    
    
    printf("class_id = %u \n", class_id);
    printf("vsid:0x%08x\n", vsid);
    printf("vssn:0x%08x\n", vssn);

    return 0;
    
}
