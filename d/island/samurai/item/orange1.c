#include <mudlib.h>

#define LIMIT_TIME 10
inherit OBJECT;

void create()
{
	set_name("orange","����");
	add( "id" , ({ "orange" }) );
	set_short("orange" , "����");
	set_long(@AAA
	һ�����ʵ�����������ϰ�ļ������뵱���Ե���
AAA
	);
   	set("unit","��");
   	set("weight", 2);
   	set("value",({ 15, "silver" }) );
	call_out("eat_it", LIMIT_TIME, this_object());
}

void eat_it(object what)
{
	object owner;
		tell_object(owner, can_read_chinese()?
			"�����һ�������������о������㡣\n":
			"You drink a cup of Special Wine....\n"
		);
		tell_room( environment(this_player()), ({
			owner->query("cap_name")+" drink a cup of Special Wine....\n",
			owner->query("c_name")+"����һ����������������"
			"�����������\n"}), this_player()
		);
		owner->receive_healing( 5+random(5) );
	remove();
}
