//#pragma save_binary
#include <mudlib.h>

inherit DAEMON;
string path,*all_files,output ;

void check_weapons(object player) 
{
	int i;
	object ob;
	string msg ;

	
			write_file(output,
			sprintf("%-16s - %-16s - %|4s - %|4s - %|4s - %|4s - %s\n",
					"����","��������","WC","MaxD","MinD","����","�ڶ�"));
	write_file(output,
	"====================================================================\n");
	for ( i = sizeof(all_files)-1 ; i >=0 ; i -- ) {
	if ( catch(ob = new(path+all_files[i]))) continue ;
		if ( ob->query("weapon_class") ) {
			write_file(output,
			sprintf("%-16s - %-16s - %|4d - %|4d - %|4d - %|4d - %s\n",
						all_files[i],ob->query("c_name"),
						ob->query("weapon_class"),
						ob->query("max_damage"),ob->query("min_damage"),
						ob->query("weight"),
						( ob->query("second") ? "Y" : 
							( ob->query("no_second") ? "N" : "1" ) )
						));
			
		}
	ob->remove();
	
	}
	return;
}
void check_armors(object player) 
{
	int i;
	object ob;
	string msg ;

			write_file(output,
			sprintf("%-16s - %-12s - %|12s - %|8s - %|4s - %|4s - %s\n",
					"����","��������","����","����","AC","DB","Weight"));
	write_file(output,
"==========================================================================\n");
	for ( i = sizeof(all_files)-1 ; i >=0 ; i -- ) {
	if ( catch(ob = new(path+all_files[i]))) continue ;
		if ( ob->query("material") ) {
			write_file(output,
			sprintf("%-16s - %-12s - %|12s - %|8s - %|4d - %|4d - %d\n",
						all_files[i],ob->query("c_name"),
						ob->query("material"),ob->query("type"),
						ob->query("armor_class"),ob->query("defense_bonus"),
						ob->query("weight"),
						));
			
		}
	ob->remove();
	
	}
	return;
}
void check_mobs(object player) 
{
	int i;
	object ob;
	string msg ;

			write_file(output,
			sprintf("%-16s - %-12s - %|4s - %|4s - %|7s - %s\n",
					"����","��������","LV","HP","AC/DB","WC/MaxD~MinD"));
	write_file(output,
"==========================================================================\n");
	for ( i = sizeof(all_files)-1 ; i >=0 ; i -- ) {
	if ( catch(ob = new(path+all_files[i]))) continue ;
		if ( ob->query("npc") ) {
			ob->calc_weapon_class();
			ob->calc_armor_class();
			write_file(output,
			sprintf("%-16s - %-12s - %|4d - %|4d - %|4d/%3d - %3d/%3d~%3d\n",
						all_files[i],ob->query("c_name"),
						ob->query_level(),ob->query("hit_points"),
						ob->query("armor_class"),ob->query("defense_bonus"),
						ob->query("weapon_class1"),ob->query("max_damage1"),
						ob->query("min_damage1")
						));
			
		}
	ob->remove();
	
	}
	return;
}

int help() ;
int check_file(string file)
{
	string tmp,tmp2;
	if ( sscanf(file,"%s.c%s",tmp,tmp2) == 2) 
		if ( tmp2 == "" ) return 1;
	return 0;
}

int cmd_check_objects(string arg)
{
	object *ob;
	int i,j,memory;
	string type,tmp;

	if ( !arg || arg == "") return help();
	output = 0;
	if (sscanf(arg,"%s %s",type,output)!= 2) 
		type = arg ;
	path = this_player()->query("cwd")+"/";
	if ( !sscanf(path,"/d/%s",tmp) )
	 	return notify_fail("Use only under dirs in /d/\n");
//	write(type+output+path);
	all_files = get_dir(this_player()->query("cwd")+"/");
	all_files = filter_array(all_files,"check_file",this_object());
//	for (i = sizeof(all_files)-1 ; i >= 0 ; i -- )
//		write(all_files[i]+"\n");
//	return 1;		
	switch ( type ) {
		case "weapons" :
						if ( !output ) output = "weapons.rpt" ;	
						output = user_path(this_player()->query("name"))+output;
						if ( file_size(output) ) rm(output);
							check_weapons(this_player());
						break;
		case "armors" :
						if ( !output ) output = "armors.rpt" ;	
						output = user_path(this_player()->query("name"))+output;
						if ( file_size(output) ) rm(output);
							check_armors(this_player());
						break;
//		case "items" :
//						if ( !output ) output = "items.rpt" ;	
//						break;
		case "mobs" :
						if ( !output ) output = "mobs.rpt" ;
						output = user_path(this_player()->query("name"))+output;
						if ( file_size(output) ) rm(output);
							check_mobs(this_player());
						break;
		default : return help();
	}
	return 1;
}

int help()
{
write(
"�÷� : check_objects <������Ŀ> <�������>\n\n"
"����һ������һ����Ŀ¼���������Ŀǰ״���Ĺ��ߡ�\n"
"���������Ŀǰ���ڵ���Ŀ¼�µ����е������������\n"
"�������ĸ�Ŀ¼�½� weapons.rpt (��) �ĵ�����\n\n"
"	������Ŀ : weapons ,mobs ,armors.\n");
	return 1;
}
