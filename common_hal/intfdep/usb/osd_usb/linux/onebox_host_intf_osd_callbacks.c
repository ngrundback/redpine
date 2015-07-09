/**
 * @file onebox_host_intf_osd_callbacks.c
 * @author  
 * @version 1.0
 *
 * @section LICENSE
 *
 * This software embodies materials and concepts that are confidential to Redpine
 * Signals and is made available solely pursuant to the terms of a written license
 * agreement with Redpine Signals
 *
 * @section DESCRIPTION
 *
 * This file contains callbacks for all operations defined in host_interface 
 * specific files
 */

#include "onebox_common.h"
#include "onebox_linux.h"
#include "onebox_sdio_intf.h"

static struct onebox_osd_host_intf_operations osd_host_intf_ops =
{
	.onebox_read_register     = read_register,
	.onebox_write_register    = write_register,
	.onebox_read_multiple     = read_register_multiple,
	.onebox_write_multiple    = write_register_multiple,
	.onebox_register_drv      = register_driver,
	.onebox_unregister_drv    = (void *)unregister_driver,
	.onebox_rcv_urb_submit    = (void *)onebox_rx_urb_submit,
	.onebox_ta_write_multiple = write_ta_register_multiple,
	.onebox_ta_read_multiple  = read_ta_register_multiple,
	.onebox_remove            = remove,
	.onebox_master_reg_read      = master_reg_read,
	.onebox_master_reg_write     = master_reg_write
};

struct onebox_osd_host_intf_operations *onebox_get_osd_host_intf_operations(void)
{
	return &osd_host_intf_ops;
} 

EXPORT_SYMBOL(onebox_get_osd_host_intf_operations);
