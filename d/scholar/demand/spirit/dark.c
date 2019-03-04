#include <mudlib.h>
#include <daemons.h>
#define AC_EFFECT 25
#define DB_EFFECT 15
#define WC_EFFECT 15
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;

string str1="�ڰ�����˵���ҵ����ѡ��ұ���Ҫ���ˣ�������Ҫ�Ұ�æ���ٽ��ҡ�\n";
string str2="������ڰ���������������ɢ���ˡ�\n";
string str3="HIW";

void create()
{
	::create();
	set_level(15);
	set_name( "dark spirit", "�ڰ�����" );
	add( "id", ({ "spirit" }) );
	set_short( "�ڰ�����" );
	set_long(
		"һ�ź�ɫ�ľ��飬��ֻ�ܿ��������������������۾���\n"
	);
	set( "unit", "��" );
	set( "race", "elf" );
	set( "alignment",  800 );
	set( "max_hp", 5000 );
	set( "hit_points", 5000 );
        set( "invisible",1);
	set_skill( "dodge", 50 );
}

void add_effect(object me)
{
  int i ;

  me->set_temp("extra_ac/body",AC_EFFECT+(int)me->query_temp("extra_ac/body"));
  me->set_temp("extra_db/body",DB_EFFECT+(int)me->query_temp("extra_db/body"));
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")+WC_EFFECT);
  return;
}

void remove_effect(object me)
{
  int i;

  me->set_temp("extra_ac/body",(int)me->query_temp("extra_ac/body")-AC_EFFECT);
  me->set_temp("extra_db/body",(int)me->query_temp("extra_db/body")-DB_EFFECT);
  me->calc_armor_class();
  me->set_temp("extra_wc",(int)me->query_temp("extra_wc")-WC_EFFECT);
  return ;
}

void check_battle1(object me)
{
  if (!this_object())
    return;
  if (!me->query_attacker()) {
    remove_effect(me);
    END->bye_bye(me,this_object(),15,str1,str2,str3);
    return;
  }
  else
    call_out("check_battle1",1,me);
  return;
}

void check_battle2(object me)
{
  if (!this_object())
    return;
  if (random(me->query_skill("polemic"))<=15) {
    remove_effect(me);
    END->bye_bye(me,this_object(),15,str1,str2,str3);
    return;
  }
  else
    call_out("check_battle2",4,me);
  return;
}

int my_action(object me)
{
 	seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"�ڰ��������˵��û����...����������������ս��Ǳ��!\n");
    tell_object(me,set_color("һ�ź���Ʈ�˹���������������ڰ��������˵:�����ð��ڶ������������ս������ ! ��֪������ʩ��ʲ�ᷨ������ͻȻ�����Լ��ľ���������\n","HIW",me));
    tell_room(environment(me),set_color("�����"+me->query("c_name")+"����רע������һЩ���һ�ź���Ʈ�˹���������ԼԼ���Կ���һֻ�ڰ���������"+me->query("c_name")+"��֪��ʩʲ�ᷨ����\n","HIW",me),me);
        add_effect(me);
        call_out("check_battle1",1,me);
        call_out("check_battle2",15+random(15),me);
	return 1;
}

