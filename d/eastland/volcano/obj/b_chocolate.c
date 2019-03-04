#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "blue_chocolate", "��ɫ�ɿ���" );
	add( "id", ({ "chocolate" }) );
	set_short(  "��ɫ�ɿ���" );
	set_long(
		"����һ����������������ɿ���������ԡ�����(taste)��\n"
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
   int fp,maxfp;

   if(!arg || arg!="chocolate")
   { write("��Ҫ��ʲ�᣿\n");
     return 1;
   };

   write("���������ɿ�������!��Ȼһֻ���Ȳ������档\n");
   write("�����֮�ᷢ�ֶ��ӹ��๾��ֱ�У��������ܲ��������ˡ�\n");
   maxfp=this_player()->query("max_fp");
   fp=this_player()->query("force_points");
   if (maxfp<(fp+10))
     this_player()->set("force_points",maxfp);
   else
     this_player()->set("force_points",fp+5);
   this_object()->remove();
   return 1;
}
