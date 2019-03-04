#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit OBJECT;

void init()
{
	add_action( "smell_food", "smell" );
        add_action( "hook_hook", "tie");
}

void create()
{
	set_name("meat","������Ϻ����");
	add( "id" , ({ "meat","fish" }) );
   set_short("������Ϻ����");
   set_long( "������Щ��ԭ����Щʲ���Ѿ�û��֪���ˣ��������ǵ���Դ�������\n"
             "��һЩ��Ϻ֮�࣬��Ȼ���ǲ�ʱ�����̱ǵĳ�ζ���㻹���̲�ס�ذ�\n"
             "�����ڱ���ǰ��һ��(smell)��\n" );
   	set("unit","��");
   	set("weight", 5);
}

int smell_food(string arg)
{
object holder;	

       if( !(holder = environment(this_object())) || !living(holder) ) return 0;
       
       if( !arg || arg != "meat" ) return 0;
       write("\n�������ǳ���.....\n");
       (CONDITION_PREFIX + "weak")->apply_effect(holder,4,4);
	return 1;
}

 int hook_hook(string arg,object me)
 {
 int i,n;
 object ob;
 
 if (!arg || arg != "hook" )
 return notify_fail(
 "�봩��Щ������ʲ����?\n" );
 if (!(int)this_player()->query_temp("can_fish")==1 )  {
 write(
 "\n��ѳ�����Ϻ���⴩�ڵ�����...\n");
 this_player()->set_temp("can_fish",1);
 remove();
 return 1;
}
 else 
 write(
 "\n�������Ѿ������˵���.....\n");
 return 1;
}