#include "../takeda.h"
inherit OBJECT;

void create()
{
     set_name("crumb","���м");
     set_short("crumb","���м");
     set_long(
      "һС���ʣ�����м�����˳��Ǿ��ԳԲ����ġ�\n"
      );
     set( "unit", "��");
     set("weight",5);
}
void init()
{
	add_action( "eat_food", "eat" );
}
int eat_food(string arg)
{
	if( !arg || arg != "crumb" ) return 0;
        write(
                "�����һС�����м���¶��ӣ��ͺ����ڴ��ж���һ��ʯͷ��\n" );
        tell_room( environment(this_player()),"�㿴��"+
                     this_player()->query("c_name")+"���̻����سԵ���һ�����м��"
                "���ͬ������Ȼ����...\n", this_player()
		);
           this_player()->receive_healing( 1+random(1) );
	remove();
	return 1;
}

