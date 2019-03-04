
#include "../echobomber.h"

inherit ROOM;

void bottle_find();
int bottle_num;

void create()
{
	::create();
  set_short("swamp of GreyIsland","�Ұ�֮��������");
  set_long(@Long
Long
,@CLong
һ�������������, �������ƺ��������µ��������������ȥ, �����С�Ľ���
���ÿһ��. Խ�����������ˮ��Խ��, �����������Ҳ��������ȫ����ס��. ��
�������Ѿ��޷�����ؿ������ܵ�״����, ֻ֪����Ľ��Ѿ����������������.

CLong
);
set("search_desc",([
    "here":"@@search_here",
    ]) );
set("exits",([
     "northeast":Deathland"/island/swamp04",
     ]) );
set("exit_invisble",1);     
::reset();
}

void init()
{
     bottle_find();

}

void bottle_find()
{
     object *items;
     int i;
     
     items=all_inventory(this_player());
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/crystal_card"))
             write("���ˮ����Ƭ�������Ȼһ����, �ƺ���������һ�����ص���Ʒ.\n");

     return;
}

string search_here()
{
     object *items;
     int i;
     
     items=all_inventory(this_player());
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/crystal_card")){
             items[i]->set("quest_item/black_bottle",1); 
             return "���������㷢����һ����ɫ��ƿ��\n";
             } 
     return "�ƺ���������Щʲ��? �����������õ���Ʒ��? \n";        
}
