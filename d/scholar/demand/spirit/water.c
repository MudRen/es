#include <mudlib.h>
#include <daemons.h>
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
void create()
{
	::create();
	set_level(10);
	set_name( "water spirit", "ˮ����" );
	add( "id", ({ "spirit" }) );
	set_short( "ˮ����" );
	set_long(
		"һ��ȫ����ɫ�ľ��飬ͷ�ϻ�����һС�����ơ�\n"
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
        string str1="��������һ������Ʈ����ˮ�������Ʈ�˳�����ˮ�������ִ�������˿ڣ������һ��\n������ˮ��������������Ʈ���ˡ�\n";
        string str2="�����"+me->query("c_cap_name")+"����רע������һЩ���ͻȻ�����Ʈ��һ�����ƣ�һֻˮ����\nƮ�˳����������ˮ���������ȥ����"+me->query("c_cap_name")+"���˿�֮�ᣬ����������Ʈ���ˡ�\n";
        string str3="HIB";

 	seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"ˮ�������˵��û����...������������ҽ��!\n");
        me->receive_healing(15+random(5));
        END->bye_bye(me,this_object(),10,str1,str2,str3);
	return 1;
}
