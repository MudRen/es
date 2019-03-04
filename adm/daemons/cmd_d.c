/*
// File     : cmd_d.c
// Purpose  : This file acts as an Application Program Interface for
//            command parsing.  It maintains a table of all available
//            commands and adds new elements when necessary.
// 92-02-25 : Written by Buddha@TMI based on the old cmd_d.c, by Sulam@TMI,
//            which did not deal with multiple "bin" directories.
//            This file is part of the TMI-2 mudlib distribution.
//            Please retain this header if you use any of this code.
// 92-03-08 : Truilkan@TMI added the ADM_CMDS dir
// 93-02-05 : Pallando@TMI-2 added the REF_CMDS and WIZF_CMDS dirs
// 93-07-22 : Pallando@TMI-2 added the WIZX_CMDS dir
// 93-08-25 : Pallando@TMI-2 changed REF_CMDS to OBJ_CMDS
//            I thought the point of defines was not having to change them? 8-)
*/


#include <uid.h>
#include <config.h>

mapping cmd_table;

void	create();
int	rehash(string path);
string 	find_cmd(string cmd, string *path);

void create() {
	    seteuid(ROOT_UID);
	    cmd_table = ([ ]);
	    rehash(STD_CMDS);
	    rehash(WIZ_CMDS);
	    rehash(ADM_CMDS);
        rehash(WIZX_CMDS);
        rehash(WIZF_CMDS);
        rehash(OBJ_CMDS);
}

// Function: 	find_cmd
// Purpose:	looks up the command entered in the mapping, and loads the
//		entry for its directory if not loaded.
// Arguements:	the command typed, and the path to be searched for it
// Returns:	the full path (minus the .c) for the command.
// Other:	may cause errors if there are files other than "bin" files
//		in the directory.  This should be tested.
string find_cmd(string cmd, string *path) {
	int i;

	for (i=0;i<sizeof(path);i++) {
		/* first check for invalid path */
		if(!cmd_table[path[i]] && !rehash(path[i])) continue;
		/* then see if the command is there */
		if(member_array(cmd, cmd_table[path[i]]) > -1)
			return path[i] + "/_" + cmd;
	}
	return 0;
}

// Function:	rehash
// Purpose:	updates the mapping for the directory specified, when
//		new commands are added or old ones are removed.
// Arguements:	the path of the directory to be updated
// Returns:	1 if success, 0 if there is no such directory
// Other:	There should a function to update all the directories
//		stored.  Perhaps this file should save itself and restore
//		itself so as to further minimize disk usage.
int rehash(string path) {
	string *bin_ls, *result, tmp;
	int i;
        if(!stringp(path)) { write("Badness! Invalid path!\n"); return 0; }

	if(file_size(path) != -2) return 0;
        result = ({});
	bin_ls = get_dir(path + "/");
        for(i=0;i<sizeof(bin_ls);i++) {
            if(sscanf(bin_ls[i], "_%s.c", tmp) == 1)
               result += ({ tmp });
        }
	cmd_table[path] = result;
	return 1;
}

string *list_cmds(string path) {
	if (!cmd_table[path]) rehash(path);
	return cmd_table[path];
}
	
void qq() {
        save_object("/tmp/cmd_d");
}

string show_cmds(string arg) {
	string *tt;
	int i;
	int c;
	string *ttt;
	int j;

	tt=keys(cmd_table);
	for (i=0;i<sizeof(tt);i++) {
	write("COMMAND PATH: "+tt[i]);
	c=0;
		ttt=cmd_table[tt[i]];
		for (j=0;j<sizeof(ttt);j++)
		{
		if (!(c%4)) write("\n");
		c++;
		printf("%-19s",ttt[j]);
		}
	write("\n");
	}
	return "Ok.\n";
}
