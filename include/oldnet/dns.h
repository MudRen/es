/* This network header file contains the macros used by the DNS master
 * daemons and its auxiliary daemons.
 */
#ifndef __NET__DNS_H
#define __NET__DNS_H

#ifndef NETWORK_MASTER
#include <net/daemons.h>
#endif

#define AUX_PATH "/adm/daemons/network/dns_aux/"

#define PING_Q     (AUX_PATH+"ping_q")
#define PING_A     (AUX_PATH+"ping_a")
#define MUDLIST_Q  (AUX_PATH+"mudlist_q")
#define SUPPORT_Q  (AUX_PATH+"support_q")
#define STARTUP    (AUX_PATH+"startup")
#define SHUTDOWN   (AUX_PATH+"shutdown")
#define GTELL      (AUX_PATH+"gtell")
#define GWIZ       (AUX_PATH+"gwizmsg")

/* The currently known types */
#define DNS_STARTUP          "startup"
#define DNS_SHUTDOWN         "shutdown"
#define DNS_PING_Q           "ping_q"
#define DNS_PING_A           "ping_a"
#define DNS_SUPPORT_Q        "support_q"
#define DNS_SUPPORT_A        "support_a"
#define DNS_RWHO_Q           "rwho_q"
#define DNS_RWHO_A           "rwho_a"
#define DNS_MUDLIST_Q        "mudlist_q"
#define DNS_MUDLIST_A        "mudlist_a"
#define DNS_GFINGER_Q        "gfinger_q"
#define DNS_AFFIRMATION_A    "affirmation_a"
#define DNS_GFINGER_A        "gfinger_a"
#define DNS_GWIZMSG          "gwizmsg"
#define DNS_WARNING          "warning"
#define DNS_GTELL            "gtell"

/*
 * This is the number of retrys we ping the mud for before we decide
 * it has gone down.
 */
#define MAX_RETRYS 2
#define DNS_NO_CONTACT "_dns_no_contact"

#endif //__NET__DNS_H
