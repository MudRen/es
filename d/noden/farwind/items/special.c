#include <mudlib.h>

inherit OBJECT;

void create(){

	set_name("special","�ص��󲹾�");
	add( "id" , ({ "special" }) );
	set_short( "�ص��󲹾�" );
	set_long( "�ص��󲹾ƣ��޵����ȣ�\n" );
   	set("unit","��");
   	set("weight", 15);
   	set("value",({100, "silver"}) );
	set("drink",10);
	call_out("drink_it", query("drink"), this_object() );
}

void drink_it(object who)
{
	object owner;
	owner = environment(who);
	if( owner && living(owner) ) 
	{
		tell_object(owner,
			"�����һ���ص��󲹾ơ��е��������һЩ��\n"
		);
		tell_room( environment(owner), 
			owner->query("c_name")+"����һ���ص��󲹾ƣ�������������һЩ!!\n",
			owner );

		owner->receive_healing(15);
	}
	remove();
}
	
