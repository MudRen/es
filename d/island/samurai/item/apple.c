#include <mudlib.h>

#define LIMIT_TIME 10
inherit OBJECT;

void create()
{
	set_name("apple","ƻ��");
	add( "id" , ({ "ƻ��" }) );
	set_short("apple" , "ƻ��");
	set_long(@AAA
	һ�����ʵ�ƻ��������ϰ�ļ������뵱���Ե���
AAA
	);
   	set("unit","��");
   	set("weight", 2);
   	set("value",({ 20, "silver" }) );
	call_out("eat_it", LIMIT_TIME, this_object());
}

void eat_it(object what)
{
	object owner;
	if ( owner = environment(what))
	if( living(owner) ) {
		tell_object(owner,
			"�����һ������ƻ����ҧ�����й��֭࣬�ֶ����㻹���ٳ�һ����\n"
		);
		tell_room( environment(owner), 
			owner->query("c_name")+"����һ��ƻ���������������������\n"
			, owner
		);
		owner->receive_healing( 5+random(5) );
	}
	remove();
}
