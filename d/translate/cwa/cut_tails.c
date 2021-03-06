
#include "/u/m/maverick/maverick.h"
inherit OBJECT;

int block_cut = 0;

void create()  {
        seteuid(getuid());
	set_name("cut-tail knife", "割狼尾巴小刀");
	add("id", ({"knife", "knife"}) );
	set_short("cut-tail knife", "割狼尾巴小刀");
	set_long(
"This is a very sharp knife,made for cutting color-wolves tail.\n",
"这是一把十分锋利的小刀,专门用来割(cut)色狼尾巴的.同时这也是屠狼\n"
"俱乐部的信物。欲查看如何割狼尾巴请用(help_cut)指令。\n"
	);
	set("no_sell", 1);
	set("prevent_drop",1);
	set("weight", 1);
}

int query_auto_load(){	return(1);  }

void init()
{
     add_action("help_cut","help_cut");
     add_action("cut_tail","cut");
}     

void help_cut()
{
     write(can_read_chinese()?
       "指令用法: cut <player name> \n":
       "usage: cut <player name> \n");
     return 1;
}

int cut_tail(string str)
{
     object dest,obj,*objs;
     int i;
    
	if(block_cut) return notify_fail(can_read_chinese()?
"你必须再等一下才可再割别人的尾巴!\n" :
"You have to wait a moment more to perform next cut.\n");

	block_cut = 1;
	call_out("cuttable", 15);
 
     if(!dest=present(str,environment(this_player()))){
       tell_object(this_player(),(can_read_chinese()?
       "这个人并不在这里。\n":
       "This guy is not here\n"));
       return 1;}
     if((int)dest->query("CWA") !=1){
       tell_object(this_player(),((can_read_chinese()?
       "这个人并不是色狼公会的会员。\n":
       "This guy is not a member of CWA.\n")));
       return 1;}

	if((int)dest->query_temp("tail_cut"))  {
		write(can_read_chinese()?
"这个人的尾巴早被割了!\n" :
"This wolf's tail has been cut already!\n");
		return 1;
	}

	if(random(100)<80) {
		write(can_read_chinese()?
"你挥动割尾小刀想把"+dest->query("c_cap_name")+"的尾巴割下但是失败了\n" :
"You try to cut "+dest->query("cap_name")+"'s tail down but failed");

		tell_object(dest,can_read_chinese(dest)?
this_player()->query("c_cap_name")+"试著把你的尾巴割下但是失败了.\n" :
this_player()->query("cap_name")+ "tried to cut down your tail but failed.\n");
		
		return 1;
	}

     objs=all_inventory(dest);
     for (i=0;i<sizeof(objs);i++){
       if((string)objs[i]->query("name") == "wolf tail")
         {
           objs[i]->cut();
           tell_object(dest,(can_read_chinese(dest)?
             this_player()->query("c_cap_name")+"把你的狼尾巴割下来了。\n":
             this_player()->query("cap_name")+" cut down your wolf tail.\n"));
           tell_object(this_player(),(can_read_chinese()?
             "你把"+dest->query("c_cap_name")+"的狼尾巴割了下来。\n":
             "You cut down"+dest->query("cap_name")+"'s wolf tail.\n"));
           tell_room(environment(this_player()),(can_read_chinese()?
             this_player()->query("c_cap_name")+"把"+dest->query("c_cap_name")+"的狼尾巴割了下来。\n":
             this_player()->query("cap_name")+" cuts down "+dest->query("cap_name")+"'s wolf tail.\n")
             ,({this_player(),dest}));
           obj=new(MITEMS"tails");
           obj->move(this_player());
           return 1;
           break;
         }
    }
	return 1;
}           
          

void cuttable() { 
	object *owner;

	block_cut = 0;
	owner = environment(this_object()); 
	tell_object(owner, can_read_chinese(owner)?
"你又可集中精神去屠狼了.\n" : "You can cut again.\n");
}



 
