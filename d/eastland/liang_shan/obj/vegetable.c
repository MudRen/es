#include <mudlib.h>
#define FRESH_TIME 600

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	if (clonep(this_object())) {
		set_default_ob(__FILE__);
		return ;
	}
	set_name("vegetable","�����");
	add( "id" , ({ "vegetable" }) );
	set_short("�����");
	set_long(
		"һ�̳���ˣ��������ɰ���\n"
	);
   	set("unit","��");
   	set("weight", 10);
   	set("value",({ 130, "silver" }) );
	set("is_fresh",1);
}
int move(mixed ob)
{
	if ( ob && living(ob))
		call_out("not_fresh", FRESH_TIME, this_object() );
	return ::move(ob);
}

int eat_food(string arg)
{
		if( !arg || arg != "vegetable" ) return 0;
		write("��ܸ��˵ĳ���������ˣ��о������صĺô���\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+
			"�Թ���һ�̳���ˣ�Ȼ��������˼...\n" , this_player()
		);
		this_player()->receive_healing( 3+random(2) );
	    this_player()->set("spell_points",(int)this_player()->query("spell_points")+8);
	remove();
	return 1;
}

void not_fresh(object what)
{
	object owner;
	owner = environment(what);
	if ( !owner ) { 
//	what->set ("value", ({ 1, "silver" }));
//	what->set_short("���˵ĳ����");
//	what->set_long("������˱�ɻ�ɫ�����ܳ��ˡ�\n");
//	what->set("is_fresh",0);
	if( living(owner) )
	tell_object(owner,
		"�㷢�������˱���˻ƻƵģ��������ٳ��ˣ���ֻ�ð���������\n" 
		);
	}
	remove();
}
