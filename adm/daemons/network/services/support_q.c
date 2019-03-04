#define WHO find_player("iral")
#define TELL(x) if(WHO) message( "info", x + "\n", WHO );

/* File    : support_q.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to query another mud to see what protocols/services
 * they support.
 */
#include <uid.h>
#include <mudlib.h>
#include <net/dns.h>
#include <net/macros.h>
#define SERVICES_PATH "/adm/daemons/network/services/"

inherit DAEMON;

// Support.  Do we support this protocol?
void
incoming_request(mapping info)
{
  if(!ACCESS_CHECK(previous_object())) return;

  if (stringp(info["NAME"]) && stringp(info["PORTUDP"]))    {
      // dont want requests from ourself
      if(info["NAME"] == Mud_name())
	return ;

      if(!DNS_MASTER->query_mud_info(info["NAME"]))
	PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

      // if the file exists that is enough to know that we support
      // it, unless there is a param request, in which case we have
      // to call_other to the file to check.
      if(!file_exists(SERVICES_PATH+info["CMD"]+".c") 
	 || (!undefinedp(info["PARAM"])
	 && call_other(SERVICES_PATH+info["CMD"], "support_"+info["PARAM"])))
	// we don't support it
	DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
		sprintf("@@@%s||NAME:%s||PORTUDP:%d||CMD:%s"
			"||NOTSUPPORTED:yes||ANSWERID:%s@@@\n",
			DNS_SUPPORT_A, Mud_name(), udp_port(), info["CMD"]+
			(!undefinedp(info["PARAM"]) ?
				"||PARAM:"+info["PARAM"] : ""),
			info["ANSWERID"]));
      else
	// we do support it
	DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
		sprintf("@@@%s||NAME:%s||PORTUDP:%d||CMD:%s"
			"||SUPPORTED:yes||ANSWERID:%s@@@\n",
			DNS_SUPPORT_A, Mud_name(), udp_port(), info["CMD"]+
			(!undefinedp(info["PARAM"]) ?
				"||PARAM:"+info["PARAM"] : ""),
			info["ANSWERID"]));
    } //if (stringp(info["NAME"]) && stringp(info["PORTUDP"]))
}

void
send_support_q(string host, mixed port, string cmd, string param)
{
    int idx;
    function f;

    if(!ACCESS_CHECK(previous_object())) return;

    if (!param)
	param = "";
    
    f = (: previous_object(), "support_q_callback" :);
    idx = index_add(f);

    DNS_MASTER->send_udp(host, port, sprintf(
	    "@@@%s||NAME:%s||PORTUDP:%d||CMD:%s||ANSWERID:%d@@@\n",
	    DNS_SUPPORT_Q, Mud_name(), udp_port(),
	    cmd + (strlen(param) ? "||PARAM:"+param : ""), idx));
}

void
create()
{
    seteuid(ROOT_UID);
}

