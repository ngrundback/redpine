/**
 * @file onebox_proc.c
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
 * This file contians the proc file system creation & functions for debugging
 * the driver.
 */

#include "onebox_common.h"
#include "onebox_linux.h"
#include <linux/string.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/file.h>

ONEBOX_STATIC struct proc_dir_entry *onebox_entry = NULL;
extern uint32 onebox_zone_enabled;

/**
 * This function gives the driver and firmware version number.
 *
 * @param  Pointe to the page.
 * @param  start.  
 * @param  off.  
 * @param  Count.  
 * @param  EOF.  
 * @param  data.  
 * @return Returns the number of bytes read. 
 */
#if 0
int32 onebox_proc_version_read (int8  *page,int8  **start, off_t off,
                                int32 count,int32 *eof, PVOID data )
{
	int32        len;
	PONEBOX_ADAPTER adapter    = data;
	adapter->driver_ver.major = 0;
	adapter->driver_ver.minor = 0;

	adapter->driver_ver.release_num = 11;
	adapter->driver_ver.patch_num = 0;
	len  = sprintf(page,"UMAC : %x.%d.%d.%d\nLMAC : %d.%d.%d.%d.%d\n",
	               adapter->driver_ver.major,
	               adapter->driver_ver.minor, 
	               adapter->driver_ver.release_num, 
	               adapter->driver_ver.patch_num,
	               adapter->lmac_ver.major,
	               adapter->lmac_ver.minor, 
	               adapter->lmac_ver.release_num, 
	               adapter->lmac_ver.patch_num,
	               adapter->lmac_ver.ver.info.fw_ver[0]);
	*eof = 1;
	return len;
}



/**
 * * This function display the currently enabled debug zones.
 * *
 * * @param page   Page Is The Buffer Where Data Will
 * *               Be Written
 * * @param start  From Where Data Start(NULL)
 * * @param off    Offset Location
 * * @param count  Same As Offset For Reading
 * * @param eof    To Signal No More Data Present
 * * @param data   Pointer To Driver Priv Area
 * */
int onebox_proc_debug_zone_read(char *page, char **start, off_t off,
                                int count, int32 *eof, void *data)
{
	int32 len;
	len  = ONEBOX_SPRINTF(page,"The zones available are %#x\n",*(int32 *)data);
	*eof = 1;
	return len;
}
#endif

static int onebox_proc_version_show(struct seq_file *seq, void *data)
{
	PONEBOX_ADAPTER adapter = seq->private;

	adapter->driver_ver.major =1;
	adapter->driver_ver.minor =0;
	adapter->driver_ver.release_num = 1;
	adapter->driver_ver.patch_num = 0;

	seq_printf(seq, 
		   "UMAC : %x.%d.%d.%d\nLMAC : %d.%d.%d.%d.%d\n",
		   adapter->driver_ver.major,
		   adapter->driver_ver.minor, 
		   adapter->driver_ver.release_num, 
		   adapter->driver_ver.patch_num,
		   adapter->lmac_ver.major,
		   adapter->lmac_ver.minor, 
		   adapter->lmac_ver.release_num, 
		   adapter->lmac_ver.patch_num,
		   adapter->lmac_ver.ver.info.fw_ver[0]);
	return 0;
	
}

static int onebox_proc_stats_show(struct seq_file *seq, void *data)
{
	PONEBOX_ADAPTER adapter = seq->private;
	struct ieee80211com *ic = &adapter->vap_com;
	struct ieee80211vap *vap;
	char fsm_state_lp[][32] = { 
		"FSM_CARD_NOT_READY",
		"FSM_FW_LOADED",
		"FSM_LOAD_BOOTUP_PARAMS",
		"FSM_EEPROM_CHECK",
		"FSM_EEPROM_READ_RF_TYPE",
		"FSM_EEPROM_READ_MAC_ADDR",
		"FSM_EEPROM_READ_2P4_PWR_VALS",
		"FSM_EEPROM_READ_5P1_PWR_VALS",
		"FSM_RESET_MAC_CFM",
		"FSM_BB_RF_START",
		"FSM_WAKEUP_SLEEP_VALS",
		"FSM_OPEN",
		"FSM_DEEP_SLEEP_ENABLE",
		"FSM_MAC_INIT_DONE"
	};

	TAILQ_FOREACH(vap, &ic->ic_vaps, iv_next) 
	{ 
		if (vap->iv_opmode == IEEE80211_M_STA)
			break;
	}

	seq_printf(seq, "==> ONEBOX DRIVER STATUS <==\n");
	seq_printf(seq, "DRIVER_FSM_STATE: ");
#if 1
	if (adapter->fsm_state <= FSM_MAC_INIT_DONE)
		seq_printf(seq,
			   "%s",
			   fsm_state_lp[adapter->fsm_state]);
#endif
	seq_printf(seq,
		   "(%d)\n\n", 
	           adapter->fsm_state);

	if (adapter->Driver_Mode == RF_EVAL_MODE_ON)
		seq_printf(seq,
			   "total PER packets sent : %d\n",
			   adapter->total_per_pkt_sent);

	seq_printf(seq,
		   "total beacon send : %d\n",
		   adapter->total_beacon_count);
	seq_printf(seq,
		   "total beacon Interrupts Received : %d\n",
		   adapter->beacon_interrupt);
	seq_printf(seq,
		   "beacon debugcnt : %d\n",
		   adapter->beacon_dbg_count);
	/* Mgmt TX Path Stats */
	seq_printf(seq,
		   "total_mgmt_pkt_queued : %d\t",
		   get_skb_queue_len(&adapter->host_tx_queue[4]));
	seq_printf(seq,
		   "total_mgmt_pkt_send : %d\n",
		   adapter->total_tx_data_sent[MGMT_SOFT_Q]);
	/* RX Path Stats */
	seq_printf(seq,
		   "total_mgmt_rx       : %d\n",
		   adapter->total_mgmt_rx_done_intr);
	seq_printf(seq,
		   "total_data_rx       : %d\n",
		   adapter->total_data_rx_done_intr);
	seq_printf(seq,
		   "BUFFER FULL STATUS  : %d\n",
		   adapter->buffer_full);
	seq_printf(seq,
		   "SEMI BUFFER FULL STATUS  : %d\n",
		   adapter->semi_buffer_full);
	seq_printf(seq,
		   "MGMT BUFFER FULL STATUS  : %d\n",
		   adapter->mgmt_buffer_full);
	seq_printf(seq,
		   "BLOCK_QUEUE STATUS  : %d\n",
		   adapter->sta_data_block);
	seq_printf(seq,
		   "BLOCK_AP_QUEUE STATUS  : %d\n",
		   adapter->block_ap_queues);
	if (vap)
		seq_printf(seq,
			   "PWR_SAVE STATUS  : %d\n",
			   vap->hal_priv_vap->drv_params.ps_state);

	seq_printf(seq,
		   "BUFFER FULL COUNTER  : %d\n",
		   adapter->buf_full_counter);
	seq_printf(seq,
		   "BUFFER SEMI FULL COUNTER  : %d\n",
		   adapter->buf_semi_full_counter);
	seq_printf(seq,
		   "MGMT BUFFER FULL COUNTER  : %d\n",
		   adapter->mgmt_buf_full_counter);
	/* AP mode TX data Path Statistics */
	seq_printf(seq,
		   "total_ap_vo_pkt_queued:  %8d\t",
		   get_skb_queue_len(&adapter->host_tx_queue[VO_Q_AP]));
	seq_printf(seq,
		   "total_ap_vo_pkt_send: %8d\t",
		   adapter->total_tx_data_sent[VO_Q_AP]);
	seq_printf(seq,
		   "total_ap_vo_packets dropped:  %d\n",
		   (uint32)adapter->total_tx_data_dropped[VO_Q_AP]);

	seq_printf(seq,
		   "total_ap_vi_pkt_queued:  %8d\t",
		   get_skb_queue_len(&adapter->host_tx_queue[VI_Q_AP]));
	seq_printf(seq,
		   "total_ap_vi_pkt_send: %8d\t",
		   adapter->total_tx_data_sent[VI_Q_AP]);
	seq_printf(seq,
		   "total_ap_vi_packets dropped:  %d\n",
		   (uint32)adapter->total_tx_data_dropped[VI_Q_AP]);


	seq_printf(seq,
		   "total_ap_be_pkt_queued:  %8d\t",
		   get_skb_queue_len(&adapter->host_tx_queue[BE_Q_AP]));
	seq_printf(seq,
		   "total_ap_be_pkt_send: %8d\t",
		   adapter->total_tx_data_sent[BE_Q_AP]);
	seq_printf(seq,
		   "total_ap_be_packets dropped:  %d\n",
		   (uint32)adapter->total_tx_data_dropped[BE_Q_AP]);

	seq_printf(seq,
		   "total_ap_bk_pkt_queued:  %8d\t",
		   get_skb_queue_len(&adapter->host_tx_queue[BK_Q_AP]));
	seq_printf(seq,
		   "total_ap_bk_pkt_send: %8d\t",
		   adapter->total_tx_data_sent[BK_Q_AP]);
	seq_printf(seq,
		   "total_ap_bk_packets dropped:  %d\n",
		   (uint32)adapter->total_tx_data_dropped[BK_Q_AP]);

	/*  Station mode TX data packet Statistics */
	seq_printf(seq, "total_sta_vo_pkt_queued: %8d\t",
	                      get_skb_queue_len(&adapter->host_tx_queue[VO_Q_STA]));
	seq_printf(seq, "total_sta_vo_pkt_send:%8d\t",
	                      adapter->total_tx_data_sent[VO_Q_STA]);
	seq_printf(seq,
		   "total_sta_vo_packets dropped: %d\n",
		   (uint32)adapter->total_tx_data_dropped[VO_Q_STA]);

	seq_printf(seq, "total_sta_vi_pkt_queued: %8d\t",
	                      get_skb_queue_len(&adapter->host_tx_queue[VI_Q_STA]));
	seq_printf(seq, "total_sta_vi_pkt_send:%8d\t",
	                      adapter->total_tx_data_sent[VI_Q_STA]);
	seq_printf(seq,
		   "total_sta_vi_packets dropped: %d\n",
		   (uint32)adapter->total_tx_data_dropped[VI_Q_STA]);

	seq_printf(seq, "total_sta_be_pkt_queued: %8d\t",
	                      get_skb_queue_len(&adapter->host_tx_queue[BE_Q_STA]));
	seq_printf(seq, "total_sta_be_pkt_send:%8d\t",
	                      adapter->total_tx_data_sent[BE_Q_STA]);
	seq_printf(seq,
		   "total_sta_be_packets dropped: %d\n",
		   (uint32)adapter->total_tx_data_dropped[BE_Q_STA]);

	seq_printf(seq, "total_sta_bk_pkt_queued: %8d\t",
	                      get_skb_queue_len(&adapter->host_tx_queue[BK_Q_STA]));
	seq_printf(seq, "total_sta_bk_pkt_send:%8d\t",
	                      adapter->total_tx_data_sent[BK_Q_STA]);
	seq_printf(seq,
		   "total_sta_bk_packets dropped: %d\n",
		   (uint32)adapter->total_tx_data_dropped[BK_Q_STA]);

	seq_printf(seq,
		   "total_invlaid_pkt_send: %8d\t",
		   adapter->total_data_invalid_pkt_send);

	seq_printf(seq, "total_invalid_pkt_freed: %8d\n",
	                      adapter->total_invalid_pkt_freed);

	seq_printf(seq,
		   "total_bcast_mcast_pkt_freed: %8d\n",
		   adapter->total_bcast_mcast_pkt_freed);
	seq_printf(seq,
		   "total_null_pkt_rcvd : %d\t",
		   adapter->total_null_pkt_rcvd);
	seq_printf(seq,
		   "total_unknown_interrupts: %d\n",
		   adapter->total_unknown_interrupts);
	seq_printf(seq,
		   "total RX packets dropped: %d\n",
		   (uint32)adapter->stats.rx_dropped);
	seq_printf(seq,
		   "total RX Big Size packets dropped: %d\n",
		   (uint32)adapter->big_size_pkts);
	seq_printf(seq,
		   "total TX packets dropped: %d\n",
		   (uint32)adapter->stats.tx_dropped);
	seq_printf(seq,
		   "total BufferFull's observed: %d\n",
		   (uint32)adapter->no_buffer_fulls);

	if (netif_queue_stopped(adapter->dev))
		seq_printf(seq, "Net queue stopped\n");
	else
		seq_printf(seq, "Net queue running\n");

	seq_printf(seq, "\n");
	return 0;
}

static int onebox_proc_sdio_stats_show(struct seq_file *seq, void *data)
{

	PONEBOX_ADAPTER adapter = seq->private;

	seq_printf(seq,
		   "total_sdio_interrupts: %d\n",
		   adapter->sdio_int_counter);
	seq_printf(seq,
		   "sdio_mgmt_pending_intr_count: %d\n", 
		    adapter->total_sdio_mgmt_pending_intr);
	seq_printf(seq,
		   "sdio_msdu_pending_intr_count: %d\n", 
		   adapter->total_sdio_msdu_pending_intr);
	seq_printf(seq,
		   "sdio_buff_full_count : %d\n",
		   adapter->buf_full_counter);
	seq_printf(seq,
		   "sdio_buf_semi_full_count %d\n",
		   adapter->buf_semi_full_counter);
	seq_printf(seq,
		   "sdio_unknown_intr_count: %d\n",
		   adapter->total_sdio_unknown_intr);
	seq_printf(seq,
		   "total_tx_queue_start: %d\n",
		   adapter->total_tx_queue_start);
	seq_printf(seq,
		   "total_tx_queue_stop: %d\n",
		   adapter->total_tx_queue_stop);
	seq_printf(seq,
		   "num_of_sdio_multi_pkts: %d\n",
		   adapter->num_of_sdio_multi_pkts);
	seq_printf(seq,
		   "Num_of_pkts Q0: %d, Q1: %d, Q2: %d, Q3: %d\n", 
		   adapter->sdio_pkt_count_q[0],
		   adapter->sdio_pkt_count_q[1],
		   adapter->sdio_pkt_count_q[2],
		   adapter->sdio_pkt_count_q[3]);
	return 0;
}

static int onebox_proc_debug_zone_show(struct seq_file *seq, void *data)
{
	
	seq_printf(seq,
		   "The zones available are %#x\n",
		   onebox_zone_enabled);
	return 0;
}

static ssize_t onebox_proc_debug_zone_write(struct file *filp,
					    const char __user *buff,
					    size_t len,
					    loff_t *data)
{
	char user_zone[20] = {0};

	if (!len)
		return 0;

	if (len > 20)
		return -EINVAL;

	if (copy_from_user(user_zone, (void __user *)buff, len)) 
		return -EFAULT;
	else {
		int32 dbg_zone = 0;
		if ((user_zone[0] == '0') &&
		    (user_zone[1] == 'x' || 
		     user_zone[1] == 'X'))
			dbg_zone = simple_strtol(&user_zone[2], NULL, 16);
		else
			dbg_zone = simple_strtol(user_zone, NULL, 10);

		onebox_zone_enabled = dbg_zone;
	}
	return len;
}



static int onebox_proc_version_open(struct inode *inode, struct file *file)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0))
	return single_open(file,
			   onebox_proc_version_show,
			   PDE_DATA(inode));
#else
	return single_open(file,
			   onebox_proc_version_show,
			   PDE(inode)->data);
#endif
}

static int onebox_proc_stats_open(struct inode *inode, struct file *file)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0))
	return single_open(file,
			   onebox_proc_stats_show,
			   PDE_DATA(inode));
#else
	return single_open(file,
			   onebox_proc_stats_show,
			   PDE(inode)->data);
#endif
}

static int onebox_proc_sdio_stats_open(struct inode *inode, struct file *file)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0))
	return single_open(file,
			   onebox_proc_sdio_stats_show,
			   PDE_DATA(inode));
#else
	return single_open(file,
			   onebox_proc_sdio_stats_show,
			   PDE(inode)->data);
#endif
}

static int onebox_proc_debug_zone_open(struct inode *inode, struct file *file)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0))
	return single_open(file,
			   onebox_proc_debug_zone_show,
			   PDE_DATA(inode));
#else
	return single_open(file,
			   onebox_proc_debug_zone_show,
			   PDE(inode)->data);
#endif
}
#if 0
static int onebox_proc_data_rate_open(struct inode *inode, struct file *file)
{
	return single_open(file, 
			   onebox_proc_data_rate_show,
			   PDE(inode)->data);
}
#endif


static const struct file_operations proc_version_ops = {
	.open    = onebox_proc_version_open,
	.read    = seq_read,
	.llseek  = seq_lseek,
	.release = single_release,
};	

#if 1
static const struct file_operations proc_stats_ops = {
	.open    = onebox_proc_stats_open,
	.read    = seq_read,
	.llseek  = seq_lseek,
	.release = single_release,
};	

static const struct file_operations proc_sdio_stats_ops = {
	.open    = onebox_proc_sdio_stats_open,
	.read    = seq_read,
	.llseek  = seq_lseek,
	.release = single_release,
};	
#endif	

static const struct file_operations proc_debug_zone_ops = {
	.open    = onebox_proc_debug_zone_open,
	.read    = seq_read,
	.llseek  = seq_lseek,
	.write   = onebox_proc_debug_zone_write,
};

#if  0 /* coex */
static const struct file_operations proc_data_rate_ops = {
	.open    = onebox_proc_data_rate_open,
	.read    = seq_read,
	.llseek  = seq_lseek,
	.write   = onebox_proc_data_rate_write,
};	
#endif


/**
 * This function initializes the proc file system entry.
 *
 * @param adapter   Pointer To Driver Priv Area
 *
 * @return
 * This function return the status success or failure.
 */
ONEBOX_STATUS setup_wlan_procfs(PONEBOX_ADAPTER adapter)
{
	struct proc_dir_entry *entry = NULL;

	onebox_entry = proc_mkdir("onebox-mobile", NULL);
	if (onebox_entry == NULL) {
		ONEBOX_DEBUG(ONEBOX_ZONE_ERROR, ("Unable to create onebox-mobile dir entry"));
		return ONEBOX_STATUS_FAILURE;
	} else {
		entry = proc_create_data("version",
					 0,
					 onebox_entry, 
					 &proc_version_ops,
					 adapter);
		if (entry == NULL) {
			printk("HAL : Unable to create proc entry [version]\n");
			return ONEBOX_STATUS_FAILURE;
		}
#if 1
		entry = proc_create_data("stats",
					 0,
					 onebox_entry,
					 &proc_stats_ops,
					 adapter);
		if (entry == NULL) {
			printk("HAL : Unable to create proc entry [stats]\n");
			return ONEBOX_STATUS_FAILURE;
		}

		entry = proc_create_data("sdio_stats",
					 0,
					 onebox_entry,
					 &proc_sdio_stats_ops,
					 adapter);
		if (entry == NULL) {
			printk("HAL : Unable to create proc entry [sdio_stats]\n");
			return ONEBOX_STATUS_FAILURE;
		}
#endif

		entry = proc_create("debug_zone",
				    0,
				    onebox_entry,
				    &proc_debug_zone_ops);
		if (entry == NULL) {
			printk("HAL : Unable to create proc entry [debug_zone]\n");
			return ONEBOX_STATUS_FAILURE;
		}

	}
	return ONEBOX_STATUS_SUCCESS;
}

/**
 * Removes the previously created proc file entries in the
 * reverse order of creation
 *
 * @param  void
 * @return void 
 */
void destroy_wlan_procfs(void)
{
	remove_proc_entry("version", onebox_entry);
	remove_proc_entry("stats", onebox_entry);
	remove_proc_entry("sdio_stats", onebox_entry);
	remove_proc_entry("debug_zone", onebox_entry);
	remove_proc_entry("onebox-mobile", NULL);
	return;
}
