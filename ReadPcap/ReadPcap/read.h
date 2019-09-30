#pragma once
#ifndef _READ_H_
#define _READ_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <net/ethernet.h>
#include <netpacket/packet.h>
#include <linux/if_ether.h>
#include <pthread.h>
#include <pcap.h>
#include <unistd.h>
#define LINE_LEN 16
void dispatcher_handler(u_char *, const struct pcap_pkthdr *, const u_char *);
FILE* wfd;
FILE* rfd;
int gl_fdSock = -1;
int flag = 0;


struct sockaddr_in gl_localSockaddr;
struct sockaddr_in gl_remoteSockaddr;
/**********************************************************/
int ReadPcap(const char* FileName)
{
	pcap_t *fp;
	int n = 1;
	char errbuf[PCAP_ERRBUF_SIZE];
	//打开pcap文件
	/* Open the capture file */
	if ((fp = pcap_open_offline(FileName, errbuf)) == NULL)
	{
		printf("Unable to open the file %s.\n", FileName);
		return -1;
	}
	//打印出pcap文件里面的所有包数据
	/* read and dispatch packets until EOF is reached */
	pcap_loop(fp, 0, dispatcher_handler, NULL);
	//关闭打开pcap文件的指针
	pcap_close(fp);
	close(gl_fdSock);
	return 0;
}
/**********************************************************/
void dispatcher_handler(u_char *temp1, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
	u_int i = 0;
	int iDataLen = 0;
	char* pchDataInfo = NULL;
	struct iphdr*   pip = NULL;
	struct tcphdr*  pTcp = NULL;
	char* pchBuf = NULL;
	int z = 0;
	pip = (struct iphdr*)(pkt_data + sizeof(struct ether_header));
	if (pip->protocol != IPPROTO_TCP)
	{
		printf("ignore package: (%ld)\n", header->len);
		return;
	}
	pTcp = (struct tcphdr *)((char *)pip + pip->ihl * 4);
	iDataLen = ntohs(pip->tot_len) - (pip->ihl * 4) - (pTcp->doff * 4);
	pchDataInfo = (char *)pTcp + pTcp->doff * 4;
	//fwrite(pchDataInfo, 1, iDataLen, wfd);
	for(int z = 0;z < iDataLen;z++)
	{
		if (flag == 1)
		{
			fwrite(&pchDataInfo[z], 1, 1, wfd);
		}
		//jpeg开始
		if ((unsigned char)pchDataInfo[z] == 0xff && (unsigned char)pchDataInfo[z + 1] == 0xd8)
		{
			flag = 1;
			fwrite(&pchDataInfo[z], 1, 1, wfd);
		}
		//jpeg结束
		if ((unsigned char)pchDataInfo[z] == 0xff && (unsigned char)pchDataInfo[z + 1] == 0xd9)
		{
			flag = 0;
			fwrite(&pchDataInfo[z], 1, 1, wfd);
			fwrite(&pchDataInfo[z + 1], 1, 1, wfd);
		}
	}
}
/**********************************************************/


#endif
