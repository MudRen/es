#include <mudlib.h>
#define FRESH_TIME 400

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name("beef","�б�ţ��");
	add( "id" , ({ "beef" }) );
	set_short("beef" , "�б�ţ��");
	set_long(".." , 
		"��Ҳ�����������ֺòˣ��ð�����Сţ������������ϱ���\n"
		"������㻬�ۣ����˻�ζ���\n"
	);
   	set("unit","��");
   	set("weight", 20);
   	set("value",({ 260, "silver" }) );
//	call_out("not_fresh", FRESH_TIME, this_object() );
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
		if( !arg || arg != "beef" ) return 0;
		write( "�����سԵ����̴б�ţ�⣬������������Ķ���...:)\n" );
                tell_room( environment(this_player()),
                "�㿴��"+this_player()->query("c_name")+"�Ե�һ�̴б�ţ��"
                "Ȼ���൱��������Ķ���...\n" , this_player()
        );		
		this_player()->receive_healing( 10+random(10) );
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
		"��Ĵб�ţ��̫�ò��ԣ������Ѿ�����!!��˳�ְ���������\n"
		);
	}
	remove();
}

