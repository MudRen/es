//#pragma save_binary

/*
// The "demote" command.
// Brought to you by Jubal.
// Notification and logging added by Huma (4/25/92)
// Revised to communicate with a modified Domains daemon by Buddha, and
// also allow you to demote someone who is not logged in at the
// moment (1/23/93)
// Part of the TMI mudlib.
*/


#include <mudlib.h>
#include <login_macros.h> 
#include <daemons.h>
#include <domains.h>
#include <login_macros.h>

inherit             DAEMON;

int
cmd_demote(string arg)
{
    string              domain, target;
    object              tmp, myLink, targetLink;
    int                 myLev, targetLev;

    if( !arg || sscanf(arg, "%s %s", target, domain)<2 )
    	return notify_fail("Usage: demote <name> <domain>\n");
    if( member_array(domain, DOMAIN_LIST) == -1 )
		return notify_fail("No such domain.\n");
    tmp = previous_object();
    if (!interactive(tmp))
	return 0;
    //no security hole here...
    myLink = (object) tmp->query_link();
    myLev = member_array( (string)DOMAIN_D->query_domain_level(myLink, domain),
		LEVEL_LIST);
 	/* If the command giver is an admin...well, let them do whatever. */
    if( member_group(geteuid(myLink), "admin") )
		myLev = sizeof(LEVEL_LIST);
    if (myLev < MIN_SPONSOR_LEVEL)
		return notify_fail(
		    "You must be at least " +
		    LEVEL_LIST[MIN_SPONSOR_LEVEL] +
		    " level in the domain to demote someone.\n");
 /*
  * Ask the finger daemon to get a link for us, so that if they are not on at
  * the time, we can still do this. 
  */
    targetLink = FINGER_D->restore_data(target);
    if( !targetLink )
		return notify_fail("No such user.\n");
		
    targetLev = member_array((string)DOMAIN_D->query_domain_level(targetLink, domain),
		LEVEL_LIST);
    if( targetLev >= myLev ) {
		write((string) targetLink->CAP_NAME +
			" is too high a level for you to demote.\n");
		return 1;
    } else if( targetLev < ENTRY_LEVEL ) {
    	write((string)targetLink->CAP_NAME + " is not in that domain.\n");
		return 1;
    }
    targetLev--;
    if( DOMAIN_D->set_domain(targetLink, domain, 
    	LEVEL_LIST[targetLev], geteuid(myLink))) {
		tmp = find_player(target);
		if( targetLev == 1 ) {
	    	if( tmp )
				tell_object(tmp, (string) myLink->CAP_NAME +
		       " has remove you from the " + domain + " domain.\n");
		    PROMOTION_D->reset_access(targetLink);
	    	write("Removed from domain.\n");
	    	log_file("demotes", (string) myLink->CAP_NAME +
		    	 " removed " + capitalize(target) +
		    	 " from the " + domain + " domain.\n");
		} else {
			if( tmp )
				tell_object(tmp, (string) myLink->CAP_NAME +
			    	" has demoted you to " + LEVEL_LIST[targetLev] +
			    	" in the " + domain + " domain.\n");
			PROMOTION_D->reset_access(targetLink);
	    	write("Level set to " + LEVEL_LIST[targetLev] + ".\n");
	    	log_file("demotes", (string) myLink->CAP_NAME +
	    		" demoted " + capitalize(target) + " to " + LEVEL_LIST[targetLev] +
		     	" in the " + domain + " domain.\n");
		}
    } else {
		write("Failed to set level.\n");
    }
 /*
  * This will force a save, and if the user is not on, a remove() as well. 
  */
    targetLink->clean_up();

    return 1;
}


int help()
{
    write(
	  "Command: demote\n" +
	  "Syntax:  demote <name> <domain>\n" +
	  "  The demote command lowers the level of <name> in domain <domain> by\n" +
      "one.  If <name>'s level is lowered below novice, he/she will be\n" +
      "removed from the domain.  You must be of at least initiate level to\n" +
      "demote people, and you can only demote people of lower level than\n" +
	  "yourself.\n" +
	  "  See also: domains, sponsor\n"
	  "[PS] It would be better do it at on_line user.\n" );
    return 1;
}

/* EOF */
