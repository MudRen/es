#include <mudlib.h>

#define LIMIT_TIME 10
inherit OBJECT;

void create()
{
	set_name("lemon","����");
	add( "id" , ({ "����" }) );
	set_short("����");
	set_long(@AAA
	һ�����ʵ����ʣ�����ϰ�ļ������뵱���Ե���
AAA
	);
   	set("unit","��");
   	set("weight", 2);
   	set("value",({ 50, "silver" }) );
	call_out("eat_it", LIMIT_TIME, this_object());
}

void eat_it(object what)
{
	object owner;
	if (owner = environment(what))
	if( living(owner) ) {
		tell_object(owner,
			"�����һ�����ʣ�ʵ���й��ᣬ������Ȼ���ú������\n");
		tell_room( environment(owner), 
			owner->query("c_name")+"����һ�����ʣ���������Ϊ̫���"
			"Ť���ˣ�������\n", owner
		);
		owner->receive_healing( 5+random(10) );
	}
	remove();
}
