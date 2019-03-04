#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "gold_chocolate", "��ɫ�ɿ���" );
	add( "id", ({ "chocolate" }) );
	set_short( "gold_chocolate", "��ɫ�ɿ���" );
	set_long(
		"����һ��������Ƶ��ɿ���������ԡ�����(taste)��\n"
	);
	set( "type", "misc" );
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
  add_action("do_eat","taste");
}

int do_eat(string arg)
{
   if(!arg || arg!="chocolate")
   { write("��Ҫ��ʲ�᣿\n");
     return 1;
   };

   write("�����һ������Ƶ��ɿ������������Ļ���������Ҳ����������������\n");
   write("��е�˵����������������ٳ�һ�顣\n");
   this_player()->receive_healing(5);
   this_object()->remove();
   return 1;
}
