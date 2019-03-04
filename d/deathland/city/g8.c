
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The graveyard of Hero","Ӣ��Ĺ��");
  set_long(@Long
�����ǰ���Ӣ�۵�Ĺ��,Ĺ���������һλ����ΰ��̽�վ������.��һ��Ĺ���ı���
��д��: ��·���ȷ�.
Long
);
set("search_desc",([
    "here":"@@search_here",
    ]) );
set("exits",([
            "east":Deathland"/city/g7",
            "north":Deathland"/city/g9",
             ]));
reset();

}

string search_here()
{
    object *items;
    int i;
    
    items=all_inventory(this_player());
    for(i=0;i<sizeof(items);i++)
      if ( (string)items[i]->query("name") == "Black Box of Molader" )
        {
          if ( items[i]->query("quest_item/explorer_bell") )
             return "���Ѿ��ҵ�������嵱��,�����������ð�!\n";
          items[i]->set("quest_item/explorer_bell",1);
          return "�㷢����һ����ֵ��嵱����Ĺ����,�ƺ������̽�ռҵ�����.\n" 
                 "�����˳������һ������.\n";
        }  
    return "����������, ������һ����������Ĺ����, �㲻֪��������������\n"
           "��, ���ԾͲ�ȥ�������, Ҳ\��\ֻ��װ��Ʒ��.\n";   
}

