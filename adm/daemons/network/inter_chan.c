/* File    : /adm/daemons/network/inter_chan.c
 * Creator : Grendel@tmi-2
 * When    : 93-08-16

 * This daemon sends channel broadcasts from the mudlib to the
 * network, and sends incomings from the network to the mudlib.
 */
#include <daemons.h>
#include <channels.h>
#include <net/dns.h>
#include <net/macros.h>
#include <net/config.h>

int daemon_apply(object user, string channel, string message, int emote)
{
	int i;
	string *strs;
	mapping muds;

	if( !user ) return 0;
	if ( ! previous_object() ) return 0 ;
	if( geteuid(previous_object()) != ROOT_UID ) return 0;

	if(message[0..6]==":emote ") { 
		message = message[7..-1];
		emote = 1;
	}

	GWIZ->send_gwizmsg(channel, geteuid(user), message, emote);

	if(channel == "INTERWIZ")
  		TS_D->remote_channel(user, channel, message);

	return 1;
}

void incoming_channel(string channel, string wizfrom, string mudfrom,
	string message, string emote)
{
	if ( ! previous_object() ) return ;
	if( !ACCESS_CHECK(previous_object()) ) return;

	if( !channel ) channel = "CREATOR";

	CHANNELS_D->parse_channel(channel, message, wizfrom+"@"+nntoh(mudfrom),
		(emote ? 1 : 0 ));
}
