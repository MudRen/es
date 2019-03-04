
#include "../echobomber.h"

inherit ROOM;

void ruin_exit();

void create()
{
	::create();
    set_short("The dark cave","�ڰ��Ķ�Ѩ");
    set_long(@Long
Long
,@CLong
�ڰ��Ķ�Ѩ
CLong
    );
    set("exits",([
               "south":Deathland"/dwarf/village_08",
               "east":Deathland"/ruin1/path01",
             ]));

    set( "exit_suppress",({ "east",}));
    set( "pre_exit_func",([
         "east":"to_east",
         ]) );
    ::reset();
}
void init()
{
   if ( this_player()->query_temp("dwarf_echomaze") ) 
        this_player()->delete_temp("dwarf_echomaze") ; 
   ruin_exit();
}

void ruin_exit()
{
     object *items;
     int i;
     items=all_inventory(this_player());
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_action/invoke_bell"))
             write("����嵱�������Ȼ��������.���ߺ����и����ܵĳ���.\n");
     return ;
}

int to_east()
{
     object *items;
     int i;
     items=all_inventory(this_player());
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_action/invoke_bell")) 
             return 0; 
     write("�ⷽ��û�����Եĳ���.\n");        
     return 1;
}
