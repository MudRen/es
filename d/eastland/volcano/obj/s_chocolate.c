#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "silver_chocolate", "��ɫ�ɿ���" );
	add( "id", ({ "chocolate" }) );
	set_short( "��ɫ�ɿ���" );
	set_long(
		"����һ��������ɽ�����ɿ���������ԡ�����(taste)��\n"
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
   int sp,spmax;
   if(!arg || arg!="chocolate")
   { write("��Ҫ��ʲ�᣿\n");
     return 1;
   };

   write("�����һ�������ɽ�����ɿ�����ŨŨ���ɿ����������ɽ�����ص�ζ����\n");
   write("��е�˵����������������ٳ�һ�顣\n");
   sp=this_player()->query("spell_points");
   spmax=this_player()->query("max_sp");
   if (spmax<(sp+10))
     this_player()->set("spell_points",spmax);
   else
     this_player()->set("spell_points",sp+5);
   this_object()->remove();
   return 1;
}
