#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "red_chocolate", "��ɫ�ɿ���" );
	add( "id", ({ "chocolate" }) );
	set_short(  "��ɫ�ɿ���" );
	set_long(
		"����һ������ţ�̵��ɿ���������ԡ�����(taste)��\n"
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
   int tp,maxtp;

   if(!arg || arg!="chocolate")
   { write("��Ҫ��ʲ�᣿\n");
     return 1;
   };

   write("�����һ�����ţ�̵��ɿ������������Ļ������ţ��Ҳ����������������\n");
   write("��е�˵����������������ٳ�һ�顣\n");
   maxtp=this_player()->query("max_tp");
   tp=this_player()->query("talk_points");
   if (maxtp<(tp+10))
     this_player()->set("talk_points",maxtp);
   else
     this_player()->set("talk_points",tp+10);
   this_object()->remove();
   return 1;
}
