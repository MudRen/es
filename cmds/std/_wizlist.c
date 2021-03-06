//#pragma save_binary

// _wizlist.c
// By Annihilator Oct 24, 1993

#include <uid.h>

string list;

void create()
{
	int i;
	string *dirs, *wiz_names;

	seteuid(ROOT_UID);
	dirs = ({ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
		  "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" });
	wiz_names = ({});
	for(i=0; i<sizeof(dirs); i++ ) {
		if( file_size("/u/"+dirs[i])!=-2 )
			continue;
		wiz_names += get_dir("/u/"+dirs[i]+"/");
	}
	if( !sizeof(wiz_names) ) list = "No wizards found, strange .... ";
	else {
		list = "东方故事巫师群 ( 依代号英文字母顺序排列 ):";
		for(i=0; i<sizeof(wiz_names); i++) {
			if( i%5 == 0 ) list += "\n  ";
			list += sprintf("%-15s", capitalize(wiz_names[i]));
		}
		list += "\n";
	}
}

int cmd_wizlist(string arg)
{
	write(list);
	return 1;
}

int help()
{
	write( @C_HELP
指令格式: wizlist

这个指令列出所有东方故事中的巫师阵容，好好地向他们致敬吧。
C_HELP
	);
	return 1;
}
