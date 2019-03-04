
#include "/u/m/maverick/maverick.h"
inherit OBJECT;

int block_cut = 0;

void create()  {
        seteuid(getuid());
	set_name("cut-tail knife", "����β��С��");
	add("id", ({"knife", "knife"}) );
	set_short("cut-tail knife", "����β��С��");
	set_long(
"This is a very sharp knife,made for cutting color-wolves tail.\n",
"����һ��ʮ�ַ�����С��,ר��������(cut)ɫ��β�͵�.ͬʱ��Ҳ������\n"
"���ֲ���������鿴��θ���β������(help_cut)ָ�\n"
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
       "ָ���÷�: cut <player name> \n":
       "usage: cut <player name> \n");
     return 1;
}

int cut_tail(string str)
{
     object dest,obj,*objs;
     int i;
    
	if(block_cut) return notify_fail(can_read_chinese()?
"������ٵ�һ�²ſ��ٸ���˵�β��!\n" :
"You have to wait a moment more to perform next cut.\n");

	block_cut = 1;
	call_out("cuttable", 15);
 
     if(!dest=present(str,environment(this_player()))){
       tell_object(this_player(),(can_read_chinese()?
       "����˲��������\n":
       "This guy is not here\n"));
       return 1;}
     if((int)dest->query("CWA") !=1){
       tell_object(this_player(),((can_read_chinese()?
       "����˲�����ɫ�ǹ���Ļ�Ա��\n":
       "This guy is not a member of CWA.\n")));
       return 1;}

	if((int)dest->query_temp("tail_cut"))  {
		write(can_read_chinese()?
"����˵�β���类����!\n" :
"This wolf's tail has been cut already!\n");
		return 1;
	}

	if(random(100)<80) {
		write(can_read_chinese()?
"��Ӷ���βС�����"+dest->query("c_cap_name")+"��β�͸��µ���ʧ����\n" :
"You try to cut "+dest->query("cap_name")+"'s tail down but failed");

		tell_object(dest,can_read_chinese(dest)?
this_player()->query("c_cap_name")+"���������β�͸��µ���ʧ����.\n" :
this_player()->query("cap_name")+ "tried to cut down your tail but failed.\n");
		
		return 1;
	}

     objs=all_inventory(dest);
     for (i=0;i<sizeof(objs);i++){
       if((string)objs[i]->query("name") == "wolf tail")
         {
           objs[i]->cut();
           tell_object(dest,(can_read_chinese(dest)?
             this_player()->query("c_cap_name")+"�������β�͸������ˡ�\n":
             this_player()->query("cap_name")+" cut down your wolf tail.\n"));
           tell_object(this_player(),(can_read_chinese()?
             "���"+dest->query("c_cap_name")+"����β�͸���������\n":
             "You cut down"+dest->query("cap_name")+"'s wolf tail.\n"));
           tell_room(environment(this_player()),(can_read_chinese()?
             this_player()->query("c_cap_name")+"��"+dest->query("c_cap_name")+"����β�͸���������\n":
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
"���ֿɼ��о���ȥ������.\n" : "You can cut again.\n");
}



 
