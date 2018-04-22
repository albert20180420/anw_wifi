/******************************************************************************
 *  author      :   zhongjun
 *  description :   none
 *  date        :   2018/02/22
 *****************************************************************************/
#include "platform_mgr.h"
#include "wifi_mgr.h"
#include <stdio.h>
#include "ucos_ii.h"
#include "wifi_api.h"


void msg_callback(unsigned short id,void* data )
{
    switch(id)
    {
    case WIFI_ON_CFM:
        printf("APP << SDK:WIFI INIT SUCCESS\n");
        break;
    case WIFI_OFF_CFM:
        break;
    case WIFI_NEW_DEVICE_FOUND_IND:
        break;
    case WIFI_SCAN_END:
        break;
    case WIFI_STOP_SCAN:
        break;
    default:
        break;
    }
}
int main()
{
    platform_mgr_t *platform_instace = NULL;

    AnW_wifi_on(msg_callback);
    platform_instace = get_platform_instance();


	/* test scan */
	AnW_start_scan(NULL,0);
    OSInit();
    platform_instace->create_task();
    OSStart();
    while(1);

}
