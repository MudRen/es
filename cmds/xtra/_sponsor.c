//#pragma save_binary

/*
// File     : _sponsor.c
// Purpose  : raise a wizard's position within a domain
// **-**-** : Jubal brought it to you.
//            This file is part of the TMI-2 distribution mudlib
//            Please retain this header if you use any of this code
// 92-04-24 : Buddha added logging and notification.
// 92-04-25 : Sulam made it limit you to one LESS than your position
// 92-09-24 : Prydain corrected the starting workroom for new mudlib
// 93-01-23 : Buddha revised it to communicate with a modified Domains daemon
//            and to allow promotion of users not currently logged in
//            (Mobydick helped a little with that.)
// 93-02-05 : Pallando changed it to use the same generic workroom as home.c
// 93-08-07 : Grendel fixed it so you can't sponsor a non-wizard
// 93-08-23 : Pallando made it mkdir the "/u/<letter>" dirs if not there
//            and fixed the 'under' option.
//            and fixed the 'meglomania' bug (promotion beyond God).
*/

#include <mudlib.h>
#include <daemons.h>
#include <domains.h>
#include <login_macros.h>

inherit DAEMON;

string workroom;

int cmd_sponsor( string arg )
{
	string domain, target, under;
	string fname;
	object tmp, myLink, targetLink;
	int myLev, targetLev;
	
	if( !arg || sscanf( arg, "%s %s", target, domain ) < 2 )
		return notify_fail( "Usage: sponsor <name> <guild> [under]\n" );

	sscanf( domain, "%s %s", domain, under );
	if( member_array( domain, DOMAIN_LIST ) ==  - 1 )
		return notify_fail( "No such domain.\n" );

	tmp = previous_object();
	if( !interactive( tmp ) )
		return 0;
		
	// no security hole here...
	myLink = (object)tmp->query_link();
	myLev = member_array(
		(string)DOMAIN_D-> query_domain_level( myLink, domain ),
		LEVEL_LIST );

	// If the command giver is an admin...well, let them do whatever.
	if( member_group( geteuid( myLink ), "admin" ) )
		myLev = sizeof( LEVEL_LIST );

	if( myLev < MIN_SPONSOR_LEVEL ) 
		return notify_fail( "You must be at least " + LEVEL_LIST[MIN_SPONSOR_LEVEL] +
			" level in the domain to sponsor someone.\n" );

	if( under && ( myLev < ( sizeof( LEVEL_LIST ) - 1 ) ) )
		return notify_fail( "Only admins or " + LEVEL_LIST[sizeof( LEVEL_LIST ) - 1] +
		  " may use the 'under' option.\n" );

	if( !under ) under = geteuid( myLink );
	// Ask the finger daemon to get a link for us, 
	// so that if they are not on at the time, we can still do this.
	targetLink = FINGER_D->restore_data( target );
	if( !targetLink )
		return notify_fail( "No such user: "+capitalize(target)+".\n" );

	if( !targetLink->query( "wizard" ) )
		return notify_fail( target + " is not a wizard (use makewiz)\n" );

	targetLev = member_array(
	  ( string )DOMAIN_D->query_domain_level( targetLink, domain ),
	  LEVEL_LIST );

	if( targetLev >= myLev ) {
		write( ( string ) targetLink-> CAP_NAME +
			" is too high a level for you to sponsor.\n" );
		return 1;
	} else if( targetLev < ENTRY_LEVEL ) {
		targetLev = ENTRY_LEVEL;
		if( DOMAIN_D->set_domain( targetLink, domain, LEVEL_LIST[targetLev], under ) ) {
			printf( "Level set to %s (%s).\n", LEVEL_LIST[targetLev], under );
			tmp = find_player( target );
			if( tmp )
				tell_object( tmp, ( string ) this_player()-> query( "cap_name" ) +
					" has sponsored you to wizard" +
					" in the " + domain + " domain.\n" );
			log_file( "sponsors",
				(string)this_player()-> link_data( "cap_name" ) +
				" promoted " + targetLink-> query( "cap_name" ) +
				" to " + LEVEL_LIST[targetLev] +
				" in the " + domain + " domain.\n" );
			PROMOTION_D->add_wiz_list(target);
			PROMOTION_D->reset_access(targetLink);
		} else {
			write( "Failed to set level.\n" );
			return 1;
		}
		
		// This command is usually the first one to encounter the directories
		// "/u/a/" to "/u/z/" not existing in a newly untarred mudlib.
		fname = "/u/" + extract( target, 0, 0 );
		if( file_size( fname ) != -2 )
		{
			if( file_size( fname ) >= 0 )
			{
				write( "Directory name currently taken by file.\n" );
				write( "Unable to create directory.\n" );
				return 1;
			}
			mkdir( fname );
		}
		fname += "/" + target;
		if( file_size( fname ) != -2 )
		{
			if( file_size( fname ) >= 0 )
			{
				write( "Directory name currently taken by file.\n" );
				write( "Unable to create directory.\n" );
				return 1;
			}
			mkdir( fname );
			write( "Created directory " + fname + "\n" );
		}
		fname += "/workroom.c";
		if( file_size( fname ) ==  - 1 )
		{
			if( !workroom ) workroom = read_file( "/obj/workroom.c" );
			write_file( fname, workroom );
			write( "Created file " + fname + "\n" );
			log_file( "workrooms", "Created " + fname + " on " +
			  ctime( time() ) + ".\n" );
		}
		// This will force a save, and if the user is not on, remove() as well.
		targetLink-> save_data();
		targetLink-> clean_up();
		return 1;
	}
	targetLev++;
	if( targetLev == sizeof( LEVEL_LIST ) )
	{
		targetLev--;
		write( capitalize( target ) + " is already " + LEVEL_LIST[targetLev] +
			" of the " + domain + " domain.\n"+
			"Sorry, but you can't get higher than that!\n" );
	}
	if( DOMAIN_D->set_domain( targetLink, domain, LEVEL_LIST[targetLev], under ) ) {
		tmp = find_player( target );
		if( tmp )
			tell_object( tmp, ( string ) myLink-> CAP_NAME +
			  " has promoted you to " + LEVEL_LIST[targetLev] +
			  " in the " + domain + " domain.\n" );
		PROMOTION_D->reset_access(targetLink);
		PROMOTION_D->add_wiz_list(target);
		write( "Level set to " + LEVEL_LIST[targetLev] + ".\n" );
		log_file( "promotes", ( string ) myLink-> CAP_NAME +
		  " promoted " + capitalize( target ) + " to " + LEVEL_LIST[targetLev] +
		  " in the " + domain + " domain.\n" );
	} else
		write( "Failed to set level.\n" );

	// This will force a save, and if the user is not on, a remove() as well.
	targetLink->clean_up();
	return 1;
}

int help() {
	
	write(
	  "Command: sponsor\n" +
	  "Syntax:  sponsor <name> <domain> [under]\n" +
	  "  The sponsor command is used to enroll and promote <name> in the\n" +
	  "domain <domain>.  You must be of at least initiate level in domain\n" +
	  "<domain> to use sponsor.  If <name> is not in domain <domain>, sie\n"
	  "will be placed in the domain at the novice level.  If <name> is\n" +
	  "already in the domain, then he/she will be promoted one level.  You\n" +
	  "can only promote people up to one level below yourself.  If <name>\n" +
	  "does not have a directory, then one will be created for him/her,\n" +
	  "and a basic workroom placed in it.  Please exercise some caution\n" +
	  "in who you promote to initiate level, as he/she will be able to add\n" +
	  "new directories with this command.\n" +
	  "  Special for sages and admins, the <under> parameter allows you to\n" +
	  "change who is the offical sponsor of <name>.  If <name> is not in\n" +
	  "<domain>, then he/she will be added, otherwise his/her level will\n" +
	  "be unchanged.\n" +
	  "  See also:  domains, demote\n"
	  "[PS] It would be better to do it at on_line user.\n" );
 
	return 1;
}
