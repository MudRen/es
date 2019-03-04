//#pragma save_binary
/*	File	:  /cmds/std/_mudlist.c
//	Creator	:  Watcher@TMI-2   (01/17/93)
//
//	Simple directory of all muds available in name server

// 93-08-15 Grendel@tmi-2 Updated to use the DNS
*/

#include <config.h>
#include <net/daemons.h>
#include <mudlib.h>
#include <net/macros.h>

inherit DAEMON ;

#define	SYNTAX	"Syntax: mudlist [optional mudname]\n"

int cmd_mudlist(string str)
{
	mapping mud_list;
	mapping mud_svc;
	mixed *muds;
	string output;
	int loop, size;

  //	Obtain mapping containing mud data

	mud_list = (mapping)DNS_MASTER->query_muds();
  // so we recognise ourselves as a DNS mud
	mud_svc = DNS_MASTER->query_svc() + ([ mud_name() : 0 ]);

	if(!mud_list) {
		write("Mudlist:  No muds are presently stored in the mud name server.\n");
		return 1;
	}

  //	Get list of all mud names within name server

	muds = keys( mud_list );
	muds -= ({ "DEFAULT" });

  //	Place mudlist into alphabetical format

	muds = sort_array( muds, "compare", this_object() );

  // 	If mudname provided, search server's database for a match
  //	and display its cooresponding address

	if(str && str != "") {
		str = htonn(str);

      if(!mapp( mud_list[str] ))
	{
	  write("Requested mud is not listed in " + cap_words(mud_name()) +
		 "'s name server.\n");
	  return 1;
	}

      printf("%-24s%-18s%8s\t %s \t %s\n", nntoh(str),
	     mud_list[str]["HOSTADDRESS"], mud_list[str]["PORT"],
	     undefinedp(mud_svc[str]) ? "" : "*",
	    mud_list[str]["MUDLIB"] == "TMI-2" ? "*" : "");
      return 1;
    }

  output = "Mud name\t\t  Address\t      Port\tDNS\tES\n"
	   "========\t\t  =======\t      ====\t===\t===\n";

  //	Loop through mud list and store one by one

  for(loop = 0, size = sizeof(muds); loop<size; loop++)
      output += sprintf("%-24s%-18s%8s\t %s \t %s\n", muds[loop], 
			mud_list[muds[loop]]["HOSTADDRESS"],
			mud_list[muds[loop]]["PORT"],
			undefinedp(mud_svc[muds[loop]]) ? "" : "��",
			mud_list[muds[loop]]["MUDLIB"] == "Eastern Stories" ? "��" : "");

  //	Display dumped mudlist output through user's more pager

  this_player()->more( explode(output, "\n") );

  return 1;
}

//	Comparison function for alphabetical sorting

int
compare(string one, string two)
{  return strcmp(one, two);  }

int
help()
{

  write( SYNTAX + "\n"
"This command gives a full list of all muds and their addresses\n"
"contained within " + capitalize(mud_name()) + "'s name server.  "
"If a mudname is given,\na match will be attempted against the server "
"and its address\ndisplayed.  Muds which are part of the dns network "
"are marked\nwith a '*'.\n");

  return 1;
}

