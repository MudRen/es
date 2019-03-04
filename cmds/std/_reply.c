//#pragma save_binary

/*
// reply.c
// Command to send a message to the last person who sent you a tell.
// There was a very old version of this that was wrecked by the move
// to 0.9.0. Prydain and Blackpool played with it. Someone got it
// working but didn't add a header, probably Prydain.
// Mobydick added this header and the help, 11-20-92
// Pallando re-wrote the whole command from new (92-12-12)
// Watcher modified it for use with the new body system (93-03-26)
// 93-08-18 Grendel@tmi-2 added input_to option to get rid of those
//                        crossed lines.
*/

#include <net/daemons.h>
#include <mudlib.h>

inherit DAEMON ;

void got_reply(string msg, string who);

int cmd_reply( string msg )
{
	mixed who;
	
    
      
	who = (string)this_player()-> query( "reply" );
 
	if(!who) return notify_fail("��Ҫ�ش�˭��\n");
 
    if( (int)this_player()->query("talk_points") < 5 )
      return notify_fail(
		"�㼸��û��������������λ�Ӧ? \n");
	if( !msg ) {
		input_to("got_reply", 0, who);
		write("reply>");
		return 1;
	}
	got_reply(msg, who);
	this_player()->add( "talk_points", -5 );
	return 1;
}
 
void got_reply(string msg, mixed who)
{
	object user;
	string target, mud;

	if( !msg || msg == "" ) {
		write("���ش������.\n");
		return;
	}

	if( stringp(who) ) {
		who = lower_case( who );
		if( sscanf( who, "%s@%s", target, mud ) == 2 )  {
			if(sizeof(explode(mud, " ")) > 1)  
				mud = implode(explode(mud, " "), ".");
			write( TS_D-> remote_tell( this_player(), target, mud, msg ) );
			return;
		}
		user = find_player(who);
		if(!user) user = find_living(who);
	} else if( objectp(who) ) {
		if( living(who) && who->query("npc") ) {
			write( "��ش�"+who->query("short")+": "+msg+"\n");
			tell_object( who, this_player()->query("c_name") + "������ : "+msg+"\n" );
		}
		return;
	}

	if(!user) {
		write(capitalize(who) + "�Ѿ�����������.\n");
		return;
	}

	if( (int)this_player()->query("npc") && !wizardp(user) )
		write( TS_D-> tell_user( this_player()-> query( "name" ),
		0, who, msg) );
	else write( TS_D->tell_user(this_player()->link_data("name"),
		0, who, msg) );

	return;
}

int help() {
  write( 
@HELP
ʹ�ø�ʽ: reply <��Ϣ>

�ش�ղ���tell���㽻̸����ң�����ʡ���û���.
HELP
			       );
  return 1;
}
