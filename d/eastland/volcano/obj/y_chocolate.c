#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "yellow_chocolate", "��ɫ�ɿ���" );
	add( "id", ({ "chocolate" }) );
	set_short( "��ɫ�ɿ���" );
	set_long(
		"����һ�������ɿ���������ԡ�����(taste)��\n"
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
   int align;

   if(!arg || arg!="chocolate")
   { write("��Ҫ��ʲ�᣿\n");
     return 1;
   };

   write("���������ɿ�����������︡��һ��Ӱ��\n");
   this_player()->set_temp("block_command",1);
   write("\n\n\n\n\n\n\n");
   call_out("idle_time1",2,this_player());
   call_out("idle_time2",9,this_player());
   call_out("end",11,this_object());

   align=this_player()->query("alignment");
   this_player()->set("alignment",align+10);
   return 1;
}

int idle_time1(object who)
{
    tell_object(who,"������������ݵ�����������һ����ֻ�����е�ES��������ڵ�������Ĥ��  \n");
    tell_object(who,"�㲻��������Ц��������������������ES֮����������������������������  \n");
    tell_object(who,"\n\n\n\n\n\n\n");
    return 1;
}

int idle_time2(object who)
{
    tell_object(who,"ͻȻ�����ǰһƬ�ڰ���������һ�£��㷢�������Χ�����ˣ����Ҳ�֪����\n");
    tell_object(who,"�ֶ�����ָָ������ʲ�ᣬ���ϻ��������ӵ�Ц�ݣ�\n");
    tell_object(who,"�����������ʱ��ͻȻ�����Լ���������ˮ�����ϻ������ģ�������\n");
    tell_object(who,"��޲��õ����и��������������ȥ��\n");
    who->set_temp("block_command",0);
    return 1;
}

void end(object ob1)
{
  ob1->remove();
  return;
}
