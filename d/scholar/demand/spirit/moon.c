#include <mudlib.h>
#include <daemons.h>
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
void create()
{
	::create();
	set_level(15);
	set_name( "moon spirit", "�¹⾫��" );
	add( "id", ({ "spirit" }) );
	set_short( "�¹⾫��" );
	set_long(
		"һ��ȫ������͵Ļ�ɫ��â�ľ��顣\n"
	);
	set( "unit", "��" );
	set( "race", "elf" );
	set( "alignment",  800 );
	set( "max_hp", 5000 );
	set( "hit_points", 5000 );
	set_skill( "dodge", 50 );
}

int my_action(object me)
{
       string str1="�����һ���ƹ�����ֱ��������¹⾫��������˳�����ͻȻ�¹⾫��ȫ��ų�һƬ\n��ɫ��â�������㣬��о�һ����ů���¹⾫������ʧ�ڻƹ�֮�С�\n";
       string str2="�����"+me->query("c_name")+"����רע������һЩ���ͻȻһ���ƹ�������ֱ�������һֻ\n�¹⾫��������˳�����������¹⾫��ͻȻȫ��ų�һƬ��ɫ��â����"+me->query("c_name")+"֮�ᣬ\n����ʧ�ڻƹ�֮�С�\n";
       string str3="HIY";

        seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"�¹⾫�����˵��û����...������������ҽ��!\n");
        me->receive_healing(15+random(15));
        END->bye_bye(me,this_object(),15,str1,str2,str3);
	return 1;
}
