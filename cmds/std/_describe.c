//#pragma save_binary

// _describe.c -- Code to 'describe' yourself
// written by Truilkan@TMI - 92/04/26
// Changed by Pallando (93-04-17) in response to bug from Robocoder.
//

#include <mudlib.h>

inherit DAEMON ;

// cmd_describe(string) 

int cmd_describe(string str)
{
	int pid;
	string file;

		write( "�����༭:\n" );
		file = temp_file( "c_desc" );
		if ((string)this_player()->query("long"))
			write_file(file,(string)this_player()->query("long"));
	this_player()->edit(file, "postit", this_object());
	return 1;
}

void postit(string header)
{
	string filename, body;

	filename = (string)this_player()->query_edit_filename();
    if ( !filename ) return ;
	body = read_file(filename);
	rm(filename);
	this_player()->set_edit_filename("");
		this_player()->set("long", body);
}

int help() {
	write (@HELP
ָ���ʽ: describe

�趨�Լ�����ò����.
HELP
 );
	return 1 ;
}
