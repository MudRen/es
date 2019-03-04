//#pragma save_binary
 
//	File	:  /cmds/std/_suicide.c
//	Creator	:  Watcher@TMI	(02/08/93)
//
//	This command allows a player to commit suicide and have
//	the character file deleted from the database.
 
#include <config.h>
#include <mudlib.h>
#include <logs.h>
#define mssg ({ "�������", "����а��", "����Ѫ��", "���ݽ�թ", "������թ", })

inherit DAEMON ;
 
//  If you do not wish suicided files to be saved in the
//  archive directory, simply #undef ARCHIVE_DIR
 
int busy;
 
int cmd_suicide()
{
	//	Block any attempts by wizards to suicide
	if(wizardp(this_player())) {
		write( 
			"��ʦ������ɱ������㲻���������ʦ���� mail �� God��\n");
		return 1;
	}

	// 	Prevent someone from suiciding the Guest character
	if((string)this_player()->query("name") == "guest") {
		write( 
			"�ÿͲ�����ɱ����Ȼ���˾Ͳ������ˡ�\n");
		return 1;
	}
 
	//	Check to see if the command's busy flag is set
	if(busy) {
		write( 
			"��ɱָ��ͬʱֻ����һ�����ã����������������ڿ��ǵ��У����Ժ�\n");
		return 1;
	}

	busy = 1;				//  Set busy flag on
	write( 
		"�������ɱ�Ļ�������������������ϵ���Զɾ��������ȷ��\n"
		"Ҫ������������� [y/n] ");
	input_to("confirm_suicide");
 
	return 1;
}
 
static int confirm_suicide(string str)
{
	if(!str || member_array(lower_case(str), ({ "yes", "y" })) == -1) {
		write(
			"�ܺã�������ɽ�ڣ�����û���ա�������������������\n");
		busy = 0;
		return 1;
	}
 
	write( 
		"\nΪ�˰�ȫ�������������������ȷ��: ");
	input_to("pass_check", 1);
 
	return 1;
}
 
static int pass_check(string str)
{
	string password, name;
	object *items, *usrs;
	int i;
 
	busy = 0;				// Reset busy flag
 
	//	Get player's name for backup purposes
	name = (string)this_player()->query("name");
 
	//	Get the user's password from the linked connection object
	password = ((object)this_player()->query_link())->query("password");
 
	//	Check to see the inputed password matches the actual password
	if(password != crypt(str, password)) {
		write( 
			"�������\n");
		return 1;
	}
 
	write( 
		"�ðɣ���������Ը��\n"
		"һ���������������Ȼ�������ǰһƬ���....��\n");
 
	tell_room(environment(),
		"һ������ͻȻ���������ֱֱ�Ĵ���"+this_player()->query("c_name")+
		"��ͷ�ϣ�\n������ᣬ����ֻʣ��һ�ѻҡ�",
		this_player());
 
	//	Save the players attributes before file transfer 
 
	this_player()->save_data();
 
	//	If SUICIDE defined, write all suicides to a log file
 
#ifdef SUICIDE
	log_file(SUICIDE, capitalize(name) + " committed suicide from " +
		 query_ip_name(this_player()) + " [" +
		 extract(ctime(time()), 4, 15) + "]\n");
#endif
 
	//	Either move data files to ARCHIVE_DIR dir, or completely delete
 
	if(ARCHIVE_DIR) {
	rename(user_data_file(this_player()) + SAVE_EXTENSION, ARCHIVE_DIR + "user/" +
	  name + SAVE_EXTENSION);
	rename(PDATA_DIR + name[0..0] + "/" + name + SAVE_EXTENSION, ARCHIVE_DIR +
	  "connection/" + name + SAVE_EXTENSION);
    "/adm/daemons/backup"->remove_backup(this_player());
	}
 
	else {
	rm( user_data_file(this_player()) + SAVE_EXTENSION );
	rm( PDATA_DIR + name[0..0] + "/" + name + SAVE_EXTENSION );
	"/adm/daemons/backup"->remove_backup(this_player());
	}
 
	//	Remove the user object and connection from the game
    
    usrs = users();
    for( i=0 ; i<sizeof(usrs); i++ ) {
      if( !environment(usrs[i]) || usrs[i]==this_player() ) continue;
      tell_object( usrs[i], 
        sprintf("һ������ %s (%s) ��ɵ��������ܲ������\n%s�����磬�ո������˶���!\n",
          this_player()->query("c_name"), this_player()->query("name"),
          mssg[random(5)] ) );
    }
    items = all_inventory( this_player() );
    for( i=0 ; i<sizeof(items); i++ )
      if( items[i]->query("prevent_drop") )
        items[i]->remove();
	destruct( this_player()->query_link() );
	destruct( this_player() );
	return 1;
}
 
int help() {
	write(@HELP
ʹ�ø�ʽ: suicide

���ָ�ɾ��������ϣ������濼�ǣ�С��ʹ�ã�
HELP
);
	return 1;
}
 
