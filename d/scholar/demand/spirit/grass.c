#include <mudlib.h>
#include <daemons.h>
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
string str1="�����Զ��һ����ɫ�ľ���վ��һ�����Ϸ��˹������ݾ��齫һƬҩ�ݷ�������˿��ϣ�\n�����һ���ʹ���ݾ���������������ˡ�\n";
string str3="HIG";

void create()
{
	::create();
	set_level(4);
	set_name( "grass spirit", "�ݾ���" );
	add( "id", ({ "spirit" }) );
	set_short( "�ݾ���" );
	set_long(
		"һ�������޳���������ȫ��������ɫ�ľ��顣\n"
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
        string str1="�����Զ��һ����ɫ�ľ���վ��һ�����Ϸ��˹������ݾ��齫һƬҩ�ݷ�������˿��ϣ�\n�����һ���ʹ���ݾ���������������ˡ�\n";
        string str3="HIG";
        string str2="�����"+me->query("c_name")+"����רע������һЩ��������Զ��һ����ɫ�ľ���վ��һ����\n�Ϸ��˹������ݾ��齫һƬҩ�ݷ���"+me->query("c_name")+"���˿�֮�ᣬ������������ˡ�\n";

 	seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"�ݾ������˵��û����...������������ҽ��!\n");
        me->receive_healing(6+random(2));
        END->bye_bye(me,this_object(),4,str1,str2,str3);
	return 1;
}
