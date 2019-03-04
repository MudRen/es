#include <mudlib.h>
#include <conditions.h>

#define COND_NAME "herb_apply"

inherit OBJECT;
inherit DAEMON;
void create()
{
	set_name("box", "С����");
	set_short("С����");
	set_long(@C_LONG
����һֻ��Ө�󻬵İ������,����װ��һЩҩ�ࡣ�����ʹ����( use )����
( checkup )����
C_LONG
	);
	set( "weight", 1);
        set( "times",  10);
        set( "charge_times", 3);
        set( "duration", 30 );
        set( "heal_apply", 7);
	set( "value", ({ 1500, "silver" }));
}       
void init()
{
   add_action("do_use","use");
   add_action("do_checkup","checkup");
} 
int do_use(string arg)
{
   object me,boxes;
   string class1,my_name;
   int heal,duration,frequency,times;
   
   if ( !arg ) return 
      notify_fail("��Ҫ use ʲ�ᶫ����\n");
   if (!boxes=present(arg,this_player()))
      return notify_fail("��û������������\n");
   if (boxes->query("name")!="box")
      return notify_fail("Syntax <use box>\n");
   times=boxes->query("times");
   me=this_player();
   if (times<1)
      return notify_fail("����,������������\n");
   if ( me->query_attacker() )
      return notify_fail("ս���в��ܷ�ҩ!!\n");
   if ( (int)me->query("hit_points")>=(int)me->query("max_hp") )
      return notify_fail("û���˷��ʲ�ᾢ??\n");
   if( (int)me->query_temp("bandaged") ) 
      return notify_fail("���Ѿ���������,���� remove bandage !!\n");
   my_name=me->query("c_name");
   class1=me->query("class");
   switch (class1) {
   case "healer":
   
   case "mage":
   case "scholar":
      times-=1;
      tell_object(me,
         "�������شӻ���ȡ��һֻС��,�򿪺���,��ָմЩҩ��Ϳ���˿ڴ�!\n");
      tell_room(environment(me),my_name+
         "�����شӻ���ȡ��һֻС��,�򿪺���,��ָմЩҩ��Ϳ���˿ڴ�!\n",me);
      break;
   default:
      times-=2;                       
      tell_object(me,
         "���ֿ������شӻ���ȡ��һֻС��,������ָմЩҩ��Ϳ���˿ڴ�!\n");
      tell_room(environment(me),my_name+
         "�ֿ������شӻ���ȡ��һֻС��,������ָմЩҩ��Ϳ���˿ڴ�!\n",me);
      break;
   }
   boxes->set("times",times);
   frequency = (int)boxes->query("heal_frequency");
   if( frequency < 1 ) frequency = 10;
   heal = (int)boxes->query("heal_apply");
   if( undefinedp(heal) ) heal = 1;
   duration = (int)query("duration");
   if( duration < 1 ) duration = 1;
   me->set("conditions/" + COND_NAME, ({ frequency,heal,duration}));
   return 1;
}
int do_checkup(string arg)
{
   int left_times;
   object boxes;
   if( !arg )
      return notify_fail("��Ҫ checkup ʲ�ᶫ��?\n");
   if( !(boxes=present( arg, this_player() )) )
      return notify_fail("��û������������\n");
   if (boxes->query("name")!="box")
      return notify_fail("Syntax <checkup box>\n");
   left_times=boxes->query("times");
   if (left_times<1)
      return notify_fail("��,��Ϳ������!ֻ�пտյ�һ�����ӡ�\n");   
   if (left_times>8)
      return notify_fail("��,С���ӻ�װ��������ҩ�࡫��\n");
   else if (left_times>3)
      return notify_fail("��,С���ӻ����²��ٵ�ҩ�࡫��\n");
   else return notify_fail("��,С�������ҩ���Ѿ��챻������������\n");   
}
