//#pragma save_binary

// #include <disclaimer.h>
// The Version command.
// Brought to you by Buddha@TMI
// Updated for mudlib version by Watcher@TMI
// 4-19-92

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

int help();

int cmd_version(string str) {
	if (str) return help();
 
	write(capitalize(mud_name()) + " is running the " + MUDLIB_VERSION +
	      " mudlib on " + version() + "\n");
	return 1;
}
int
help() {
  write(@HELP

����ָ���������֪�����mud��ʲô�汾����ת�˶��.

HELP
);
  return 1;
}